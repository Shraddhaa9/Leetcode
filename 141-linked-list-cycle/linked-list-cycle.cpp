/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// IP: head (of a singly linked list)
// OP: True/False - based on cycle or not

// two pointer approach
// fast pointer - will move ahead two nodes at a time
// slow pointer will move one node at a time
// if at any point, fast and slow meets each other, then we can safely say that
// linked list has a cycle

// edge case:
// single node
// two nodes with cycle

// QUESTIONS:
// Does this Linked List always have integer values in it?
// YES, but can have negative values as well

// Linked list length - [0,10^4]
// Node values can be negative as well
// Pos is not known, but if it's -1 then there are no cycles

// TC: O(N) - as we are traversing a list
// SC: O(1) - as we are not using any extra space

// If we would have been using hashmap approach, like we keep noting the nodes that have been
// visited once and then if we find that we have reached node twice, then we can simply
// say that there is a cycle in the list
// For this approach:
// TC: O(N) - as we are traversing a list
// SC: O(N) - as we are using extra hashmap to store all traversed nodes

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};