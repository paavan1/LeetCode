#include<stdlib.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


    ListNode *removeNthFromEnd(ListNode *head, int n) {


    	        ListNode *dummy = new ListNode(0);

    	        dummy->next = head;

    	        ListNode* p = dummy, *prev = dummy;

    	        for(int i = 0; i < n; i++) p = p->next;

    	        while(p->next){
    	            p = p->next;
    	            prev = prev->next;
    	        }

    	        prev->next = prev->next->next;

    	        return dummy->next;

    }
