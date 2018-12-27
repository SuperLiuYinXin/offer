#include <iostream>
#include <stack>

/*****************************/
/*　filename: 用两个栈队列.cpp*/
/*　abstract: 用两个栈来实现一个队列，完成队列的push和pop操作
队列中的元素为int类型  */
/*　author :  liuyinxin  */
/*　time:     2018-12-27 22:40:07  */
/*****************************/
/*****************************/

using namespace std;

/*基本是两个栈来回倒*/
class Solution
{
public:
    void push(int node) {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(node);
    }

    int pop() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int res = s2.top();
        s2.pop();
        return res;
    }

private:
    stack<int> s1;
    stack<int> s2;
};

int main(){
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.push(6);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}
