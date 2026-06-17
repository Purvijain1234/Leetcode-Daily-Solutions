/*
Problem Number: 2095
Problem Name: Delete the Middle Node of a Linked List

LeetCode Link:
https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

Difficulty: Medium

Topics:
Linked List, Two Pointers

Approach:
1. If there is only one node,
   return nullptr.

2. Use Slow and Fast pointers
   to find the middle node.

3. Maintain a previous pointer
   to the node before slow.

4. Delete the middle node by:
      prev->next = slow->next

5. Return head.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:

    ListNode* deleteMiddle(ListNode* head) {

        // Single node case
        if(head == nullptr ||
           head->next == nullptr) {

            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Find middle node
        while(fast && fast->next) {

            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete middle node
        prev->next = slow->next;

        delete slow;

        return head;
    }
};
