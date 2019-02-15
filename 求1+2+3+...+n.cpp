
#include <iostream>

/*****************************/
/*　filename: 求1+2+3+...+n.cpp */
/*　abstract: 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-15 16:28:30  */
/*****************************/
/*****************************/

using namespace std;

int a = 0;
int sum = 0;

class add{

  public:
  add(){
    sum += 1 + a;
  }
  static int getSum(){
    return sum;
  }
};
class Solution {
public:
    int Sum_Solution(int n) {
      a = n;
      sum = 0;
      add an[n];
      return an[0].getSum() >> 1;
    }
};

int main(){
  Solution s ;
  cout << s.Sum_Solution(100);
    return 0;
}
