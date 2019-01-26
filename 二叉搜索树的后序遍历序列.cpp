
#include <iostream>
#include <vector>

/*****************************/
/*　filename: 二叉搜索树的后序遍历序列.cpp */
/*　abstract: 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果
如果是则输出Yes,否则输出No
假设输入的数组的任意两个数字都互不相同  */
/*　author :  liuyinxin  */
/*　time:     2019-01-26 14:24:23  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() <= 0) 

            return false;

        return check(sequence, 0, sequence.size() -2, sequence[sequence.size() -1]);
    }

    // [begin ...end]
    bool check (vector<int> & seq, int begin, int end, int root) {
        // cout << "begin " << begin << " end " << end << " root " << root <<  endl; 

        if (begin >= end) 
            return true;

        int lastMax = begin;
        // 找到做子树
        for (; lastMax <= end; ++lastMax) {
            if (seq[lastMax] > root) 
                break;

        }
        // 判断右子树
        for (int j = lastMax + 1; j<= end; ++j) {
            // cout << seq[j] << " ";
            if (seq[j] < root) {
                return false;
            }
        }
        // cout << endl;
        return check(seq, begin, lastMax - 2, seq[lastMax - 1]) 
                && check(seq, lastMax, end - 1, seq[end]);

    }
};

int main(){
    Solution s;
    vector<int> v;
    v.push_back(14);
    // v.push_back(9);
    v.push_back(5);
    v.push_back(16);
    v.push_back(17);
    v.push_back(15);
    v.push_back(19);
    v.push_back(18);
    cout << s.VerifySquenceOfBST(v) << endl;
    return 0;
}
