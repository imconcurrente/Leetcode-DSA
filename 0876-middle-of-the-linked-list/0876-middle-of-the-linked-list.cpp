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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0; // count the no. of nodes
        while(temp != NULL){
            cnt = cnt+1;
            temp = temp->next;
        }

        int midNode = (cnt/2) + 1;  // middle node
        ListNode* temp1 = head;
        while(temp1 != NULL){
            midNode = midNode-1;
            if(midNode == 0){
                break;
            }
            temp1 = temp1->next;
        }
        return temp1;
    }
};