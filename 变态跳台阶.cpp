
#include <iostream>

/*****************************/
/*　filename: 变态跳台阶.cpp */
/*　abstract: 一次可以跳n个台阶  */
/*　author :  liuyinxin  */
/*　time:     2018-12-29 10:41:49  */
/*****************************/
/*****************************/

using namespace std;

#include <string.h>
// 其实就是 f(n) = 2 * f(n-1)
class Solution {
private:
    long arr[100000];
public:
    Solution() {
        memset(arr, 0, sizeof(long) * 100000);
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;
    }
    int jumpFloorII(int number) {
        if (number < 0) {

            return 0;
        } 
        if (arr[number] == 0) {


            arr[number] = jumpFloorII(number-1) * 2;
        }

        return arr[number];
    }
};

int main(){

    Solution s;
    cout << s.jumpFloorII(5) << endl;

    return 0;
}
