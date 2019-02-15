
#include <iostream>

/*****************************/
/*　filename: 丑数.cpp */
/*　abstract: 把只包含质因子2、3和5的数称作丑数（Ugly Number）
例如6、8都是丑数，但14不是，因为它包含质因子7
 习惯上我们把1当做是第一个丑数
求按从小到大的顺序的第N个丑数
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-03 02:22:28  */
/*****************************/
/*****************************/

using namespace std;



class Solution {
public:
    // leetcode 
    int nthUglyNumber(int n) {
      return GetUglyNumber_Solution(n);
    }
    int GetUglyNumber_Solution(int index) {
      if (index <= 0) {
        return 0;
      }

      int uglyNumbers[index];

      uglyNumbers[0] = 1;
      int nextUglyIndex = 1;

      int m2 =0 ,m3 = 0,m5 = 0, min;
      while (nextUglyIndex < index) {
        min = min_val(uglyNumbers[m2] * 2, uglyNumbers[m3] * 3, uglyNumbers[m5] * 5);
        uglyNumbers[nextUglyIndex] = min;
        while(uglyNumbers[m2] * 2 <= min) {
          ++m2;
        }
        while(uglyNumbers[m3] * 3 <= min) {
          ++m3;
        }
        while(uglyNumbers[m5] * 5 <= min) {
          ++m5;
        }
        ++nextUglyIndex;
      }
      return uglyNumbers[index - 1];
    }
    int min_val(int a, int b, int c) {
      return min(min(a,b), c);
    }
    bool isUgly(int num) {
      if (num <= 0) {
        return false;
      }
      while (num % 2 == 0) {
        num /= 2;
      }
      while (num % 3 == 0) {
        num /= 3;
      }
      while (num % 5 == 0) {
        num /= 5;
      }
      return num == 1;
    }
};

int main(){
  Solution s;
  cout << s.GetUglyNumber_Solution(1500) << endl;
    return 0;
}
