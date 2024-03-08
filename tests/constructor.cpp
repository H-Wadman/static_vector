#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../static_vector.hpp"
#include <array>
#include <doctest.h>

TEST_CASE("Constructor")
{
    //Constructor with template arguments
    hw::static_vector<int, 5> test1{1, 2, 3, 4, 5}; //NOLINT

    //Test with template argument deduction
    hw::static_vector test_inferred_cap{1, 2, 3};
}

TEST_CASE("Size and capacity")
{
    hw::static_vector<int, 5> test1{1, 2, 3, 4, 5}; //NOLINT
    std::array<int, 5> elems{1, 2, 3, 4, 5};
    CHECK_EQ(test1.size(), test1.cap());
    CHECK_EQ(test1.size(), 5);
    CHECK_EQ(test1.size(), elems.size());
    for (std::size_t i = 0; i < elems.size(); ++i) {
        CHECK_EQ(elems.at(i), test1.at(i));
    }

    hw::static_vector test_inferred_cap{1, 2, 3};
    CHECK_EQ(test_inferred_cap.size(), 3);
    CHECK_EQ(test_inferred_cap.cap(), 3);
}

TEST_CASE("Element initialization")
{
    hw::static_vector<int, 5> test1{1, 2, 3, 4, 5}; //NOLINT
    hw::static_vector test2{1, 2, 3, 4, 5};         //NOLINT

    std::array<int, 5> elems{1, 2, 3, 4, 5};
    CHECK_EQ(test1.size(), elems.size());
    for (std::size_t i = 0; i < elems.size(); ++i) {
        CHECK_EQ(elems.at(i), test1.at(i));
        CHECK_EQ(test1.at(i), test2.at(i));
    }
}
