
#include <iostream>
#include <string>

/*****************************/
/*　filename: 左旋转字符串.cpp */
/*　abstract: 
            汇编语言中有一种移位指令叫做循环左移（ROL），
            现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
            对于一个给定的字符序列S，
            请你把其循环左移K位后的序列输出。
            例如，字符序列S=”abcXYZdef”,
            要求输出循环左移3位后的结果，即“XYZdefabc”。
            要求输出循环左移4位后的结果，即“YZdefabcX”。
            要求输出循环左移5位后的结果，即“ZdefabcXY”。
            要求输出循环左移6位后的结果，即“defabcXYZ”。 
            要求输出循环左移7位后的结果，即“efabcXYZd”。             
            要求输出循环左移8位后的结果，即“fabcXYZde”。             
            要求输出循环左移9位后的结果，即“abcXYZdef”。
            */
/*　author :  liuyinxin  */
/*　time:     2019-02-16 23:50:22  */
/*****************************/
/*****************************/

using namespace std;
//　偷懒的方法，直接用string的库函数
// 但是要注意，将n 取模

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.size() <= 1)
            return str;
            
        n = n % str.size();
        return str.substr(n) + str.substr(0, n);
        
    }
};

int main(){
    Solution s;
    for (int i = 0; i < 11; ++i) {
        cout << s.LeftRotateString("abcXYZdef", i) << " " << i<< endl;

    }
    // cout << s.LeftRotateString("", 3) << endl;
    // cout << s.LeftRotateString("abcXYZdef", 3) << endl;
    // cout << s.LeftRotateString("abcXYZdef", 3) << endl;
    // cout << s.LeftRotateString("abcXYZdef", 3) << endl;
    // cout << s.LeftRotateString("abcXYZdef", 3) << endl;
    // cout << s.LeftRotateString("abcXYZdef", 3) << endl;
    return 0;
}
