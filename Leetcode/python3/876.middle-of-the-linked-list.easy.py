# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        length = 0
        while(cur.next):
            cur = cur.next
            length += 1
        mid = (length + 1)>>1
        cur = head
        for i in range(mid):
            cur = cur.next
        return cur