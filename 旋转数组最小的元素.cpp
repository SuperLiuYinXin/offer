
#include <iostream>
#include <vector>

/*****************************/
/*　filename: 旋转数组最小的元素.cpp */
/*　abstract: 
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组 {3,4,5,1,2} 为 {1,2,3,4,5} 的一个旋转，
该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
/*　author :  liuyinxin  */
/*　time:     2018-12-27 23:14:11  */
/*****************************/
/*****************************/

using namespace std;

/**
 * 
 * 思路:
 * 看网上大佬的思路
 * 二分查找呀
 * 左右指针
 * 左边永远大大于右边
 * 分成两个递增数组
 * 这样就ok
 * 左边的永远小于右边的
 * 
 * PS:
 * 注意题目给的条件
 * 很重要啊
 */
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int len = rotateArray.size() - 1;
        int i = 0, j = len, mid = 0;
        while (rotateArray[i] >= rotateArray[j]) {
            if (j - i <= 1) {

                mid = rotateArray[j];
                break;
            }

            mid = i + (j - i) / 2;
            // cout << mid << endl;
            if (rotateArray[mid] >= rotateArray[i]) {

                i = mid;

            } else if (rotateArray[mid] <= rotateArray[j]) {

                j = mid;

            }
            // cout << "i = " << i << " j= " << j << endl;
        }
        return mid;
    }
};

int main(){
    Solution s;

    vector<int> v;
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    // v.push_back(1);
    // v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);
    cout << 
        s.minNumberInRotateArray(v);
    return 0;
}
