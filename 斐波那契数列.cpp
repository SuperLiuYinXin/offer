
#include <iostream>

/*****************************/
/*　filename: 斐波那契数列.cpp */
/*　abstract: 计算契数列第n项,0开始，第0项为0  */
/*　author :  liuyinxin   */
/*　time:     2018-12-27 23:56:34  */
/*****************************/
/*****************************/

class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0)
            return 0;
        else if (n <= 2)
            return 1;

        long a = 1,b = 1, tmp = 0;
        // 3
        for (int i = 3; i <= n; ++i) {

            tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }
};

using namespace std;

int main(){
    Solution s;
    cout <<  s.Fibonacci(5);
    return 0;
}
