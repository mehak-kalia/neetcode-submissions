class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* revHead = reverse(head);

        if (n == 1) {
            // removing the very first node of the reversed list — no "previous" needed
            ListNode* newHead = revHead->next;
            return reverse(newHead);
        }

        ListNode* temp = revHead;
        int count = 1;
        while (count < n - 1) {   // walk temp to node (n-1), the one BEFORE the target
            temp = temp->next;
            count++;
        }

        temp->next = temp->next->next;   // now temp correctly sits one before the target
        return reverse(revHead);          // reverse back using the SAVED head, not the walked-off pointer
    }
};