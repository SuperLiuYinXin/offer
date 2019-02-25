
#include <iostream>

/*****************************/
/*　filename: 最长回文子串.cpp */
/*　abstract: leetcode  */
/*　author :  liuyinxin  */
/*　time:     2019-02-24 22:49:02  */
/*****************************/
/*****************************/

using namespace std;

// 中心展开法
// leetcode 5
class Solution {
public:
    string longestPalindrome (string s)
    {
        const int length=s.size();
        if (length <= 1)
            return s;
        int maxlength=1, start = 0;
        for(int i=0;i<length;i++)//长度为奇数
        {
            int j=i-1,k=i+1;
            while(j>=0&&k<length&&s[j]==s[k]) {

                if(k-j+1>maxlength) {
                    maxlength=k-j+1;
                    start=j;
                }
                --j,++k;
            }
            j = i, k = i + 1;
            while(j>=0 && k<length && s[j]==s[k]) {
                if(k-j+1 > maxlength) {
                    maxlength=k-j+1;
                    start=j;
                } 
                j--, ++k;
            }
        }
        return s.substr(start,maxlength);
    }
};

int main(){
    Solution s;
    cout << s.longestPalindrome("abad") <<  "=aba" << endl;
    cout << s.longestPalindrome("abba")  << "=" << "abba"<< endl;
    cout << s.longestPalindrome("babad")  << "=" << "bab"<< endl;
    cout << s.longestPalindrome("abb")  << "=" << "bb"<< endl;
    cout << s.longestPalindrome("bba")  << "=" << "bb"<< endl;
    // cout << s.longestPalindrome("aa")  << "=" << "aa"<< endl;
    cout << s.longestPalindrome("aaaa")  << "=" << "aaaa"<< endl;
    return 0;
}
