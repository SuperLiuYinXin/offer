
#include <iostream>
#include "utils.h"

/*****************************/
/*　filename: 链表中环的入口结点.cpp */
/*　abstract: 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。  */
/*　author :  liuyinxin  */
/*　time:     2019-02-19 11:56:11  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == nullptr || pHead->next == nullptr || pHead->next->next == nullptr) {
            return nullptr;
        }
        bool isLoop = false;
        ListNode * lHead = pHead, * fHead = pHead;
        while (fHead != nullptr) {
            // cout <<  "visit:"<< lHead->val << " " << fHead->val << endl;
            lHead = lHead->next;
            if (fHead->next != NULL) 
                fHead = fHead->next->next;
            else 
                return nullptr;
            if (lHead == fHead) {
                isLoop = true;
                break;
            }
        }
        // cout <<  "相遇:"<< lHead->val << " " << fHead->val << endl;
        if (!isLoop) {
            return nullptr;
        }
        lHead = pHead;
        while (lHead != fHead) {
            // cout << lHead->val << " " << fHead->val << endl;
            lHead = lHead->next;
            fHead = fHead->next;
        }
        return lHead;
    }
};

int main(){

    ListNode * l, * l1;
    l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);
    l->next->next->next->next->next = l->next->next;
    Solution s;
    cout << s.EntryNodeOfLoop(l)->val << endl;
    return 0;
}
