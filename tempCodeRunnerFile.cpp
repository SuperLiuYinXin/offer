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