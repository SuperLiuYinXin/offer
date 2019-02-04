
#include <iostream>
#include "utils.h"
#include <vector>

/*****************************/
/*　filename: 从叶结点开始的最小字符串.cpp */
/*　abstract: leetcode周竞赛题  */
/*　author :  liuyinxin  */
/*　time:     2019-02-03 10:54:44  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
private:
    vector<int> v;
    string fStr;

public:
    string smallestFromLeaf(TreeNode* root) {
        v.clear();
        fStr = "";
        if (root == NULL) {
            return "";
        }
        deepVisit(root);
        return fStr;
    }
    void deepVisit(TreeNode * node) {
        // cout << "visit" << node->val << endl;
        // 如果是leaf
        v.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            // cout << "node " << node->val << " is leaf" << endl;
            string curStr = this->to_string(v);
            if (fStr.size() == 0 || curStr < fStr) {
                fStr = curStr;
            }
            v.pop_back();
            return;
        }
        if (node->left) 
            deepVisit(node->left);
        if (node->right) 
            deepVisit(node->right);
        v.pop_back();
    }
    string to_string(vector<int> v) {
        string rtn;
        vector<int>::iterator ite = v.end() - 1;
        // cout << "end" << endl;
        for (;ite >= v.begin(); --ite) {
            rtn += *ite + 'a';
        }
        return rtn;
    }
};

int main(){
    Solution s;
    TreeNode * s1 = new TreeNode(25);
    // s1->left = new TreeNode(1);
    // s1->right = new TreeNode(3);
    // s1->left->left = new TreeNode(1);
    // s1->left->right = new TreeNode(3);
    // s1->right->left = new TreeNode(0);
    // s1->right->right = new TreeNode(2);
    // s1->left->right->right = new TreeNode(7);
    cout << s.smallestFromLeaf(s1) << endl;
    return 0;
}
