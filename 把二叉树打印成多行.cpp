#include <iostream>
#include "utils.h"
#include <queue>


/*****************************/
/*　filename: 把二叉树打印成多行.cpp */
/*　abstract: 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。  */
/*　author :  liuyinxin  */
/*　time:     2019-02-20 10:46:10  */
/*****************************/
/*****************************/
using namespace std;


class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> rtn;
            if (pRoot == NULL)  {
                return rtn;
            }

            queue<TreeNode * > a, b;
            TreeNode * cur = pRoot;
            a.push(cur);
            bool dir = true;
            while (!a.empty() || !b.empty()) {
                vector<int> v;
                if (dir) {
                    dir = false;
                    while (!a.empty()) {
                        cur = a.front();
                        v.push_back(cur->val);
                        a.pop();
                        if (cur->left)
                            b.push(cur->left);
                        if (cur->right)
                            b.push(cur->right);
                    }
                } else {
                    dir = true;
                    while (! b.empty()) {
                        cur = b.front();
                        v.push_back(cur->val);
                        b.pop();
                        if (cur->left)
                            a.push(cur->left);
                        if (cur->right)
                            a.push(cur->right);
                    }
                }
                rtn.push_back(v);
            }

        
            return rtn;
        }
    
};

using namespace std;

int main(){
    Solution s;
    TreeNode * s1 = new TreeNode(8);
    s1->left = new TreeNode(1);
    s1->right = new TreeNode(6);
    s1->right->left = new TreeNode(3);
    s1->right->right = new TreeNode(4);
    s1->left->left = new TreeNode(1);
    s1->left->right = new TreeNode(2);
    // s1->left->right->right = new TreeNode(7);

    vector< vector<int>> rtn = s.Print(s1);
    for (int i = 0; i < rtn.size(); ++i) {
      for (int j = 0; j <rtn[i].size(); ++j) {
        cout << rtn[i][j] << " ";
      }
      cout  << endl;
    }
    return 0;
}
