
#include <iostream>

/*****************************/
/*　filename: 不用加减乘除做加法.cpp */
/*　abstract: 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-15 16:52:41  */
/*****************************/
/*****************************/

using namespace std;


class Solution {
public:
    int Add(int num1, int num2)
    {
      while (num2 != 0) {
        int tmp = num1 ^ num2;
        num2 = (num1 & num2) << 1;
        num1 = tmp;
      }
      return num1;
    }
};

int main(){
  
    return 0;
}
