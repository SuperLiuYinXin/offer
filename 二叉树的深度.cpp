
#include <iostream>
#include "utils.h"

/*****************************/
/*　filename: 二叉树的深度.cpp */
/*　abstract: 输入一棵二叉树，求该树的深度
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-14 23:03:50  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
private: 
  int maxDeep;
public:
    int TreeDepth(TreeNode* pRoot) {
      maxDeep = 0;
      if (pRoot != NULL) {
        preVisit(pRoot, 1);
      }
      return maxDeep;
    }
    void preVisit(TreeNode * root, int deep) {
      // 根节点
      if (root->left == NULL && root->right == NULL){
        if (maxDeep < deep)
          maxDeep = deep;
      }
      if (root->left) {
        preVisit(root->left, deep + 1);
      }
      if (root->right) {
        preVisit(root->right, deep + 1);
      }

    }
};

int main(){
    TreeNode * s1 = new TreeNode(8);
    s1->left = new TreeNode(8);
    // s1->right = new TreeNode(7);
    // s1->right->left = new TreeNode(7);
    // s1->left->left = new TreeNode(9);
    // s1->left->right = new TreeNode(2);
    // s1->left->right->left = new TreeNode(4);
    // s1->left->right->right = new TreeNode(7);
    Solution s;
    cout << s.TreeDepth(s1) << endl;
    return 0;
}
