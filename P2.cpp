class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ans;
        ListNode * head;
        int add = 0;
        int init = (l1->val + l2->val);
        ans = new ListNode(init >= 10 ? init - 10 : init);
        add = init >= 10 ? 1 : 0;
        head = ans;
        while (l1->next != NULL || l2->next != NULL) {
            if (l1->next != NULL && l2->next != NULL) {
                int sum = l1->next->val + l2->next->val + add;
                if (sum >= 10) add = 1, sum -= 10;
                else add = 0;
                ans->next = new ListNode(sum);
                ans = ans->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            if (l1->next == NULL) {
                while (l2->next != NULL) {
                    int sum = l2->next->val + add;
                    if (sum >= 10) add = 1, sum -= 10;
                    else add = 0;
                    ans->next = new ListNode(sum);
                    ans = ans->next;
                    l2 = l2->next;
                }
            }
            if (l2->next == NULL) {
                while (l1->next != NULL) {
                    int sum = l1->next->val + add;
                    if (sum >= 10) add = 1, sum -= 10;
                    else add = 0;
                    ans->next = new ListNode(sum);
                    ans = ans->next;
                    l1 = l1->next;
                }
            }
        }
        if(add) ans->next = new ListNode(add);
        return head;
    }
};