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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;

        if (head == NULL || head->next == NULL)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;

        int idx = 1;

        while (curr != NULL && curr->next != NULL) {
            int left = prev->val;
            int val = curr->val;
            int right = curr->next->val;

            if ((val > left && val > right) ||
                (val < left && val < right)) {
                critical.push_back(idx);
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (critical.size() < 2)
            return {-1, -1};

        int mini = INT_MAX;

        for (int i = 1; i < critical.size(); i++) {
            mini = min(mini, critical[i] - critical[i - 1]);
        }

        int maxi = critical.back() - critical.front();

        return {mini, maxi};
    }
};