
#include <iostream>
#include "utils.h"
#include <stack>

/*****************************/
/*　filename: 二叉搜索树与双向链表.cpp */
/*　abstract: 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表
要求不能创建任何新的结点，只能调整树中结点指针的指向
  */
/*　author :  liuyinxin  */
/*　time:     2019-01-30 17:27:13  */
/*****************************/
/*****************************/

using namespace std;
class Solution {
  private: 
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
      if (pRootOfTree == NULL) {
        return pRootOfTree;
      }
      TreeNode * t = NULL;
      convertNext(pRootOfTree, t);

      while(t && t->left) {
        t = t->left;
      }
      return t;
    }
    void convertNext(TreeNode * root, TreeNode * & lastNode) {

      if (root == NULL) {
        return ;
      }

      TreeNode * n = root;

      if (n->left) {
        convertNext(n->left, lastNode);
      }

      n->left = lastNode;

      if (lastNode) {
        lastNode->right = n;
      }

      lastNode = n;
      if (n->right != NULL) {
        convertNext(n->right, lastNode);
      }

    }
};

int main(){

    TreeNode * s1 = new TreeNode(8);
    s1->left = new TreeNode(8);
    s1->right = new TreeNode(7);
    s1->right->left = new TreeNode(7);
    s1->left->left = new TreeNode(9);
    s1->left->right = new TreeNode(2);
    s1->left->right->left = new TreeNode(4);
    s1->left->right->right = new TreeNode(7);

    Solution s;
    TreeNode * tree =  s.Convert(s1);
    cout << tree->val << endl;
    cout << tree->left->right->val << endl;
    return 0;
}
