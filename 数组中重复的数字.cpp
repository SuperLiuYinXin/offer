
#include <iostream>
#include <set>

/*****************************/
/*　filename: 数组中重复的数字.cpp */
/*　abstract: 
在一个长度为n的数组里的所有数字都在0到n-1的范围内。
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
*/
/*　author :  liuyinxin  */
/*　time:     2019-02-17 16:04:00  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length <= 0) 
            return false;

        set<int> hset;
        for (int i = 0; i < length; ++i) {
            if (hset.find(numbers[i]) != hset.end()) {
                *duplication = numbers[i];
                return true;
            }
            hset.insert(numbers[i]);
        }
        return false;
    }
    // 方法二
    /* * 
    不需要额外的数组或者hash table来保存，
    题目里写了数组里数字的范围保证在0 ~ n-1 之间，
    所以可以利用现有数组设置标志，当一个数字被访问过后，
    可以设置对应位上的数 + n，之后再遇到相同的数时，
    会发现对应位上的数已经大于等于n了，那么直接返回这个数即可。
     */
    int find_dup( int numbers[], int length) {

        for ( int i= 0 ; i<length; i++) {

            int index = numbers[i];

            if (index >= length) {

                index -= length;

            }   

            if (numbers[index] >= length) {

                return index;

            }   

            numbers[index] = numbers[index] + length;

        }   

        return - 1 ; 

    }
};

int main(){
    Solution s;
    int arr[8] = {2,3,1,0,2,5,3};
    int duplication;
    s.duplicate(arr, 7, &duplication);
    cout << duplication;
    return 0;
}
