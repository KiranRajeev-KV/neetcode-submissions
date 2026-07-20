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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* a = list1; ListNode* b = list2;
        ListNode dummy(0);
        ListNode* head = &dummy;

        while(a && b) {
            if (a->val <= b->val) {
                head->next = a;
                a = a->next;
            } else {
                head->next = b;
                b = b->next;
            }
            head = head->next;
        }

        if (a) {
            head->next = a;
        } else {
            head->next = b;
        }
        return dummy.next;
    }
};
