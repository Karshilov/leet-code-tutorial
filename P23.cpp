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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() <= 0) return NULL;
        priority_queue<int, vector<int>, greater<int> > q;
        for (auto h : lists) {
            while (h != NULL) {
                q.push(h->val);
                h = h->next;
            }
        }
        if (q.empty()) return NULL;
        ListNode *head = new ListNode(q.top());
        ListNode *ans = head;
        q.pop();
        while (!q.empty()) {
            head->next = new ListNode(q.top());
            head = head->next;
            q.pop();
        }
        return ans;
    }
};