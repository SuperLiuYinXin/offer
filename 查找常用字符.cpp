
#include <iostream>
#include <vector>
#include <string>

/*****************************/
/*　filename: 查找常用字符.cpp */
/*　abstract: Leetcode 1002  */
/*　author :  liuyinxin  */
/*　time:     2019-03-03 10:31:37  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int len = A.size();
        vector<string> rtn;

        if (len <= 0)
            return rtn;

        int arr[len][26];
        for (int i = 0; i < len; ++i){
            for (int j = 0; j < 26; ++j)  {    
                arr[i][j] = 0;
            }
        }

        vector<string>::iterator ite = A.begin();
        string::iterator site;
        for (int i = 0; ite != A.end(); ++ite, ++i) {
            site = ite->begin();
            while (site != ite->end()) {
                ++arr[i][*site - 'a'];
                ++site;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (arr[0][i] > 0) {
                int minv = 0x7fffffff;
                for (int j = 0; j < len; ++j) {
                    if (arr[j][i] <= 0) {
                        minv = 0;
                        break;
                    }
                    minv = min(arr[j][i], minv);
                }
                if (minv != 0 && minv != 0x7fffffff) {
                    while (minv--)
                        rtn.push_back(string(1,  (char) (i + 'a')));
                } 
            }
        }
        return rtn;
    }
};

int main(){
    Solution s;
    vector<string> v;
    // v.push_back("cool");
    // v.push_back("lock");
    // v.push_back("cook");
    v = s.commonChars(v);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
    return 0;
}
