class Solution {
public:
    ListNode* findNthNode(ListNode* temp, int k) {
        int cnt = 1;

        while (temp != NULL) {

            if (cnt == k)
                return temp;

            cnt++;
            temp = temp->next;
        }

        return NULL;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // Find length and tail
        int len = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        // If k is greater than length
        k = k % len;

        tail->next = head;

        // Find the new last node which points to NULL
        int cnt = len - k;
        ListNode* newLastNode = findNthNode(head, cnt);

        ListNode* newHead = newLastNode->next;

        newLastNode->next = NULL;

        return newHead;
    }
};