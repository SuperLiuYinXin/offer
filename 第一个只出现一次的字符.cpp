
#include <iostream>

/*****************************/
/*　filename: 第一个只出现一次的字符.cpp */
/*　abstract: 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.  */
/*　author :  liuyinxin  */
/*　time:     2019-02-04 17:41:31  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int cMap[256];
        for (int i = 0; i < 256; ++i)
            cMap[i]= 0;
        for(int i = 0; i < str.size(); ++i) {
            ++cMap[str[i]];
        }
        for (int i = 0; i < str.size(); ++i) {
            cout << str[i] << " " << cMap[str[i]] << endl;
            if (cMap[str[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout <<  s.FirstNotRepeatingChar("googgle");
    return 0;
}
