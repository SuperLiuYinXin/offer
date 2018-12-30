
#include <iostream>

/*****************************/
/*　filename: 单值二叉树.cpp */
/*　abstract: leecode[D[D[D  */
/*　author :  liuyinxin  */
/*　time:     2018-12-30 10:30:37  */
/*****************************/
/*****************************/

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    int val = -1;
public:
    bool isUnivalTree(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (val == -1)  {

            val = root->val;
        } else if (val != root->val) {

            return false;
        }
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

int main(){

    return 0;
}
