class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // Edge case
        if (head == NULL || head->next == NULL)
            return head;

        vector<int> arr;

        // Store odd-positioned nodes
        ListNode* temp = head;

        while (temp != NULL) {
            arr.push_back(temp->val);

            if (temp->next == NULL)
                break;

            temp = temp->next->next;
        }

        // Store even-positioned nodes
        temp = head->next;

        while (temp != NULL) {
            arr.push_back(temp->val);

            if (temp->next == NULL)
                break;

            temp = temp->next->next;
        }

        // Put values back into linked list
        int i = 0;
        temp = head;

        while (temp != NULL) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};