class Solution {
public:

    ListNode* reverse(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* newHead = reverse(head->next);

        ListNode* front = head->next;

        front->next = head;
        head->next = NULL;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle
        while(fast->next != NULL && fast->next->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* newHead = reverse(slow->next);

        // Connect slow to reversed half
        slow->next = newHead;

        ListNode* first = head;
        ListNode* second = newHead;

        // Compare both halves
        while(second != NULL) {

            if(first->val != second->val) {

                slow->next = reverse(newHead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        // Restore original list
        slow->next = reverse(newHead);

        return true;
    }
};