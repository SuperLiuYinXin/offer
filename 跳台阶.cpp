
#include <iostream>

/*****************************/
/*　filename: 跳台阶.cpp */
/*　abstract: 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
    求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。*/
/*　author :  liuyinxin  */
/*　time:     2018-12-29 06:41:48  */
/*****************************/
/*****************************/



using namespace std;
/* 可以抽象城一个斐波那契数列　*/
class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 0)

            return 0;

        if (number <= 1) 

            return 1;
        else if (number <= 2)
            return 2;



        int a = 1, b = 2, tmp;
        for (int i = 3; i <= number; ++i) {

            tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }
};

int main(){

    Solution s;

    cout << s.jumpFloor(3) << endl;

    return 0;
}