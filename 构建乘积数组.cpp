#include <iostream>
#include <vector>

/*****************************/
/*　filename: 构建乘积数组.cpp */
/*　abstract: 
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。  */
/*　author :  liuyinxin  */
/*　time:     2019-02-18 10:21:02  */
/*****************************/
/*****************************/

using namespace std;
// 可以创建两个数组
// 分别为前面和后面
// 开始计算

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size());

        if (A.size() <= 0) {
            return A;
        }

        vector<int>::const_iterator ite = A.begin() + 1;
        B[0] = 1;
        for (int i = 1;ite != A.end(); ++ite, ++i) {
            B[i] = B[i - 1] * *(ite - 1);
        }

        long long temp = 1;
        for (int i = A.size() - 2; i >= 0; --i) {
            temp *= A[i + 1];
            B[i] *= temp;
        }

        return B;
    }
};

int main(){
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int> rtn = s.multiply(v);
    for (int i = 0; i < rtn.size(); ++i) 
        cout << rtn[i] << " ";

    return 0;
}
