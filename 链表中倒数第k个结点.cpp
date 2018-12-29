
#include <iostream>

/*****************************/
/*　filename: 链表中倒数第k个结点.cpp */
/*　abstract: 求链接中第倒数k个结点  */
/*　author :  liuyinxin  */
/*　time:     2018-12-29 22:13:58  */
/*****************************/
/*****************************/

using namespace std;

// 用快慢指针
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode * head = pListHead, * nextHead = pListHead;


        while (k && head!=NULL) {
            --k;
            
            head = head->next;

        }

        if (k > 0) {

            nextHead = NULL;

        }


        while (head != NULL){
            head = head->next;
            nextHead = nextHead->next;

        }

    
        return nextHead;
    }
};

int main(){
    Solution s;
    ListNode * l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);

    cout << s.FindKthToTail(l, 5)->val << endl;

    return 0;
}
