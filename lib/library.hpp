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
                    desired_arr[i] = '\0';
                }
                else{
                    std::wstring temp;
                    std::string temp_desired_locale = std::string("")+=(char)i;
                    MultiByteToWideChar(
                            CodePage,
                            NULL,
                            temp_desired_locale.c_str(),
                            10,
                            temp.data(),
                            1
                    );
                    desired_arr[i] = temp[0];
                    if (temp[1] != '\0') {
                        errors[error_count++] = i;
                    }
                }
            }
        }
    };
} // my




