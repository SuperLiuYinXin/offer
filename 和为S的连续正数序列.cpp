
#include <iostream>
#include <vector>
#include <cmath>

/*****************************/
/*　filename: 和为S的连续正数序列.cpp */
/*　abstract: 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!  */
/*　author :  liuyinxin  */
/*　time:     2019-02-16 14:32:20  */
/*****************************/
/*****************************/

using namespace std;

// 考虑溢出的问题
int rangeSum(int a, int b) {
    if (b < a) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    // 考虑溢出的问题
    return ((a + b) >> 1) * (b - a + 1) ;
}

// 感觉可是使用滑动窗口
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int l = 1, r = 1;
        // 四舍五入
        int max = sum / 2.0 + 0.5 , curSum;
        vector<vector<int>> rtn;
        if (sum <= 0) return rtn;
        // cout << "max=" << max << endl;
        while (l < max) {
            curSum = rangeSum(l, r);
            if (curSum > sum) {
                ++l;
            } else if (curSum < sum) {
                ++r;
            } else if (curSum == sum) {
                vector<int> v;
                generatorRange(v, l, r);
                rtn.push_back(v);
                ++r;
            }
        }
        return rtn;
    }
    // leetcode  https://leetcode-cn.com/problems/consecutive-numbers-sum/
    // 这里只需要返回次数，有一个问题是本算也算一次
    int consecutiveNumbersSum(int sum) {
        int l = 1, r = 1;
        // 四舍五入
        int max = sum / 2.0 + 0.5 , curSum, rtn = 0;
        if (sum <= 0) return rtn;
        // cout << "max=" << max << endl;
        while (l < max) {
            curSum = rangeSum(l, r);
            if (curSum > sum) {
                ++l;
            } else if (curSum < sum) {
                ++r;
            } else if (curSum == sum) {
                ++rtn;
                ++r;
            }
        }
        return rtn + 1;
    }
    void generatorRange(vector<int> & v, int a, int b) {
        for (int i = a; i <= b; ++i) {
            v.push_back(i);
        }
    }
};


int main(){
    Solution s;
    // vector<vector<int>> rtn = s.FindContinuousSequence(933320757);
    cout << s.consecutiveNumbersSum(933320757) << endl;
    // for (int i = 0; i < rtn.size(); ++i) {
    //     for (int j = 0; j < rtn[i].size(); ++j) {
    //         cout << rtn[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
