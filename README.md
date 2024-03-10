# Static vector
This is a very simple implementation of a static vector (a vector with a fixed compile-time capacity, but a variable size).

_Presumably this is obvious but this implementation is (currently, and almost certainly always will be) hilariously incomplete. The three most used implementations if you need one
are from boost (static_vector), EASTL (fixedVector) and Folly (small_vector). These all behave slightly differently, so choose the on that best suits your needs._

The goal of this "library" is just to get familiar with different features of CMake (including ctest and cpack [eventually]), multi directional builds, testing frameworks, etc. There's no real
reason for this to be public, other than for my own humiliation.
