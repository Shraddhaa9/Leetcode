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
private:
    ListNode* reverseLinkedList(ListNode *head, int k) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while(k > 0) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }

        return prev;
    }

#if 1
public:
// newHead - resultant reversed list's head node
// ktail - previous k node's tail node (already reversed)
// khead - k node's head (to be reversed)
// revHead - reverse list's head for k nodes
// ptr - to skip k nodes every time
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode *ptr = head;
        ListNode *ktail = nullptr;
        ListNode *newHead = nullptr;

        while(ptr != nullptr) {
            int count = 0;
            // this ptr always points to k-skipped node's head
            ListNode *khead = ptr;

            // Check if there are k nodes left
            while(count < k && ptr != nullptr) {
                ptr = ptr->next;
                count++;
            }

            if (count == k) {
                // Reverse k nodes
                ListNode *revHead = reverseLinkedList(khead, k);

                // New head for the result list
                if (newHead == nullptr) {
                    newHead = revHead;
                }

                // Connect with previous part
                if (ktail != nullptr) {
                    ktail->next = revHead;
                }

                // ktail becomes the end of this reversed segment
                ktail = khead;
                // Move head to the next group
            } else {
                // Less than k nodes left, do not reverse
                if (ktail != nullptr) {
                    ktail->next = khead;
                }
            }
        }

        return newHead;
    }
#else
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode *ptr = head;

        while (count < k && ptr != nullptr) {
            ptr = ptr->next;
            count++;
        }

        if (count == k) {
            ListNode *reverseHead = this->reverseLinkedList(head, k);
            head->next = this->reverseKGroup(ptr, k);
            return reverseHead;
        }

        return head;   
    }
#endif
};