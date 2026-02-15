/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If the list is empty or has only one node, no swaps needed
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            // Identify the two nodes to swap
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Actual Swapping Logic
            first->next = second->next; // 1. First points to the rest of the list
            second->next = first;       // 2. Second points back to First
            prev->next = second;        // 3. Prev points to Second

            // Move the pointer forward by two nodes for the next pair
            prev = first;
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up memory
        return newHead;
    }
};