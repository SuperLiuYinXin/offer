
#include <iostream>
#include <cmath>
#include <string.h>
#include <queue>

/*****************************/
/*　filename: 字符流中第一个不重复的字符.cpp */
/*　abstract: 请实现一个函数用来找出字符流中第一个只出现一次的字符
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-18 16:00:45  */
/*****************************/
/*****************************/

using namespace std;

class Solution
{
private:
  char rtn = '#';
  int * arr;
  queue<char > cqueue;
public:
  //Insert one char from stringstream
    Solution () {
      arr = new int[256];
      memset(arr, 0, sizeof(int) * 256);
    }
    void Insert(char ch){
      ++arr[ch];
      if (arr[ch] == 1) {
        cqueue.push(ch);
        if (rtn == '#') {
          rtn = ch;
        }
      } else if (ch ==rtn && arr[ch] > 0){
        while (!cqueue.empty() && arr[cqueue.front()] > 1) {
          cqueue.pop();
        }
        if (cqueue.empty())
          rtn = '#';
        else 
          rtn = cqueue.front();
      }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
      return rtn;
    }
    ~Solution () {
      delete[] arr;
    }

};

int main(){
  Solution s;
  // s.Insert('B');
  // cout << s.FirstAppearingOnce() << endl;
  // s.Insert('a');
  // cout << s.FirstAppearingOnce() << endl;
  // s.Insert('b');
  // cout << s.FirstAppearingOnce() << endl;
  // s.Insert('y');
  // cout << s.FirstAppearingOnce() << endl;
  // s.Insert('B');
  // cout << s.FirstAppearingOnce() << endl;
  // s.Insert('a');
  // cout << s.FirstAppearingOnce() << endl;
  // s.Insert('b');
  // cout << s.FirstAppearingOnce() << endl;
  // s.Insert('y');
  // cout << s.FirstAppearingOnce() << endl;
  s.Insert('I');
  cout << s.FirstAppearingOnce() << endl;
  s.Insert('K');
  cout << s.FirstAppearingOnce() << endl;
  s.Insert('n');
  cout << s.FirstAppearingOnce() << endl;
  s.Insert('o');
  cout << s.FirstAppearingOnce() << endl;
  s.Insert('w');
  cout << s.FirstAppearingOnce() << endl;
  s.Insert('y');
  cout << s.FirstAppearingOnce() << endl;
  s.Insert('o');
  cout << s.FirstAppearingOnce() << endl;
  s.Insert('u');
  cout << s.FirstAppearingOnce() << endl;
  s.Insert('l');
  cout << s.FirstAppearingOnce() << endl;
  s.Insert('o');
  cout << s.FirstAppearingOnce() << endl;
  s.Insert('v');
  cout << s.FirstAppearingOnce() << endl;
  s.Insert('e');
  cout << s.FirstAppearingOnce() << endl;
  s.Insert('m');
  cout << s.FirstAppearingOnce() << endl;
  s.Insert('e');
  cout << s.FirstAppearingOnce() << endl;
  return 0;
}
