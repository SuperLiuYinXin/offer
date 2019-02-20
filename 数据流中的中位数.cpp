#include <iostream>
#include <queue>

/*****************************/
/*　filename: 数据流中的中位数.cpp */
/*　abstract: 
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。  */
/*　author :  liuyinxin  */
/*　time:     2019-02-20 17:26:43  */
/*****************************/
/*****************************/
using namespace std;

// 思路
// 维护一个最大最和最小堆
// 大于的放在一个队，小于的放在一个堆
class Solution {
private:
        // 数据类型 底层容器 比较函数
    priority_queue<int, vector<int>, less<int>> p; 
    priority_queue<int, vector<int>, greater<int>> q;
public:

    /**
     * 如果小堆为空,
     * 最小堆放的是中位数后面的
     * 最大堆放的是中位数前面的
     */
    void Insert(int num)
    {
        if (p.empty() || num <= p.top()) 
            p.push(num);
        else 
            q.push(num);
        // 这样保证p 比q只可能多一个
        if (p.size() == q.size() + 2) {
            // 把最小的放入最大堆中
            q.push(p.top());
            p.pop();
        }
        // 这样就相等了
       if (p.size() + 1 == q.size()) {
            p.push(q.top());
            q.pop();
        }
    }

    double GetMedian()
    { 
        return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
    
    }

};

using namespace std;

int main(){
    return 0;
}
