add_executable(constructor_test constructor.cpp)
add_executable(read_write read_write.cpp)

target_include_directories(constructor_test PRIVATE /opt/homebrew/include/doctest/)
target_include_directories(read_write PRIVATE /opt/homebrew/include/doctest/)
