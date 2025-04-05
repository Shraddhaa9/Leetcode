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

// reverse a linked list
// take first node from first list and 1st node from reversed list
// append both and keep traversing
// till mid node reached
// if required can have mid pointer stored as well somewhere

class Solution {
private:
    ListNode *findMiddle(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr and fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* revList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        ListNode *curr = head;
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void printL(ListNode *head) {
        ListNode *curr = head;
        while(curr != nullptr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
public:
    void reorderList(ListNode* head) {
        ListNode *mid = findMiddle(head);
        ListNode *newL = revList(mid->next);
        mid->next = NULL;

        ListNode *curr = head;
        while(newL != nullptr and curr != nullptr) {
            ListNode *l1next = curr->next;
            ListNode *l2next = newL->next;
            curr->next = newL;
            newL->next = l1next;
            curr = l1next;
            newL = l2next;
        }

        return;
    }
};