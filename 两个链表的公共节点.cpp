
#include <iostream>
#include "utils.h"
#include <stack>

/*****************************/
/*　filename: 两个链表的公共节点.cpp */
/*　abstract: 输入两个链表，找出它们的第一个公共结点
  */
/*　author :  liuyinxin  */
/*　time:     2019-02-13 14:57:53  */
/*****************************/
/*****************************/

using namespace std;

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        // 如果有一个链表为空，则返回结果为空
        if(pHead1 == NULL || pHead2 == NULL){
            return NULL;
        }
        // 获得两个链表的长度
        unsigned int len1 = GetListLength(pHead1);
        unsigned int len2 = GetListLength(pHead2);
        // 默认 pHead1 长， pHead2短，如果不是，再更改
        ListNode* pHeadLong = pHead1;
        ListNode* pHeadShort = pHead2;
        int LengthDif = len1 - len2;
        // 如果 pHead1 比 pHead2 小
        if(len1 < len2){
            pHeadLong = pHead2;
            pHeadShort = pHead1;
            LengthDif = len2 - len1;
        }
        // 将长链表的前面部分去掉，使两个链表等长
        for(int i = 0; i < LengthDif; i++){
            pHeadLong = pHeadLong->next;
        }
        
        while(pHeadLong != NULL && pHeadShort != NULL && pHeadLong != pHeadShort){
            pHeadLong = pHeadLong->next;
            pHeadShort = pHeadShort->next;
        }
        return pHeadLong;
    }
private:
    // 获得链表长度
    unsigned int GetListLength(ListNode* pHead){
        if(pHead == NULL){
            return 0;
        }
        unsigned int length = 1;
        while(pHead->next != NULL){
            pHead = pHead->next;
            length++;
        }
        return length;
    }
};

// 利用栈的性质，从尾到头开始比较信息

int main(){
  Solution s;
  ListNode * l = new ListNode(1);
  l->next = new ListNode(2);
  l->next->next = new ListNode(3);
  l->next->next->next = new ListNode(4);

  // ListNode * l2 = new ListNode(0);
  // l2->next = l;
  cout << s.FindFirstCommonNode(l, NULL) << endl;

  cout << l;
  return 0;
}
