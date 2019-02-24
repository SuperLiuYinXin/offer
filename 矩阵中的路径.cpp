#include <iostream>

/*****************************/
/*　filename: 矩阵中的路径.cpp */
/*　abstract: 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子
 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-20 17:52:06  */
/*****************************/
/*****************************/

using namespace std;


class Solution {
public:
    // 释放的实际一定要记得判断是否为空
    bool * visits = NULL;
    int len;
    int r, c;
    int dir[4];
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
      len = rows * cols;
      r = rows, c = cols;
      if (matrix == NULL) 
        if (str != NULL && *str == '\0') 
          return true;
        else 
          return false;
      visits = new bool[len + 1]{false};
      // 方向数组  上下左右
      dir[0] = -cols, dir[1] = cols, dir[2] = -1, dir[3] = 1;
      bool rtn = false;
      char * s = matrix;
      while (*s != '\0' && !rtn) {
        if (*s == *str) {
          rtn = traversal(s, s - matrix, str);
        }
        ++s;
      }
      return rtn;
    }

    bool traversal(char * matrix, int pos, char *str) {
      // // 如果不相同false
      // 如果str已经完,这完成
      if (*str == '\0')
        return true;

      // cout << "m="<<* matrix << " s=" << *str <<  endl;;
      if (pos > len || pos < 0 || (*matrix !=  *str)) {
        return false;
      }

      // 标记访问
      if (pos != len)
        visits[pos] = true;
      bool rtn = false;
      int next;
      for (int i = 0; i < 4 && !rtn; ++i) {
        // cout << "martix " << *(matrix + dir[i]) <<  endl;
        next = pos + dir[i];
        if (i > 1 ) {
          if (c == 1 || c == -1) 
            continue;
          else if (pos % c == 0  && dir[i] == -1 || (pos % c == c - 1 && dir[i] == 1) ){
            continue;
          }
        }
        if (!visits[next] &&  next <= len && next >= 0) {
          if (* (str + 1)  == '\0') 
            rtn = true;
          // 防止斜的相同
          else if ( *(matrix + dir[i]) ==  * (str + 1)){
            // cout << "M="<<* (matrix + dir[i]) << " S=" << *(str + 1) <<  endl;;
            rtn = traversal(matrix + dir[i], next, str + 1);
          }
        }
      }
      visits[pos] = false;
      return rtn;
    }
    ~ Solution(){
      if (visits != NULL)
        delete [] visits;
    }
};

int main(){
  Solution s;
  char str[] = "A";
  char seq[] = "A";
  char *c = str;
  for (int i = 0; i < 1; ++i) {
    for (int j = 0; j < 1; ++j) {
      cout << *c << " ";
      ++c;
    }
    cout << endl;
  }
  if (s.hasPath(str, 1, 1, seq) ) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  } 
  return 0;
}
