class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sorted = NULL;

        while (head != NULL) {
            ListNode* current = head;
            head = head->next;

            if (sorted == NULL || current->val < sorted->val) {
                current->next = sorted;
                sorted = current;
            }
            else {
                ListNode* temp = sorted;

                while (temp->next != NULL && temp->next->val < current->val) {
                    temp = temp->next;
                }

                current->next = temp->next;
                temp->next = current;
            }
        }

        return sorted;
    }
};