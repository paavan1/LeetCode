#include<stdlib.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};



    ListNode *reverseBetween(ListNode *head, int m, int n) {

        if( n - m <= 0) return head;

        ListNode* virtualHead = new ListNode(0);

        virtualHead->next = head;

        ListNode* prev = virtualHead;

        for(int i = 0; i < m - 1; i++) prev = prev->next;

        ListNode *temp = NULL, *p = NULL, *q = NULL;

        q = prev->next;

        p = prev->next->next;

        //reverse
        for(int i = 0; i < n - m; i++){
           temp = p->next;
           p->next = q;
           q = p;
           p = temp;
        }

        temp = prev->next;
        prev->next = q;
        temp->next = p;

        return virtualHead->next;
    }
