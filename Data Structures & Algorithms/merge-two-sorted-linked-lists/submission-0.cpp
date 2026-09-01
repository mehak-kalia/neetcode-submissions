class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;   // tail walks forward; dummy stays fixed

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;   // <- the missing piece: advance tail
        }

        // attach whichever list has leftover nodes (already sorted)
        tail->next = (list1 != nullptr) ? list1 : list2;

        return dummy->next;
    }
};