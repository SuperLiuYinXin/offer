
#include <iostream>
#include <vector>

/*****************************/
/*　filename: 数字在排序数组中出现的次数.cpp */
/*　abstract: 统计一个数字在排序数组中出现的次数
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-14 22:11:19  */
/*****************************/
/*****************************/

using namespace std;


//　结论
// 记住查找的顺序，可以这样玩
// 找第一个和最后一个
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
      int num = 0, first, last;
      if (data.size() > 0) {
        last = findLast(data, k); 
        if (last >= 0){
          first = findFirst(data, k);
          if (first >= 0) {
            num = last - first + 1;
          }
        }
      }
      return num;
    }

    int findFirst(vector<int> & data, int k){
      int l = 0, r = data.size() - 1;
      while (l <= r) {
        int mid = l + (r - l) / 2;
        if (data[mid] == k) {
          if ( (mid > 0 && data[mid -1] != k)  || mid == 0)
            return mid;
          else 
            r = mid - 1;
        } else if (data[mid] < k) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      return -1;
    }
    int findLast(vector<int> & data, int k) {
      int l = 0, r = data.size() - 1;
      while (l <= r) {
        int mid = l + (r - l) / 2;
        if (data[mid] == k) {
          if ( (mid < data.size() - 1 && data[mid + 1] != k)  || mid == data.size() - 1)
            return mid;
          else 
            l = mid + 1;
        } else if (data[mid] < k) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      return -1;
    }
};

int main(){
  Solution s;
  vector<int> v;
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(2);
  v.push_back(2);
  v.push_back(3);
  cout << s.GetNumberOfK(v, 1) << endl;
  return 0;
}
