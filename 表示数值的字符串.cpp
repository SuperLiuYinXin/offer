
#include <iostream>
#include <string>
#include <string.h>

/*****************************/
/*　filename: 表示数值的字符串.cpp */
/*　abstract: 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值
 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-18 15:23:16  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
      int flag = 0, flat = 0, point = 0;
public:
    bool isNumeric(char* string)
    {
      bool rtn = false;
      int len;
      if (string == NULL || (len = strlen(string)) <= 0  )
        return rtn;

      char * str = string;
      flag = 0, flat = 0, point = 0;
      if (*str != '\0') {
        if (*str == '+' || *str == '-') {
          ++str;
        }
      }
      return check(str);
    }
    bool check (char *str) {
      if (*str == '\0')
        return false;
      while (*str != '\0') {
        /// 处理e的
        if (*str == 'e' || *str == 'E' ) {
          if (flat > 0) 
            return false;
          ++flat;
          return check(++str);
        }
        if (*str == '.') {
          if (point > 0 || flat)  
            return false;
          ++point;
          return check(++str);
        }
        if ((*str == '-' || *str == '+') && (*(str - 1) == 'e' || 'E' == *(str - 1)) && flag < 1)
          ++flag;
        else if (*str < '0' || *str > '9')
          return false;
        ++str;
      }
      return true;
    }

};

int main(){
  Solution s;
  char str[100];
  cout << s.isNumeric(NULL) << endl;;
  strcpy(str, "+100");
  cout << s.isNumeric(str) << endl;
  strcpy(str, "5e2");
  cout << s.isNumeric(str) << endl;
  strcpy(str, "3.1416");
  cout << s.isNumeric(str) << endl;
  strcpy(str, "-123");
  cout << s.isNumeric(str) << endl;
  strcpy(str, "-1E-16");
  cout << s.isNumeric(str) << endl;
  strcpy(str, "12e");
  cout << s.isNumeric(str) << endl;
  strcpy(str, "1a3.14");
  cout << s.isNumeric(str) << endl;
  strcpy(str, "+-5");
  cout << s.isNumeric(str) << endl;
  strcpy(str, "1.2.3");
  cout << s.isNumeric(str) << endl;
  strcpy(str, "12e+4.3");
  cout << s.isNumeric(str) << endl;
    return 0;
}
