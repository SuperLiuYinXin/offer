
#include <iostream>
#include <cmath>

/*****************************/
/*　filename: 整数中1出现的次数.cpp */
/*　abstract: 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-01 20:24:59  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    // leecode 
    int countDigitOne(int N) {
      return NumberOf1Between1AndN_Solution(N);
    }
    int NumberOf1Between1AndN_Solution(int N)
    {
      if (N <= 0) {
        return 0;
      }
      int N1=N/10;
      int N2=N%10;
      int N3;
      int x=1;
      int y=10;
      int cnt=(N2==0?0:1);
      cout << "N1=" << N1 << " N2 " << N2 << " N3=" <<N3 << " cnt " << cnt << " x=" << x << " y=" << y << endl;
      while(N1>0)
      {
          N3=N1%10;
          if (N3==1) {
              cnt=N2+1+x+cnt;
          }
          else if (N3 != 0) {
              cnt=N3*x+cnt+y;
          }
          N2=y*N3+N2;
          N1=N1/10;
          x=10*x+y;
          y=y*10;
        cout << "N1=" << N1 << " N2 " << N2 << " N3=" <<N3 << " cnt " << cnt << " x=" << x << " y=" << y << endl;
      }
      return cnt;
    }
};

int main(){
    Solution s;
    cout << s.NumberOf1Between1AndN_Solution(1111);
    return 0;
}
