//
// Created by Lykov on 7/8/2022.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <library.hpp>
#include <doctest/doctest.hpp>

void check_errs_vector(const std::vector<int>& vec_errs){
    uint8_t errs_total = 0;
    std::for_each(vec_errs.begin(), vec_errs.end(), [&errs_total](const int& err) -> void {
        ++errs_total;
    });
    CHECK_EQ(errs_total, 0);
}



TEST_CASE("ru"){
    std::vector<char16_t> vec(256, 'a');
    std::vector<int> vec_errs(256, 0);
    my::fill_alphabet(vec.data(), 1251, vec_errs.data());
    CHECK_EQ(vec[0xC4], L'\u0414'); // Д
    CHECK_EQ(vec[0xB8], L'\u0451'); // ё
    CHECK_EQ(vec[0xBB], L'\u00bb'); // »
    check_errs_vector(vec_errs);
}


TEST_CASE("de/sp/fr"){
    std::vector<char16_t> vec(256, 'a');
    std::vector<int> vec_errs(256, 0);
    my::fill_alphabet(vec.data(), 1252, vec_errs.data());
    CHECK_EQ(vec[0xC0], u'\u00C0'); // À
    CHECK_EQ(vec[0xD8], u'\u00D8'); // Ø
    CHECK_EQ(vec[0xBC], u'\u00bc'); // ¼
    CHECK_EQ(vec[0xBF], u'\u00bf'); // ¿
    check_errs_vector(vec_errs);
}


TEST_CASE("russian locale -> char16_t"){
    constexpr int ru_code_page = 1251;
    const size_t mama_size = 5;
    char MAMA[mama_size];
    MAMA[0] = 204;
    MAMA[1] = 192;
    MAMA[2] = 204;
    MAMA[3] = 192;
    MAMA[4] = '\0';
    char16_t alphabet_to_fill[256];
    int errs[256];

    my::fill_alphabet(alphabet_to_fill, ru_code_page, errs);
    char16_t MAMA_wide[mama_size];
    my::translate_word_given_alphabet(alphabet_to_fill, MAMA, MAMA_wide/*only mutable link*/, ru_code_page);


    constexpr char16_t MAMA_by_hand[5] = u"\u041C\u0410\u041C\u0410";

    bool are_equal = true;
    for (size_t i = 0; i < mama_size - 1; ++i) {
        if (MAMA_wide[i] != MAMA_by_hand[i]) {
            are_equal = false;
            break;
        }
    }
    CHECK(are_equal);
    // CHECK_EQ(MAMA_wide, MAMA_by_hand);  doesn't work =(
}

