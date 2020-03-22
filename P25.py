class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        cur = head
        counter = 0
        while cur and counter!= k:
            cur = cur.next
            counter += 1
        if counter == k:
            cur = self.reverseKGroup(cur, k)
            while counter:
                tmp = head.next
                head.next = cur
                cur = head
                head = tmp
                counter -= 1
            head = cur   
        return head