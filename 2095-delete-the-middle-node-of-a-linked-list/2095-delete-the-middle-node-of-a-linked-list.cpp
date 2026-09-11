/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
         if(head == NULL || head->next == NULL)
         return NULL;

        ListNode* temp = head;
        int n = 0;
        while(temp)
        {
            n++;
            temp = temp->next;
        }

        
        int midPrev = n/2;
        temp = head;
        while(temp != NULL)
        {
            midPrev--;
            if(midPrev == 0){
                ListNode* mid = temp->next;
                temp->next = temp->next->next;
                delete mid;
            }
            temp = temp->next;
        }

        
        return head;
    }
};