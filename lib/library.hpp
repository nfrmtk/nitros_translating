#include <Windows.h>
#include <string>
#include <locale.h>
#include <iostream>

namespace my{
    void fill_alphabet (char16_t * desired_arr/*size=256*/, INT CodePage, int* errors/*size=256*/){
        desired_arr[0] = '\0';
        for (uint8_t i = 1; i != 0; ++i){
            wchar_t answer[4];
            char str_to_convert[2];
            str_to_convert[0] = i;
            str_to_convert[1] = '\0';
            auto err = MultiByteToWideChar(
                    CodePage,
                    NULL,
                    str_to_convert,
                    1,
                    answer,
                    1
            );
            desired_arr[i] = answer[0];
            if (err == 0) errors[i] = 1;
            if (answer[1] != 52428)
                errors[i] = 1;
        }
    }
    void translate_word_given_alphabet(const char16_t* alphabet, const char* word, char16_t* answer, INT CodePage) {
        
        
        for (size_t i = 0; word[i] != '\0'; ++i) {
            word[i] >= 0 ? answer[i] = alphabet[word[i]] :
                answer[i] = alphabet[256 + word[i]];
        }
    }
} // my




