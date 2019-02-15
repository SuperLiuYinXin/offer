
#include <iostream>

/*****************************/
/*　filename: 数值的整数次方.cpp */
/*　abstract: 给定一个double类型的浮点数base和int类型的整数exponent。
            求base的exponent次方。  */
/*　author :  liuyinxin  */
/*　time:     2018-12-29 21:40:40  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0) {
            return 1;
        }
        int neg = exponent < 0 ? 1 : 0;
        double rtn = base;
        exponent = abs(exponent);
        while (--exponent) {

            rtn *= base;
        }

        return neg ? 1 / rtn : rtn;
    }
};

int main(){

    Solution s;
    cout << s.Power(2.2, -1);

    return 0;
}
