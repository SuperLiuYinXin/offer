
#include <iostream>
#include <string>

/*****************************/
/*　filename: 翻转单词顺序列.cpp */
/*　abstract: 
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志， 写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。
后来才意识到，这家伙原来把句子单词的顺序翻转了
正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？  */
/*　author :  liuyinxin  */
/*　time:     2019-02-17 00:02:24  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.size();
        if (len <= 1)
            return str;

        char arr[len + 1]; 
        len = str.copy(arr, len);
        arr[str.size()] = '\0';
        reverse(arr, 0, len - 1);

        int i = 0, j = 0;
        for (; i < len; ++i) {
            if (arr[i] == ' ') {
                reverse(arr, j, i - 1);
                j = i + 1;
            }
        }
        if (j < len)
            reverse(arr, j, len - 1);

        return string(arr);
    }
    void reverse(char * arr, int begin, int end) {
        char tmp;
        for (int i = begin, j = end; i < j; ++i, --j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
};

int main(){
    Solution s;
    cout << s.ReverseSentence("student. a am I") << endl;
    cout << s.ReverseSentence("I") << endl;
    cout << s.ReverseSentence("am") << endl;
    cout << s.ReverseSentence("a m") << endl;
    cout << s.ReverseSentence("hello world") << endl;
    cout << s.ReverseSentence("") << endl;
    return 0;
}
