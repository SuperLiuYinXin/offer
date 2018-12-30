
#include <iostream>

/*****************************/
/*　filename: 树的子结构.cpp */
/*　abstract: 输入两棵二叉树A，B，判断B是不是A的子结构。
              （ps：我们约定空树不是任意一个树的子结构） 
 */
/*　author :  liuyinxin  */
/*　time:     2018-12-30 10:24:28  */
/*****************************/
/*****************************/

using namespace std;

// 坑啊
//　只要就子结构一样
// 而非子树
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

    bool HasSubtree(TreeNode* s, TreeNode* t)
    {
        
        if (s == NULL || t == NULL) {
            return false;
        } 

        bool rtn = false;
        if (s->val == t->val) {
            rtn = isSubtree(s->left, t->left) && isSubtree(s->right, t->right);
        }

        return rtn || (HasSubtree(s->left, t) || HasSubtree(s->right, t));
    }

    bool isSubtree(TreeNode * s, TreeNode * t) {

        if (t == NULL) {
            return true;
        } 

        if (s == NULL) {
            return false;
        } 

        if (s->val == t->val) {
            return isSubtree(s->left, t->left) && isSubtree(s->right, t->right);
        } else 
            return false;
    }
};

int main(){
    Solution s;
    TreeNode * s1 = new TreeNode(8);
    s1->left = new TreeNode(8);
    s1->right = new TreeNode(7);
    s1->left->left = new TreeNode(9);
    s1->left->right = new TreeNode(2);
    s1->left->right->left = new TreeNode(4);
    s1->left->right->right = new TreeNode(7);

    TreeNode  * t1 = new TreeNode(8);
    t1->left = new TreeNode(9);
    t1->right = new TreeNode(2);
    cout << s.HasSubtree(s1, t1) << endl;
    return 0;
}
