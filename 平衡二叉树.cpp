
#include <iostream>
#include "utils.h"

/*****************************/
/*　filename: 平衡二叉树.cpp */
/*　abstract: 输入一棵二叉树，判断该二叉树是否是平衡二叉树
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-15 15:19:27  */
/*****************************/
/*****************************/

using namespace std;

// 通过后序遍历
// 这样，注意优先级　　1 + (left > right : left : right)

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
      int deep = 0;
      return isBalance(pRoot, &deep);
    }

    bool isBalance(TreeNode * node, int * deep) {
      if (node == NULL) {
        *deep = 0;
        return true;
      }
      int left, right;
      if (isBalance(node->left, &left) && isBalance(node->right, &right)) {
          int diff = left - right;
          if (diff <= 1 && diff >= -1) {
            // 注意优先级
            *deep = 1 + (left > right ? left: right);
            return true;
          }
      }
      return false;
    }
};

int main(){
    TreeNode * s1 = new TreeNode(8);
    s1->left = new TreeNode(8);
    // s1->right = new TreeNode(7);
    // s1->right->left = new TreeNode(7);
    s1->left->left = new TreeNode(9);
    s1->left->right = new TreeNode(2);
    s1->left->right->left = new TreeNode(4);
    // s1->left->right->right = new TreeNode(7);
    Solution s;
    cout << s.IsBalanced_Solution(s1) << endl;
    return 0;
}
