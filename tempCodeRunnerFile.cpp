class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
      int deep = 0;
      return isBalance(pRoot, &deep);
    }

    bool isBalance(TreeNode * node, int * deep) {
      if (node == NULL) {
        *node = 0;
        return true;
      }
      int left, right;
      if (isBalance(node->left, &left)
          && isBalance(node->right, &right)) {
          int diff = left - right;
          if (diff <= 1 && diff >= -1) {
            *deep = 1 + left < right ? right : left;
            return true;
          }
      }
      return false;
    }
};