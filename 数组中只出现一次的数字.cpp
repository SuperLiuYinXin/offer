
#include <iostream>
#include <vector>

/*****************************/
/*　filename: 数组中只出现一次的数字.cpp */
/*　abstract: 一个整型数组里除了两个数字之外，其他的数字都出现了偶数次
请写程序找出这两个只出现一次的数字
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-14 23:27:00  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
      if (data.size() <= 2)
        return;
      
      int resultExclusiveOr = 0;
      vector<int>::iterator ite = data.begin();
      while (ite != data.end()) {
        resultExclusiveOr ^= *ite;
        ++ite;
      }
      ite = data.begin();
      int index = findFirstBit1(resultExclusiveOr);

      *num1 = * num2 = 0;
      while (ite != data.end()) {
        if (isBit(*ite, index)) {
          *num1 ^= *ite;
        } else {
          *num2 ^= *ite;
        }
        ++ite;
      }
    }

    int findFirstBit1(int num){
      int n =  num & (-num);
      int i = 0;
      while ( (n & 1) == 0) {
        n >>= 1;
        ++i;
      }
      return i;
    }
    bool isBit(int num, int index) {
      return ((num >> index) & 1) == 1;
    }
};

int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);
    v.push_back(6);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);
    v.push_back(5);
    Solution s;
    int a, b;
    s.FindNumsAppearOnce(v, &a, &b);
    cout << "a=" << a << " b = " << b <<endl;

    return 0;
}
