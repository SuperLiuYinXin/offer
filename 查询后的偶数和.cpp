
#include <iostream>
#include <vector>

/*****************************/
/*　filename: 查询后的偶数和.cpp */
/*　abstract: leetcode 给出一个整数数组 A 和一个查询数组 queries
leetcode 周竞赛题
对于第 i 次查询，有 val = queries[i][0], index = queries[i][1]，我们会把 val 加到 A[index] 上。然后，第 i 次查询的答案是 A 中偶数值的和。

（此处给定的 index = queries[i][1] 是从 0 开始的索引，每次查询都会永久修改数组 A。）

返回所有查询的答案。你的答案应当以数组 answer 给出，answer[i] 为第 i 次查询的答案。
  */
/*　author :  liuyinxin  */
/*　link :  https://leetcode-cn.com/contest/weekly-contest-122/problems/sum-of-even-numbers-after-queries/*/
/*　time:     2019-02-03 10:33:05  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
      vector<int> rtn;
      int evenSum = 0, index, val, add;
      for (int i = 0; i < A.size(); ++i) {
        if ((A[i] & 1) == 0) {
          evenSum += A[i];
        }
      }
      for (int i = 0; i < queries.size(); ++i) {
        index = queries[i][1];
        val = queries[i][0];
        add = 0;
        // 原来为奇
        if ( A[index] & 1) {
          // 奇数
          if (val & 1) {
            add = A[index] + val;
          }
        } else {
          // even + odd  - even
          if (val & 1) {
            add = -(A[index]);
          // even + odd
          } else {
            add = val;
          }
        }
        evenSum += add;
        A[index] += val;
        rtn.push_back(evenSum);
      }
      return rtn;
    }
};

int main(){
    Solution s;
    vector<int> v1;
    v1.push_back(0);

    return 0;
}
