import os
import subprocess
import sys

SCRIPT_DIR = os.path.dirname(__file__)
BIN_DIR = sys.argv[1]

with open(f"{SCRIPT_DIR}/tests.txt") as file:
    fail_count: tuple[int, list[str]] = (0, [])
    for test in file:
        test = test.strip()

        cmd = [os.path.join(f"{BIN_DIR}", test)]
        process = subprocess.Popen(
            cmd, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL
        )
        exit_code = process.wait()
        if exit_code != 0:
            fail_count[1].append(test)
            fail_count = (fail_count[0] + 1, fail_count[1])

    print(f"{fail_count[0]} tests failed:")
    for fail in fail_count[1]:
        print(f"\t{fail}")

    if fail_count[0] == 0:
        exit(0)
    else:
        exit(1)
