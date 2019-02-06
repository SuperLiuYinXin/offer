
#include <iostream>
#include <vector>

/*****************************/
/*　filename: 数组中的逆序对.cpp */
/*　abstract: 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对
输入一个数组,求出这个数组中的逆序对的总数P
并将P对1000000007取模的结果输出
 即输出P%1000000007  */
/*　author :  liuyinxin  */
/*　time:     2019-02-06 11:20:05  */
/*****************************/
/*****************************/

using namespace std;


// 思路
// 类似于插入排序
class Solution {
public:
    int InversePairs(vector<int> data) {
        int arr[data.size()], copy[data.size()];
        for (int i = 0; i < data.size(); ++i) {
            arr[i] = data[i];
            copy[i] = data[i];
        }
        // 0   data.size() - 1
        return InversePairsCore(arr, copy, 0, data.size() - 1);
    }
    int InversePairsCore(int * data, int * copy, int begin, int end) {
        if (begin == end) {
            copy[begin] = data[begin];
            return 0;
        }
        int lenght = ( end - begin ) / 2, count = 0, left, right,i, j;
        int mid = begin + lenght;
        left = InversePairsCore(copy, data, begin, mid ) % 1000000007;
        right = InversePairsCore(copy, data, mid + 1, end) % 1000000007;
        // cout << "left = " << left<< " right = " << right << endl;
        i = mid, j = end;
        int copyIndex = end;
        for (; i >= begin && j >= mid + 1; ) {
            // 乱序
            if (data[i] > data[j]) {
                copy[copyIndex--] = data[i--];
                count += j - mid;
                // 不然会溢出!!!!!!!
                count %= 1000000007;
            } else {
                copy[copyIndex--] = data[j--];
            }
        }
        for (; i>= begin;--i) 
            copy[copyIndex--] = data[i];

        for (; j >= mid + 1; --j) 
            copy[copyIndex--] = data[j];

            
        // cout << "begin " << begin << " end " << end;
        // cout << " return " << (left + right + count ) % 1000000007 << endl;
        return (left + right + count ) % 1000000007;
    }
};

int main(){
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(0);
    cout << s.InversePairs(v) << endl;
    return 0;
}
