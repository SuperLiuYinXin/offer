
#include <iostream>
#include "utils.h"
#include <stack>

/*****************************/
/*　filename: 按之字形顺序打印二叉树.cpp */
/*　abstract: 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-19 19:26:12  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
      vector<vector<int>> rtn;
      if (pRoot == NULL) {
        return rtn;
      }
      stack<TreeNode *> s, q, * curStack;
      int dir = 0;
      q.push(pRoot);
      TreeNode * cur;
      while (!q.empty() || !s.empty()) {
        vector<int> v;
        if (dir == 0) {
          dir = 1;
          while (!q.empty()) {
            cur = q.top();
            q.pop();
            v.push_back(cur->val);
            if (cur->left != NULL)
              s.push(cur->left);
            if (cur->right != NULL)
              s.push(cur->right);
          }
        } else if (dir == 1) {
          dir = 0;
          while (!s.empty()) {
            cur = s.top();
            s.pop();
            v.push_back(cur->val);
            // 注意这里先右后左
            if (cur->right != NULL)
              q.push(cur->right);
            if (cur->left != NULL)
              q.push(cur->left);
          }
        }
        rtn.push_back(v);
      } 
      return rtn;
    }
    
};

int main(){
    TreeNode * s1 = new TreeNode(8);
    s1->left = new TreeNode(1);
    s1->right = new TreeNode(6);
    s1->right->left = new TreeNode(3);
    s1->right->right = new TreeNode(4);
    s1->left->left = new TreeNode(1);
    s1->left->right = new TreeNode(2);
    // s1->left->right->right = new TreeNode(7);
    Solution s;
    vector< vector<int>> rtn = s.Print(s1);
    for (int i = 0; i < rtn.size(); ++i) {
      for (int j = 0; j <rtn[i].size(); ++j) {
        cout << rtn[i][j] << " ";
      }
      cout  << endl;
    }
    return 0;
}
