#include <iostream>
#include <string>
#include <iomanip>

int main ( int argc, char **argv )
{
    std::string str;
    if (argc >= 2)   { str = argv; }
    if (str.empty()) { str = "English & 中文"; }

    std::wstring wStr(str.begin(), str.end());
    std::wstring::iterator i = wStr.begin();
    for (; i != wStr.end(); ++i) {
        // actually numbers, you can add one
        std::cout << "\t" << std::hex << 1+(*i);
    }
    std::cout << std::endl;
}
//      $ ./WideString.exe
//              46      6f      68      6d      6a      74      69      21      27      21      ffd7    ffd1    ffcf    ffc5
//
//      $ ./WideString.exe "hay 嗨"
//              69      62      7a      21      ffe1    ffcc
