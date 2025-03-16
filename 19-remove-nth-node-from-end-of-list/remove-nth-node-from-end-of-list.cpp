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

// Brute force:
// we will count the length of the list - 1st pass
// we will find the number of node to be removed, based on length
// we will remove the node - 2nd pass
// TC: O(n^2) - as two passes
// SC: O(1) - no extra space used

// edge case - 
// only one node in list
// remove one and only node from the list
// remove node from the list
// last node from the list

// OPTIMAL APPROACH - two pointer approach:
// we will initialize a left pointer at start and right pointer n steps ahead
// and will shoft towards ends one step at a time
// once right pointer reaches end of list, left pointer will be at the position
// which node we want to delete, as it will always have gap of n nodes with right ptr
// BUT, we want to delete the nth node, so instead of starting left pointer at head
// we need to have one dummy node, which next will be head, so once we reach previous
// node whose next shall be deleted, we can delete it easily

// TC: O(n) - as we traversing only once
// SC: O(1) - as we are not using any extra spaces

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *left = &dummy;
        ListNode *right = head;
        while(n > 0)
        {
            right = right->next;
            n--;
        }
        
        while(right != NULL)
        {
            left = left->next;
            right = right->next;
        }

        ListNode *nodeToBeDeleted = left->next;
        left->next = left->next->next;
        delete nodeToBeDeleted;

        return dummy.next;
    }

#if 0
        ListNode dummy;
        dummy.next = head;
        ListNode *temp = &dummy;
        int count = 0;

        ListNode* curr = head;
        while(curr != NULL)
        {
            count = count + 1;
            curr = curr->next;
        }

        // previous node of the node to be removed, we want to remove 4th in 1st case,
        // but we will get 3 from this and this will be pointing to the node to be removed
        int nodeToBeRemoved = count - n;
        int currNode = 0;
        while(currNode < nodeToBeRemoved)
        {
            currNode = currNode + 1;
            temp = temp->next;
        }

        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        return dummy.next;
    }
#endif
};