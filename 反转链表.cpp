
#include <iostream>

/*****************************/
/*　filename: 反转链表.cpp */
/*　abstract: 反转链表  */
/*　author :  liuyinxin  */
/*　time:     2018-12-29 22:43:34  */
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
    ListNode* ReverseList(ListNode* pHead) {

        ListNode * pre = NULL, * tmp = NULL;
        if (pHead == NULL) {
            return pHead;
        }

        while (1) {


            tmp = pHead->next;


            pHead->next = pre;
            pre = pHead;

            if (tmp == NULL) 
                break;
            pHead = tmp;

        }
        return pre;
    }
};

int main(){

    Solution s;

    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode * p =  s.ReverseList(head);
    while(p!=NULL) {

        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}
