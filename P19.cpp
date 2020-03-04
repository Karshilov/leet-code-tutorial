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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = new ListNode(0), *q = new ListNode(0), *header = new ListNode(0);
        header->next = head;
        p = q = header;
        for (int i = 0; i < n; i++) q = q->next;
        while (q->next != NULL) {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        //delete p, q, header;
        return header->next;
    }
};