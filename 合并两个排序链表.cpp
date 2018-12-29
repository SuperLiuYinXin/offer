
#include <iostream>

/*****************************/
/*　filename: 合并两个排序链表.cpp */
/*　abstract: 输入两个单调递增的链表，
            输出两个链表合成后的链表，
            当然我们需要合成后的链表满足单调不减规则。*/
/*　author :  liuyinxin  */
/*　time:     2018-12-29 23:09:23  */
/*****************************/
/*****************************/

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode * head = NULL, * rtn;
        if (pHead1 == NULL) 

            return pHead2;
        else if (pHead2 == NULL) 
            
            return pHead1;

        if (pHead1->val < pHead2->val) {

            head = pHead1;
            pHead1 = pHead1->next;
        } else  {

            head = pHead2;
            pHead2 = pHead2->next;
        }

        rtn = head;

        while (pHead1 != NULL && pHead2 != NULL) {

            if (pHead1->val < pHead2->val) {

                head->next = pHead1;
                head = head->next;
                pHead1 = pHead1->next;

            } else  {

                head->next = pHead2;
                head = head ->next;
                pHead2 = pHead2->next;

            }
        }
        while (pHead1 != NULL) {
            head->next = pHead1;
            pHead1 = pHead1 ->next;
            head = head->next;
        }

        while (pHead2 != NULL) {
            head->next = pHead2;
            pHead2 = pHead2 ->next;
            head = head->next;
        }
        return rtn;
    }
};

int main(){

    Solution s;
    ListNode * v1, * v2;
    
    v1 = new ListNode(1);
    v1->next = new ListNode(3);
    v1->next->next = new ListNode(5);
    v1->next->next->next = new ListNode(7);

    v2 = new ListNode(2);
    v2->next = new ListNode(4);
    v2->next->next = new ListNode(6);
    v2->next->next->next = new ListNode(8);

    

    ListNode * p =  s.Merge(v1, v2);
    while(p!=NULL) {

        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}
