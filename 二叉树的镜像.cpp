
#include <iostream>

/*****************************/
/*　filename: 二叉树的镜像.cpp */
/*　abstract: 判断是否是镜像的二叉树  */
/*　author :  liuyinxin  */
/*　time:     2018-12-31 00:56:10  */
/*****************************/
/*****************************/

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL)
            return; 

        TreeNode * tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;

        if (pRoot->left != NULL)
            Mirror(pRoot->left);
        
        if (pRoot->right != NULL)
            Mirror(pRoot->right);
    }

};

int main(){

    TreeNode * s1 = new TreeNode(8);
    s1->left = new TreeNode(8);
    s1->right = new TreeNode(7);
    s1->left->left = new TreeNode(9);
    s1->left->right = new TreeNode(2);
    s1->left->right->left = new TreeNode(4);
    s1->left->right->right = new TreeNode(7);

    Solution s;
    s.Mirror(s1);
    return 0;
}
