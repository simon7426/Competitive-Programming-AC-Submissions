# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        prev = cur
        while(cur):
            while(cur.next and cur.next.val == cur.val):
                cur = cur.next
            prev.next = cur.next
            prev=cur.next
            if cur:
                cur = cur.next
        return head