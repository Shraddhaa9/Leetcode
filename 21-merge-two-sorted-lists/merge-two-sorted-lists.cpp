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

// IP: Two linked list - HEADS of two LL
// OP: Head of merged LL

// IP: Integer value - ranged between -100 to 100
// Nodes in the lists in the range of [0,50]
// LL1 and LL2, both are sorted in acsending order

// we will have one dummy node, our resultant list will start from there
// we will iteratively, compare both the list's value of current node, based on that
// will update the resultant list
// if we are done with any of the list, we will simply append the rest of the list to
// resultant list

// and at the end we will return dummy node's next node, as it will have first value
// TC: O(m+n) -> m = 1st LL, n - 2nd LL
// SC: O(1) as we are not using any extra space

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode();
        ListNode *merged = dummy;

        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val) {
                merged->next = list1;
                list1 = list1->next;
            } else {
                merged->next = list2;
                list2 = list2->next;
            }

            merged = merged->next;
        }

        if (list1 == NULL) {
            merged->next = list2;
        }
        if (list2 == NULL) {
            merged->next = list1;
        }

        return dummy->next;
    }
};