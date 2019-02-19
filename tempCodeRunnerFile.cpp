class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
      if (pNode == NULL)
        return NULL;

      // 如果有有孩子,这是右孩子
      if (pNode->right != NULL) 
        return pNode->right;
      // 如果没有右孩子，且父亲节点为空，说明没有其他节点可以遍历
      // 该节点是父亲节点的左子树，下一个节点就是父亲节点
      // 说明是右子树,寻找父亲节点,有右子树
      while (pNode->next != NULL) {
        if (pNode->next->left == pNode) {
          return pNode->next;
        } 
        pNode = pNode->next;
      }
      return pNode;
    }
};