# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left == right:
            return head
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        
        for i in range(left-1):
            pre = pre.next
        
        reverse = None
        cur = pre.next
        for i in range(right-left+1):
            nxt = cur.next
            cur.next = reverse
            reverse = cur
            cur = nxt
        
        pre.next.next = cur
        pre.next = reverse
        
        return dummy.next