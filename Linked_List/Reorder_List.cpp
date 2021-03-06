#include<stdlib.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* head)
    {

        ListNode* cur = head, *prev = NULL, *temp = NULL;

        while(cur)
        {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }

    void reorderList(ListNode *head) {

        if(head == NULL || head->next == NULL) return;

        //find the middle node

        ListNode* slow = head, *fast = head->next;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* mid = fast == NULL ? slow : slow->next;

        // reverse the second half
        ListNode* second = reverse(mid->next);
        mid->next = NULL;
        ListNode* first = head;

        ListNode* temp = NULL;

        //merge two sublists
        while(second)
        {
            temp = first->next;
            first->next = second;
            first = temp;

            temp = second->next;
            second->next = first;
            second = temp;
        }
    }
