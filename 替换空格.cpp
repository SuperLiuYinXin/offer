#include <iostream>
#include <stdio.h>

using namespace std;

/***
 * 
 * 
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为We Are Happy.
 * 则经过替换之后的字符串为We%20Are%20Happy。
 * 
 */
class Solution {
public:
    /**
     * 
     * 值得注意的地方是，length是整个字符串可以存放的大小，
     * 而非字符长度的大小
     *
     * 通过\0计算原来字符串的大小，然后得出加空格后的字符串长度大小
     * 通过双指针分别指向原来字符串的尾和现字符串的尾
     * 拷贝就ok啦
     *
     */
	void replaceSpace(char *str,int length) {
        int block = 0, newLen = 0, len = 0;

        for (int i = 0; str[i] != '\0'; ++i) {
            ++len;
            if (str[i] == ' ')
                block++;
        }
        newLen = len + block * 2;
        if (newLen> length) {
            return;
        }
        str[newLen] = '\0';

        for (int j = len - 1; j >= 0; --j) {
            if (str[j] == ' '){
                str[--newLen]= '0';
                str[--newLen] = '2';
                str[--newLen]= '%';
            }else {
                str[--newLen] = str[j];
            }
        }
	}
};

int main() {
    Solution s;
    char  chars[1000] = "We Are Happy.";
    s.replaceSpace(chars, 1000);
    cout << chars << endl;
    return 0;
}