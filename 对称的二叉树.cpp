
#include <iostream>
#include "utils.h"

/*****************************/
/*　filename: 对称的二叉树.cpp */
/*　abstract: 请实现一个函数，用来判断一颗二叉树是不是对称的
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-19 19:10:54  */
/*****************************/
/*****************************/

using namespace std;

// 
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
      if (pRoot == NULL) {
        return false;
      }
      return isSymmetrical(pRoot->left, pRoot->right);
    
    }

    bool isSymmetrical(TreeNode * left, TreeNode * right) {
      if (left == NULL && right == NULL) return true;
      if (left == NULL || right == NULL) return false;
      return left->val == right->val && isSymmetrical(left->left, right->right)
            && isSymmetrical(left->right, right->left);
    }

};

int main(){
    TreeNode * s1 = new TreeNode(8);
    s1->left = new TreeNode(6);
    s1->right = new TreeNode(6);
    s1->right->left = new TreeNode(7);
    s1->right->right = new TreeNode(9);
    s1->left->left = new TreeNode(9);
    s1->left->right = new TreeNode(7);
    // s1->left->right->right = new TreeNode(7);
    Solution s;
    cout << s.isSymmetrical(s1) << endl;
    return 0;
}
