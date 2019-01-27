
#include <iostream>
#include <vector>
#include "utils.h"

/*****************************/
/*　filename: 二叉树中和为某一值的路径.cpp */
/*　abstract: 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径
(注意: 在返回值的list中，数组长度大的数组靠前)  */
/*　author :  liuyinxin  */
/*　time:     2019-01-26 15:19:37  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
private: 
    vector<vector<int> > result;
    vector<int> cur;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        result.clear();
        cur.clear();
        foreach(root, expectNumber);
        return result;
    }

    void foreach(TreeNode * root, int expectNumber) {
        // cout << expectNumber << endl;
        if (root == NULL) 
            return;

        if (root->val > expectNumber) 
            return;

        cur.push_back(root->val);

        if (root->val == expectNumber && root->left == NULL && root->right == NULL) {
            // cout << "push " << endl;
            result.push_back(cur);
            // result[result.size() - 1].push_back(root->val);
        } 

        expectNumber -= root->val;
        if (root->left != NULL) {
            foreach(root->left, expectNumber);
        }
        if (root->right != NULL) {
            foreach(root->right, expectNumber);
        }
        cur.pop_back();
    }
};

int main(){

    Solution s;

    TreeNode * s1 = new TreeNode(8);
    s1->left = new TreeNode(8);
    s1->right = new TreeNode(7);
    s1->right->left = new TreeNode(7);
    s1->left->left = new TreeNode(9);
    s1->left->right = new TreeNode(2);
    s1->left->right->left = new TreeNode(4);
    s1->left->right->right = new TreeNode(7);

    vector<vector <int>> v = s.FindPath(s1, 22);

    for(int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {

            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
