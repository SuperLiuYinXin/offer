
#include <iostream>
#include <vector>

/*****************************/
/*　filename: 顺时针打印矩阵.cpp */
/*　abstract: 顺时针打印矩阵  */
/*　author :  liuyinxin  */
/*　time:     2018-12-31 01:13:10  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int m, n, count, cur = 0, sum;
        vector<int> rtn;

        n = matrix.size();
        if (n <= 0)
            return rtn;

        m = matrix[0].size();
        if (m <= 0) {
            return rtn;
        }

        if (n == 1) {
            return matrix[0];
        }  else if (m == 1) {
            for (int i = 0; i < n; ++i) 
                rtn.push_back(matrix[i][0]);
            return rtn;
        }
        sum = n * m;

        count = min((n + 1) / 2, (m + 1) / 2);
        n--, m--;
        // cout << "n " << n << " m " << m <<  " count " << count << endl;
        for (int i = 0; i < count; ++i) {

            for (int j = i; j <= m - i - 1 && cur < sum; ++j, cur++) {
                // cout << matrix[i][j] << endl;
                rtn.push_back(matrix[i][j]);
            }

            for (int j = i; j <= n - i && cur < sum; ++j, cur++) {
                // cout << matrix[j][m -i] << endl;
                rtn.push_back(matrix[j][m - i]);
            }

            for (int j = m - i - 1; j >= i && cur < sum; --j, cur++) {
                // cout << matrix[n - i][j] << endl;
                rtn.push_back(matrix[n - i][j]);
            }

            for (int j = n - i - 1; j >= i + 1 && cur < sum; --j, cur++) {
                // cout << matrix[j][i] << endl;
                rtn.push_back(matrix[j][i]);
            }
        }
        return rtn;
    }
};

int main(){

    Solution s;
    int m , n, num;
    freopen("./testCase/顺时针打印矩阵.txt", "r", stdin);
    cin >> n >> m;
    vector<vector <int >> matrix;

    for (int i = 0; i < n; ++i) {
        vector<int> v;
        for (int j = 0; j < m; ++j) {
            cin >>  num;
            v.push_back(num);
        }
        matrix.push_back(v);
    }
    vector<int> r = s.printMatrix(matrix);
    for (int i = 0; i < r.size(); ++i) {

        cout << r[i] << " ";
    }
    return 0;
}
