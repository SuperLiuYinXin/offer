
#include <iostream>
#include "utils.h"
/*****************************/
/*　filename: 复杂链表的复制.cpp */
/*　abstract: 输入一个复杂链表
（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空)  */
/*　author :  liuyinxin  */
/*　time:     2019-01-27 15:37:28  */
/*****************************/
/*****************************/

using namespace std;
/**
 * 思路:
 * 根据剑指offer提供的解法，我们可以直接在原来的链表上拷贝一份，
 * 这样random所指的就是他所指的下一个
 * 再把结点偶数个树链接起来即可
 *
 * */

class Solution {
  public:
    // Leetcode
    RandomListNode *copyRandomList(RandomListNode *head)
    {

        if (!head)
            return head;

        // 复制
        RandomListNode *nHead = head, *cpHead, *rtnHead;
        while (nHead)
        {

            cpHead = new RandomListNode(nHead->label);

            cpHead->next = nHead->next;
            nHead->next = cpHead;
            nHead = nHead->next->next;
        }

        nHead = head;

        while (nHead)
        {

            if (nHead->random)
            {

                nHead->next->random = nHead->random->next;
            }
            // 跳过复制的
            nHead = nHead->next->next;
        }

        // 剪切分开
        nHead = head;
        rtnHead = new RandomListNode(0);

        cpHead = rtnHead;
        
        while (nHead) { 
            cpHead->next = nHead->next;
            nHead->next = nHead->next->next;
            nHead = nHead->next;
            cpHead = cpHead->next;
        }
        cpHead = rtnHead;
        rtnHead = rtnHead->next;

        delete cpHead;

        return rtnHead;
    }

    // 牛客
    RandomListNode* Clone(RandomListNode* pHead) {
        return copyRandomList(pHead);
        
    }
};

int main()
{

    Solution s;
    RandomListNode *r = new RandomListNode(1);
    r->next = new RandomListNode(2);
    r->next->next = new RandomListNode(3);
    r->next->next->next = new RandomListNode(4);
    r->next->next->next->next = new RandomListNode(5);

    r->random = r->next->next;
    r->next->random = r->next->next->next->next;
    r->next->next->next->random = r->next;

    RandomListNode *rt = s.copyRandomList(r);

    while (rt)
    {

        cout << rt->label << " ";
        if (rt->random)

            cout << rt->random->label;

        cout << endl;
        rt = rt->next;
    }
    return 0;
}
