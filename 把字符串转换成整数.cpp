
#include <iostream>

/*****************************/
/*　filename: 把字符串转换成整数.cpp */
/*　abstract: 把字符串转换成整数  */
/*　author :  liuyinxin  */
/*　time:     2019-02-17 15:30:32  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        long long num = 0;
        const char * cstr = str.c_str();
        if (cstr != nullptr && *cstr != '\0') {
            bool minus = false;
            while (*cstr == '+' || *cstr == ' ') {
                ++cstr;
            } 
            while ( *cstr == '-') {
                ++cstr;
                minus = true;
            }
            if (*cstr != '\0') {
                num = StrToIntCore(cstr, minus);
            }
        }
        return (int) num;
    }
    long long StrToIntCore(const char * str, bool minus) {
        long long num = 0;
        while (*str != '\0' && *str != ' ') {
            if (*str < '0' || *str > '9') {
                num = 0;
                break;
            }
            num = num * 10 + (minus ? -1 : 1 )*(*str - '0');
            // 注意 signed int
            if ( (!minus && num > 0x7fffffff) 
                || (minus && num < (signed int)0x80000000 )) {
                    cout << 0x80000000 << endl;
                num = 0;
                break;
            }
            ++str;
        }
        return num;
    }
};

int main(){
    Solution s;
    // cout << s.StrToInt("123") << endl;
    // cout << s.StrToInt("+123") << endl;
    // cout << s.StrToInt("-123") << endl;
    // cout << s.StrToInt("0") << endl;
    // cout << s.StrToInt(" +0 ") << endl;
    // cout << s.StrToInt("1a33") << endl;
    cout << s.StrToInt("2147483647") << endl;
    return 0;
}
