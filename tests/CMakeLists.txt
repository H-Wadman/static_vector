add_executable(constructor constructor.cpp)
add_executable(read_write read_write.cpp)

target_include_directories(constructor PRIVATE /opt/homebrew/include/doctest/)
target_include_directories(read_write PRIVATE /opt/homebrew/include/doctest/)

add_test(NAME "UnitTest" COMMAND "python3" "${CMAKE_CURRENT_SOURCE_DIR}/run_tests.py" "${CMAKE_CURRENT_BINARY_DIR}")
