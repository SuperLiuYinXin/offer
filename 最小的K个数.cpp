
#include <iostream>
#include <queue>

/*****************************/
/*　filename: 最小的K个数.cpp */
/*　abstract: 输入n个整数，找出其中最小的K个数
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-01 00:04:07  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
      vector<int> result;
      if (input.size() <= 0 || k <= 0 || input.size() < k) {
        return result;
      }

      priority_queue<int> q;


      vector<int>::iterator ite = input.begin();
      for (;ite < input.end(); ++ite) {
        if (q.size() < k) {

          q.push(*ite);
        } else {
          if (q.top() > *ite) {
            q.pop();
            q.push(*ite);
          }
        }
      }


      while(!q.empty()) {
        result.push_back(q.top());
        q.pop();
      }
      for (int i = 0, j = result.size() - 1, tmp; i < j; i ++, --j) {
        tmp = result[i];
        result[i] = result[j];
        result[j] = tmp;
      }

      return result;
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
    v = s.GetLeastNumbers_Solution(v, 3);

    for (int i = 0; i < v.size(); ++i) {

        cout << v[i] << " ";
    }
    return 0;
}
