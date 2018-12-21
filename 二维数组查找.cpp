#include <iostream>
#include <vector>

using namespace std;

// 从[l ... r]

// 思路，利用从左到右，从上到下依次递增，可以从右上开始比较
// 如果大于，则往下，小于则往左
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& array, int target) {
        int rows = array.size(), row = 0;
        if (rows <= 0) return false;
        int col = array[0].size() -1, ret = -1;

        // [0 ... col]
        while (col >= 0 & row < rows ) {
            if (array[row][col] == target) {
                return true;
            }
            else if (array[row][col] > target)  {
                row++;
            }
            else {
                col--;
            }
        }
        return false;
    }
};

int main() {
    freopen("./testCase/二维数组查找.txt", "r", stdin);
    Solution s;
    vector<vector<int>> v;
    int c;
    for (int i = 0; i < 5; i++) {
        vector<int> vs;
        for (int j = 0; j < 5; ++j) {
            cin >> c;
            vs.push_back(c);
        }
        v.push_back(vs);
    }
    cout << endl;
    cout << s.searchMatrix(v, 19) << endl;
}

