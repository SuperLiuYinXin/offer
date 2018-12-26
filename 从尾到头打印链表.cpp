#include <iostream>
#include <vector>

using namespace std;


/**
 * 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

/**
 * 就是反转链表
 */
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode * pre = NULL, * tmp;
        vector<int> v;
        if (head==NULL) 
            return v;
        while (1) {
            tmp = head -> next;
            head->next = pre;
            pre = head;
            if (tmp == NULL) 
                break;
            head = tmp;
        }
        tmp = head;
        while(tmp!=NULL) {
            v.push_back(tmp->val);
            tmp = tmp->next;
        }
        return v;
    }
};

int main() {
    Solution s;
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    vector<int> v = s.printListFromTailToHead(head);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
}