#include <Windows.h>
#include <string>
#include <locale.h>
#include <iostream>

namespace my{
    class filler{
    public:
        static void fill (wchar_t * desired_arr, INT CodePage, int* errors){
            short error_count = 0;
            for (int i = 0; i < 256; ++i){
                if (i == 0){
                    desired_arr[0] = '\0';
                }
                else{
                    wchar_t letter_answer = L'a';
                    std::wstring str_answer = L"a";
                    // std::string temp_desired_locale = std::string("")+=(char)i;
                    
                    char letter_to_convert = i;
                    std::string string_before_convert = "a";
                    string_before_convert[0] = (char)i;

                    char *str_to_convert = string_before_convert.data();
                    wchar_t* answer = str_answer.data();
                    auto err = MultiByteToWideChar(
                            CodePage,
                            NULL,
                            str_to_convert,
                            1,
                            answer,
                            1
                    );
                    desired_arr[i] = *answer;
                    if (err == 0) errors[i] = 1;
                }
            }
        }
    };
} // my




