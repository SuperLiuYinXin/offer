
#include <iostream>
#include "utils.h"

/*****************************/
/*　filename: 删除链表中重复的结点.cpp */
/*　abstract: 
在一个排序的链表中，存在重复的结点，
请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
/*　author :  liuyinxin  */
/*　time:     2019-02-19 14:33:51  */
/*****************************/
/*****************************/



using namespace std;


class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL) {
            return pHead;
        }
        ListNode * cur = pHead, * pre = new ListNode(0), *next = pHead->next, * rtnPre, *tmp;
        rtnPre = pre;
        pre->next = pHead;
        while (next != NULL) {
            while (next != NULL && cur->val == next->val) {
                next = next->next;
            }
            // 如果cur的next 不为next, 这说明　cur和next不相符,中间有重复元素，删除cur
            if (cur->next != next) {
                while (cur != next) {
                    tmp = cur;
                    cur = cur->next;
                    delete tmp;
                }
                pre->next = next;
                if (next != NULL)
                    next = next->next;
            //  如果不重复的话
            } else {
                pre->next = cur;
                pre =pre->next;
                next = next->next;
                cur = cur->next;
            }
        }
        tmp = rtnPre;
        rtnPre = rtnPre->next;
        delete tmp;

        return rtnPre;
    }
};

int main(){
    Solution s;
    ListNode * l;
    l = new ListNode(1);
    l->next = new ListNode(1);
    l->next->next = new ListNode(1);
    // l->next->next->next = new ListNode(1);
    // l->next->next->next->next = new ListNode(1);
    // l->next->next->next->next->next = new ListNode(4);
    // l->next->next->next->next->next->next = new ListNode(5);

    l = s.deleteDuplication(l);
    while (l != NULL) {
        cout << l->val << " ";
        l = l->next;
    }
    return 0;
}
