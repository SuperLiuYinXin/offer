
#include <iostream>
#include <stack>

/*****************************/
/*　filename: 包含min函数的栈.cpp */
/*　abstract: 包含min函数的栈  */
/*　author :  liuyinxin  */
/*　time:     2018-12-31 22:54:29  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
    stack<int> s1, s2;
public:
    void push(int value) {
        if (s2.empty() || s2.top() >= value) 
            s2.push(value);
        s1.push(value);
    }
    void pop() {
        if (s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};

int main(){
    return 0;
}
