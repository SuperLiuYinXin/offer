
#include <iostream>
#include "utils.h"

/*****************************/
/*　filename: N叉树的最大深度.cpp */
/*　abstract: 给定一个 N 叉树，找到其最大深度
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-15 11:55:20  */
/*****************************/
/*****************************/

using namespace std;


class Solution {
public:
    int maxDepth(Node* root) {
      int deep = 0;
      if (root == NULL)
        return deep;
      else 
        deep += 1;
      if (root->children.size() == 0) 
        return deep;
      for (int cur = 0, i = 0; i < root->children.size(); ++i) {
        if (!root->children[i]) 
          continue;
        cur = maxDepth(root->children[i]);
        if (deep < cur) 
          deep = cur;
      }
      return deep + 1;
    }
};

// 加速读取
static const auto io_speed_up = []()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();


int main(){

    return 0;
}
