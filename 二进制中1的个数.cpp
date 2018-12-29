
#include <iostream>

/*****************************/
/*　filename: 二进制中1的个数.cpp */
/*　abstract: 计算二进制中1的个数,负数用补码表示  */
/*　author :  liuyinxin  */
/*　time:     2018-12-29 12:14:35  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
        int bit = 0;
        if (n < 0) {
            n = n & 0x7fffffff;
            bit++;
        }
        while (n != 0) {
            bit += n & 1;
            n = n >> 1;
        }
        return  bit;
     }
};

int main(){
    Solution s;
    cout << s.NumberOf1(-3);
    return 0;
}
