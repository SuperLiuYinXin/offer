
#include <iostream>
#include <string>

/*****************************/
/*　filename: 检查替换后的词是否有效.cpp */
/*　abstract: leetcode 1003

给定有效字符串 "abc"。

对于任何有效的字符串 V，我们可以将 V 分成两个部分 X 和 Y，使得 X + Y（X 与 Y 连接）等于 V。（X 或 Y 可以为空。）那么，X + "abc" + Y 也同样是有效的。

例如，如果 S = "abc"，则有效字符串的示例是："abc"，"aabcbc"，"abcabc"，"abcabcababcc"。无效字符串的示例是："abccba"，"ab"，"cababc"，"bac"。

如果给定字符串 S 有效，则返回 true；否则，返回 false。  
*/
/*　author :  liuyinxin  */
/*　time:     2019-03-03 10:56:22  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    bool isValid(string S) {
        // cout << "S = " << S << endl;
        if (S.size() > 2 && S.size() % 3 == 0) {
            if (S == "abc") {
                return true;
            }
            int s_pos = S.find("abc");
            bool fs = false;
            string substr;
            while (s_pos != string::npos) {
                int ns_pos = S.find("abc", s_pos + 1);
                while (ns_pos != string::npos && ns_pos == s_pos + 3) {
                    s_pos = ns_pos;
                    ns_pos = S.find("abc", s_pos + 1);
                }
                substr = S.substr(0, s_pos) + S.substr(s_pos + 3);
                if (substr.size() <=0 || substr[0] != 'a' || substr[substr.size() - 1] != 'c')
                    break;
                fs = isValid(substr);
                if (fs) 
                    return fs;
                s_pos = ns_pos;
                // cout << s_pos << endl;
            }

        }
        return false;
    }
};

int main(){
    Solution s;
    // cout << "abcabc = "  <<  s.isValid("abcabc") <<  " = 1" << endl;
    string str = "aabcbc";
    // cout << str + "= "  <<  s.isValid(str) <<  " = 1" << endl;
    str = "abcabcababcc";
    cout << str + "= "  <<  s.isValid(str) <<  " = 1" << endl;
    // str = "aaaccbcbabcacbaaccbaabbababaaaaacabcaaacabbaccaabccaccababbabbaaaaabccacacabaabcabcbcbacbcbccabcbaacbacbbbabbcaacbcaabcbabcacaabbbacacaabacbbacbbcacbcabcacbbaccbcbcbcaabbcccacbccbcaacbccccabbcbccbcccbccccbcbacabbccabbabbcccaaabacbcaaaacaaaabbbabcbcbcaabcaccbcabaaaccbbccacabbacaaabacacaabbabbccccababbcbcccbccccabacbccbcbcabcbacbbabcaacbbccaabbbacaacbbcaaaabbbbccbcbbbccbbcbabbcacbbbcbaccbccbaacccabbbaabccbaccbbacaacbabbaccbabbabcccaaacacaaccbbbbcccbcabbabbbababbbabbcabaacbbcbaccbacbaacbccccbcaccacacabaccccbccbbbaaabcbccaccaccbcacbcacbaabccaabccbaacabccbbbacbbcaaabbccbcbaccacababbcaacabccccbccbacbbaccaaaccacbacaaaaccbbcacbcccbacbbbbacabbcbbaacbaabaaabbbabcababccbbbbbaaccaabaaabccbccbaacbaaaaaabcbacccbbccacccccbbbcacbbacaaaccbcacbcbcbcbcbaaccabbcccbababcccbabcbbbaabcababcbaabbabbbaacbbaababbbaccbaaabbbaaabbabbcbbccabcccccabbcbaaacbcacacccbabbaaabacbbabbaacabaabbcbbcbbcbbaacbccacaacaccbbcacacbccbabbabbcbccaabccbacbbcacbbbaaaaccabbacccaaacbacabaccbbcaabcbcabcbcbbacccabbabcacbcbaaaacbbcbbccabbaacbcaabccacbccbacbccaacbacbcababcaacacccaacbcabbaabcccaaacccbbacabaaccbaacbbcbabcccbacbbbcaabcbbbbbaaabcbccabcccabaaaacaabaacaacaabacbcccccaaabaaabcaacbcacccccabbbacccabcabbaccabbaccacbacabbacaacacaabbacaccaabcbaccacbbbabcacbbcbccabcabbccaccabbbabcbabbaaacccbaacbaabcbcaccbbcbacbcaaabbccacacbcbcbcacabaaacaccbacbcaacacacccbccabbbbacabacaacacacaccabaacaccbbbcbbacacbaacaaaacacbaabbaacbaacaaabcbbbaaccabbabaccabcaccabccbbacccbcacabacbacaacacbbcbbbcbaaaacccacbacabbaaabaaccccacccacaacbaccaccbccabbbbccacccacccbbacbcbaccbcaacbacbbbbabaacabaaccabbabccbacaabbcacbaacaacabcbbbbbcbaacaaccbbaababbbcbcabaccbccaabccaccaacacbbcbbbcabbcbacabaccbccabcbbabcacbacaaccccaaccacabbccaccccbcacbaacbabcaccbbabcacabbbbbcccabbabcabbbaacbbccbcabacabbcbcaaabbcabbcbacaabcacaccacacbcbcbbcbaaaacaacbcbbaccacccbbaacbbaabccaabbacabcbbacbbbbbbabababacbbcbbabcccabbbaaabcababaabbaacbbacccccccccbbcaaaabcbacaaaccaacbbacbcccacbbbcbacaacacbababcacccbabccaccacccabbcbccbcbccbaccbbbbbbcabacccccbbbcabcbacbacacabbcbbbccbbaaaabbbbcbaaaccbabbcbabaaaacbacbbccbbbbaacbbbbabcacabaaaccbcccabacaacbcaccabababaaabbbbbababbaabcaababaacccbbaabcbabbbccbaccabaaaaacabaababbcbbcaaaaccbababbbbbacbaccabaccaccacaacabaabacabaabbabacaacbccbcbaacbaaaabaabbcacaabbcbcaabaccbbacbaccabbcacabcbbbbacabcaacaabcbbacbabbbbaabcaacaababaabcbbcacbbabccbbaababaccabcbbbcaaccbbbbbccbacbacccbbaacacbcaccbcbbacbacaccaccaabbcaabacbcbbababbbcbccbacbbbacbabcabacacbacaacaaccababbcacaaabbbaacbcbcbcbbaabaaabbbbcaaaaacbcaacbcaacbcbbaccacccbaacbacbbabcabcbcccabbbbccabcbbbcabaaccacaacacabbcaaaccbbbbccccbaaabbbaccbbccacaabcbbbccaccabaccccaabacacacabacaabcbaaccaacbbbabaaaccacaaabaccccbcbcacabaaabccabaabbbcbcbaaaacbcbbbbbbbbbccbbcbbaaabbcbababbbcbbabacbaacbbcbacaabcbaabacbaabacbbcaaccbabaabbcbbaacbaccbccbbccbcbabcccaaacbbcaacabccbcbaacabacacaaaccbacbbcacacabbacbbaccbacaaacabcabbbaaabbbbcbcabcbcacbbabaabbbccacbacaccbcccbacccacbbcababaaabaaaabbabbcbbbbbcbbaaacccbabcacaaacacbaacabaccacabacaacbccaabcbcbbaccaacabbabbcabcabababbcbccbaccbbbaaccacbaaacbcabcbbcbbcbbcacaacaaabaaaabcbcacbaccbacaccbbcbcbabbccbbacacbcaccaabcbcaacabaccaaacbccbaaabccaacccbabccabccabbccacbbcbcbcccaacaccbbcabbbcabcbbcccabcbabcacabaabccaacbcccaabacaacbbbcabcccaabbbacccbcacccbcbabbcccaabccabccbabcbcbaabbcaabcbcaabbbcbbabcaccacbababbabacaaaabbccabcbccababbabbbbbcbcbbabaccabababbacbcababaccbbbaaacbbccabbcccccabaaaccbbbabbccbbbcbabcaaaabbbabbbacacbcabaaacabccbbcaaacccbcbbaaabbbacaaccacabacacbbacccaaabbcbaabbbabaacacbbaaabbaaaacbabaacbacbbccaacaacababbbcbbbbabbcabaababbaaabaaaccbacbaacccccbbbbccbbacaaabbbccbaabccabcabaccaacbcaaccabcccacbbcaccbcaacaccaababccbabccbabccbacbacacbccababcbbaabacabacccaacbacbcccacbaccababcccaaaaa";
    // cout << str + "= "  <<  s.isValid(str) <<  " = 1" << endl;
    // str = "abccba";
    // cout << str + "= "  <<  s.isValid(str) <<  " = 0" << endl;
    // str = "cababc";
    // cout << str + "= "  <<  s.isValid(str) <<  " = 0" << endl;
    // cout << str.substr(0, 0) << endl;
    // cout << str.substr(6) << endl;
    return 0;
}
