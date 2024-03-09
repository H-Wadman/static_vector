#include <stdexcept>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../static_vector.hpp"
#include <doctest.h>

TEST_CASE("Subscript") { hw::static_vector<std::string, 5>{"a", "b", "c"}; }

TEST_CASE("For-each")
{
    hw::static_vector<int, 15> bruh;
    CHECK(bruh.size() == 0);

    bruh.push_back(5);
    bruh.push_back(7);
    int n_iterations{0};

    CHECK_EQ(bruh[0], 5);
    CHECK_EQ(bruh[1], 7);
    for (int i = 0; int e : bruh) {
        ++n_iterations;
        CHECK_EQ(e, bruh[i]);
        ++i;
    }
    CHECK_EQ(n_iterations, 2);
    CHECK_EQ(bruh.size(), 2);
}

TEST_CASE("at")
{
    hw::static_vector<int, 5> at_test{1, 2, 3};

    [[maybe_unused]] int _{};
    for (int i{0}; i < 3; ++i) { REQUIRE_NOTHROW(_ = at_test.at(i)); }

    for (int i{3}; i < at_test.size(); ++i) {
        REQUIRE_THROWS_AS((_ = at_test.at(i)), std::out_of_range);
    }
}
