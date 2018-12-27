
#include <iostream>
#include <vector>

/*****************************/
/*　filename: 重建二叉树.cpp */
/*　abstract: 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
    假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
    例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。  */
/*　author :  liuyinxin  */
/*　time:     2018-12-27 00:24:33  */
/*****************************/
/*****************************/

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// begin [l --- r]
TreeNode * gen_tree(vector<int>& pre, vector<int>& vin, int pl, int pr, int ml, int mr) {
    if (pl > pr) {
        return NULL;
    }
    int preRoot = pre[pl], i = ml;
    for (i = ml;  i <= mr && preRoot != vin[i]; ) {
        ++i;
    }

    TreeNode * root = new TreeNode(preRoot);
    // cout << preRoot << " i=" << i  << endl;
    root->left = gen_tree(pre, vin, pl + 1, pl + i - ml, ml, i - 1);
    root->right = gen_tree(pre, vin, pl + i + 1 - ml, pr, i + 1, mr);
    return root;
}

// 中序遍历
void printTree(TreeNode * root) {
    if (root == NULL) 
        return;
    printTree(root->left);
    cout << root->val << endl;
    printTree(root->right);
}

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() <= 0 || vin.size() <= 0 || pre.size() != vin.size() ) 
            return NULL;

        return gen_tree(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    }
};

int main(){
    vector<int> pre, vin;
    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(4);
    pre.push_back(7);
    pre.push_back(3);
    pre.push_back(5);
    pre.push_back(6);
    pre.push_back(8);

    vin.push_back(4);
    vin.push_back(7);
    vin.push_back(2);
    vin.push_back(1);
    vin.push_back(5);
    vin.push_back(3);
    vin.push_back(8);
    vin.push_back(6);
    Solution s;
    TreeNode * t = s.reConstructBinaryTree(pre, vin);
    printTree(t);
    return 0;
}
