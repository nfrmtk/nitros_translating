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
    CHECK_EQ(vec[0xC4], L'\u0414'); // Д
    CHECK_EQ(vec[0xB8], L'\u0451'); // ё
    CHECK_EQ(vec[0xBB], L'\xbb'); // »
}


TEST_CASE("de/sp/fr"){
    std::vector<wchar_t> vec(256, 'a');
    std::vector<int> vec_errs(256, 0);
    my::filler::fill(vec.data(), 1252, vec_errs.data());
    CHECK_EQ(vec[0xC0], L'\xC0'); // À
    CHECK_EQ(vec[0xD8], L'\u00D8'); // Ø
    CHECK_EQ(vec[0xBC], L'\xbc'); // ¼
    CHECK_EQ(vec[0xBF], L'\xbf'); // ¿
}


