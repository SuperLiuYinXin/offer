
#include <iostream>
#include <vector>
#include <string>

/*****************************/
/*　filename: 数组中出现次数超过一半的数字.cpp */
/*　abstract: 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2
如果不存在则输出0
  */
/*　author :  liuyinxin  */
/*　time:     2019-01-31 22:23:45  */
/*****************************/
/*****************************/

using namespace std;


class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
      int mx = -1, r = 0;
      int bucket[10];
      for (int i = 0; i < 10; ++i) 
        bucket[i] = 0;
      for (int i = 0; i < numbers.size(); ++i) {
        ++bucket[numbers[i]];
      }

      for (int i = 0; i < 10; ++i)  {
        cout << bucket[i];
        if (mx < bucket[i]) {
          r = i;
          mx = bucket[i];
        }
      }
      cout << mx <<endl;
      return mx * 2 > numbers.size() ? r : 0;
    }
};

int main(){

    Solution s;

    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(4);
    cout << s.MoreThanHalfNum_Solution(v);
    
    return 0;
}
