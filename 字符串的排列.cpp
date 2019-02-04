
#include <iostream>
#include <vector>
#include <string>
#include <set>

/*****************************/
/*　filename: 字符串的排列.cpp */
/*　abstract: 输入一个字符串,按字典序打印出该字符串中字符的所有排列
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba
  */
/*　author :  liuyinxin  */
/*　time:     2019-01-31 06:21:25  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
private:
  set<string> st;
public:
    vector<string> Permutation(string str) {
      vector<string> result;
      if (str.size() > 0) {

        st.clear();
        Permutation(str, 0);

        
        for (set<string>::iterator iter = st.begin(); iter != st.end(); iter++)
          result.push_back(*iter);
      }

      return result;
    }

    void Permutation(string& s, int begin) {

      if (begin >= s.size()) {
        
        // cout << "add "  << s << endl;
        // result.push_back(s);
        st.insert(s);
        return;
      }


      char beginChar = s[begin], tmpChar;
      // cout <<  "begin " <<  beginChar << " s " <<  s << endl;

      for (int i = begin; i < s.size(); ++i) {

        tmpChar = s[i];
        s[i] = s[begin];
        s[begin] = tmpChar;

        // cout << "swap s  = "  << s << endl;

        Permutation(s, begin + 1);

        tmpChar = s[i];
        s[i] = s[begin];
        s[begin] = tmpChar;
      }
    }
};
int main(){ Solution s;
    vector<string> v;

    v = s.Permutation("aa");
    
    for (int i = 0; i < v.size(); ++i) {

        cout << v[i] << " ";
    }

    return 0;
}
