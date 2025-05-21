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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ptr = head;
        ListNode *ktail = nullptr;
        ListNode *newHead = nullptr;

        while(ptr != nullptr) {
            int count = 0;
            ListNode *khead = ptr;
            while(count < k && ptr != nullptr) {
                ptr = ptr->next;
                count++;
            }

            if (count == k) {
                ListNode *revHead = reverseLinkedList(khead, k);

                if (newHead == nullptr) {
                    newHead = revHead;
                }

                if (ktail != nullptr) {
                    ktail->next = revHead;
                }

                ktail = khead;
            } else {
                if (ktail != nullptr) {
                    ktail->next = khead;
                }
            }
        }

        return newHead == nullptr ? head : newHead;
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