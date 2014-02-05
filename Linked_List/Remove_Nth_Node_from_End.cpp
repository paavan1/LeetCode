#include<stdlib.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


    ListNode *removeNthFromEnd(ListNode *head, int n) {

        ListNode* dummy = new ListNode(0);

        dummy->next = head;

        ListNode* first = head, *second  = head, *prev = dummy;

        for(int i = 0; i < n; i++) first = first->next;

        while(first){
            first = first->next;
            prev = second;
            second = second->next;
        }

        prev->next = second->next;

        return dummy->next;
    }
