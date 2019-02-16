#include <iostream>
#include <vector>

/*****************************/
/*　filename: 和为S的两个连续数字.cpp */
/*　abstract: 
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。  */
/*　author :  liuyinxin  */
/*　time:     2019-02-16 23:31:36  */
/*****************************/
/*****************************/
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int l = 0, r = array.size() - 1, add;
        vector<int> rtn;
        while (l <= r) {
            add = array[l] + array[r];
            if (add == sum) {
                rtn.push_back(array[l]);
                rtn.push_back(array[r]);
                return rtn;
            } else if (add < sum) {
                ++l;
            } else if (add > sum) {
                --r;
            }
        }
        return rtn;
    }
};

int main(){
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(7);
    v.push_back(11);
    v.push_back(15);
    vector<int> rtn = s.FindNumbersWithSum(v, 16);
    for (int i = 0; i < rtn.size(); ++i) {
        cout << rtn[i] << " ";
    }
    cout << endl;
    return 0;
}
