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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        while (curr) {
            ListNode* start = curr->next;
            int sum = 0;
            while (start) {
                sum += start->val;
                if (sum == 0) {
                    curr->next = start->next;
                    break;
                }
                start = start->next;
            }
            if (!start) curr = curr->next;
        }
        return dummy->next;
    }
};



/*
    Time complexity: O(n^2)
    Space complexity: O(1)
*/    
