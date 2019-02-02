
#include <iostream>
#include <vector>
#include <algorithm>

/*****************************/
/*　filename: 把数组排成最小的数.cpp */
/*　abstract: 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-03 01:50:53  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
      sort(numbers.begin(), numbers.end(), compare);
      string r = "";
      for (vector<int>::iterator ite = numbers.begin(); ite < numbers.end(); ++ite) {
        r += to_string(*ite);
      }
      return r;
    }
    static bool compare(int a, int b) {
      string m = to_string(a), n = to_string(b);
      return m + n < n + m;
    }
};


int main(){

    Solution s;
    vector<int> v1;
    v1.push_back(0);
    // v1.push_back(32);
    // v1.push_back(321);

    string r = s.PrintMinNumber(v1);
    
        cout << r << " ";
    return 0;
}
