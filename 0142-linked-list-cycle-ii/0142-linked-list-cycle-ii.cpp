/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Hashing 
        map<ListNode* , int>mpp;
        ListNode* temp = head;
        while(temp != NULL){
            mpp[temp] = 1;
            temp = temp->next;

            if(mpp.find(temp) != mpp.end()){
                return temp;
            }
        }
        return NULL;
    }
};