/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *header = head->next;
        ListNode *cur = new ListNode(0);
        while (head != NULL) {
            if (head->next == NULL) break;
            if (cur->next != NULL) cur->next = head->next;
            ListNode *tmp = head->next;
            head->next = head->next->next;
            tmp->next = head;
            cur = head;
            head = head->next;
        }
        return header;
    }
};