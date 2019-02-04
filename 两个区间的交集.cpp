
#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>

/*****************************/
/*　filename: 两个区间的交集.cpp */
/*　abstract: leetcode  */
/*　author :  liuyinxin  */
/*　time:     2019-02-03 11:52:12  */
/*****************************/
/*****************************/

using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        int maxV = 1000000000, start = 0, end = 0, eS, eE;
        int arr[1000000000];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < A.size(); ++i) {
            start = A[i].start;
            end = A[i].end;
            for (int j= start; j <= end; ++j) 
                arr[j] = 1;
        } 
        vector<Interval> rtn;
        for (int i = 0; i < B.size; ++i) {
            start = B[i].start;
            end = B[i].end;
            for (int j = start; j <= end; ++j)
                if (arr[j]) {
                    eS = j;
                    while(arr[++j]);
                    eE = j - 1;

                }
            }
        
    }
};

int main(){
    return 0;
}
