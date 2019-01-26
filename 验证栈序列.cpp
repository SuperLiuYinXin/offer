#include <iostream>
#include <vector>
#include <stack>

/*****************************/
/*　filename: 验证栈序列.cpp */
/*　abstract: 验证栈的出站序列是否合法  */
/*　author :  liuyinxin  */
/*　time:     2018-12-31 23:31:33  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    // leecode
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) 

            return false;

        else if (pushed.size() <= 0) 

            return true;

        stack<int> s;
        int j = 0;
        for (int i = 0 ; i < pushed.size(); ++i) {

            s.push(pushed[i]);
            while (j < popped.size() && !s.empty() && popped[j] == s.top()) {

                ++j;
                s.pop();
            }
        }
        return s.empty();
    }

    // 牛客网
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        
        return validateStackSequences(pushV, popV);
    }
};

int main(){
    return 0;
}
