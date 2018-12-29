
#include <iostream>

/*****************************/
/*　filename: 矩阵覆盖.cpp */
/*　abstract: 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
        请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？ */
/*　author :  liuyinxin  */
/*　time:     2018-12-29 11:29:28  */
/*****************************/
/*****************************/

using namespace std;
// 简化成
// 斐波那契数列

class Solution {
public:
    int rectCover(int n) {

        if (n == 0)
            return 0;
        else if (n <= 1)
            return 1;

        long a = 1,b = 2, tmp = 0;
        // 3
        for (int i = 3; i <= n; ++i) {

            tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }
};   

int main(){
    return 0;
}
