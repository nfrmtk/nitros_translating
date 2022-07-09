//
// Created by Lykov on 7/8/2022.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <library.hpp>
#include "doctest/doctest.hpp"

TEST_CASE("ru"){
    std::vector<wchar_t> vec(256, 'a');
    std::vector<int> vec_errs(256, 0);
    my::filler::fill(vec.data(), 1251, vec_errs.data());
    CHECK_EQ(vec[0xC4], L'Д');
    CHECK_EQ(vec[0xBB], L'»');
}