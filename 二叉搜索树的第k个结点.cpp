
#include <iostream>
#include "utils.h"
#include <stack>

/*****************************/
/*　filename: 二叉搜索树的第k个结点.cpp */
/*　abstract: 给定一棵二叉搜索树，请找出其中的第k小的结点
例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-20 13:43:00  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    // 搜索树中序遍历就ok
    TreeNode* KthNode(TreeNode* pRoot, int k) {
      if (pRoot == NULL || k <= 0) {
        return NULL;
      }
      return notRevers(pRoot, k);
    }
    // 非递归实现
    TreeNode * notRevers(TreeNode * pRoot, int k) {
      stack<TreeNode *> s;
      TreeNode * cur = pRoot;
      while (true) {
        if (cur != NULL) {
          s.push(cur);
          cur = cur->left;
          continue;
        }
        // 如果是空,返回
        if (k <= 1) {
          return s.empty() ? NULL : s.top();
        } 
        cout << s.size() << endl;
        --k;
        // visit mid
        // visit-right
        cur = s.top()->right;
        s.pop();
      }
    }



    // leetcode
    int kthSmallest(TreeNode* root, int k) {
      if (root == NULL || k < 0) {
        return 0;
      }
      time = 0;
      return foreach(root, k)->val;
    }
    int time = 0;
    TreeNode* foreach(TreeNode* node, int k) {
      if (node == NULL) {
        return NULL;
      }
      TreeNode * cur = NULL;
      cur = foreach(node->left, k);
      ++time;
      if (time == k) {
        return node;
      }
      if (time > k){
        return cur;
      }
      return foreach(node->right, k);
    }
};

int main(){
  TreeNode * n1 = new TreeNode(3);
  n1->left = new TreeNode(1);
  n1->right = new TreeNode(4);
  // n1->left->left = new TreeNode(3);
  n1->left->right = new TreeNode(2);
  // s1->left->right->left = new TreeNode(4);
  // s1->left->right->right = new TreeNode(7);
  // n1->right->left = new TreeNode(11);
  Solution s;
  TreeNode * rtn = s.KthNode(n1, 5);
  if (rtn)
    cout << rtn->val << endl;
  else 
    cout << "NULL" << endl;
  return 0;
}
