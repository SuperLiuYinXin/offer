
#include <iostream>
#include <vector>
#include <queue>

/*****************************/
/*　filename: 调整数组顺序使奇数位于偶数前面.cpp */
/*　abstract: 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
            使得所有的奇数位于数组的前半部分，
            所有的偶数位于数组的后半部分，并保证奇数和奇数，
            偶数和偶数之间的相对位置不变。 */
/*　author :  liuyinxin  */
/*　time:     2018-12-29 21:47:42  */
/*****************************/
/*****************************/

using namespace std;

// 思路：　两个队列，一个方奇数，一个放偶数，全部入队再出队
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.size() <= 1) 
            return ;
        queue<int> odd, enve;
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] & 1) {
                odd.push(array[i]);
            } else {
                enve.push(array[i]);
            }
        }
        for (int i = 0; i < array.size(); ++i) {

            if (odd.empty()) {
                array[i] = enve.front();
                enve.pop();
            } else {
                array[i] = odd.front();
                odd.pop();
            }
        }
        
    }
};

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);
    v.push_back(6);
    v.push_back(4);
    v.push_back(7);
    
    Solution s;


    s.reOrderArray(v);


    for (int i = 0; i < v.size(); ++i) {

        cout << v[i] << " ";
    }
    return 0;
}
