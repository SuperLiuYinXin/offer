
#include <iostream>
#include "utils.h"

/*****************************/
/*　filename: 二叉树的下一个结点.cpp */
/*　abstract: 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-19 15:37:54  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
      if (pNode == NULL)
        return NULL;

      // 如果有有孩子,这是右孩子
      /// 右孩子的最左边的节点, 这个有问题，忘记了
      if (pNode->right != NULL)  {
        pNode = pNode->right;
        while (pNode->left != NULL) {
          pNode = pNode->left;
        }
        return pNode;
      }
      // 如果没有右孩子，且父亲节点为空，说明没有其他节点可以遍历
      // 该节点是父亲节点的左子树，下一个节点就是父亲节点
      // 说明是右子树,寻找父亲节点,有右子树
      while (pNode->next != NULL) {
        if (pNode->next->left == pNode) {
          return pNode->next;
        } 
        pNode = pNode->next;
      }
      return NULL;
    }
};

int main(){
  TreeLinkNode * node = new TreeLinkNode(0);
  node->left = new TreeLinkNode(1);
  node->left->next = node;
  node->right = new TreeLinkNode(2);
  node->right->next = node;
  node->left->left = new TreeLinkNode(3);
  node->left->left->next = node->left;
  Solution s;
  cout << s.GetNext(node->left->left)->val << endl;
  cout << s.GetNext(node->left)->val << endl;
  cout << s.GetNext(node)->val << endl;
  return 0;
}
