
#include <iostream>
#include <vector>
#include <queue>
// 自己定义的工具库
#include "utils.h"

/*****************************/
/*　filename: 从上往下打印二叉树.cpp */
/*　abstract: 从上往下打印出二叉树的每个节点，同层节点从左至右打印
  */
/*　author :  liuyinxin  */
/*　time:     2019-01-26 13:55:38  */
/*****************************/
/*****************************/

using namespace std;
/**
 * 
 * 思路: 
 * 通过一个队列保存每一层的
 * 
 * 
 */


class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
      vector<int> result;

      if (root == NULL) 

        return result;
      
      queue<TreeNode *> treeQueue;
      TreeNode * tmpNode;
      treeQueue.push(root);
      while (! treeQueue.empty()) {

        tmpNode = treeQueue.front();
        treeQueue.pop();
        result.push_back(tmpNode->val);

        if (tmpNode->left != NULL ) 

            treeQueue.push(tmpNode->left);
        
        if (tmpNode->right != NULL ) 

            treeQueue.push(tmpNode->right);

      }

      return result;
    }
};

int main(){



    return 0;
}
