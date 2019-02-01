
#include <iostream>
#include <cmath>
#include <vector>

/*****************************/
/*　filename: 连续子数组的最大和.cpp */
/*　abstract: HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学
今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)  */
/*　author :  liuyinxin  */
/*　time:     2019-02-01 00:26:17  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max = -0x7fffffff, curMax = 0;
        for (int i = 0; i < array.size(); ++i) {

            curMax += array[i];
            if (curMax > max) {
                max = curMax;
            }
            if (curMax < 0) {
                curMax = 0;
            }
        }
        return max;
    }
};

int main(){
    Solution s;
    vector<int> v;
    // v.push_back(6);
    v.push_back(-3);
    v.push_back(-2);
    // v.push_back(1);
    // v.push_back(7);
    v.push_back(-15);
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(2);
    cout << s.FindGreatestSumOfSubArray(v) << endl;
    return 0;
}
