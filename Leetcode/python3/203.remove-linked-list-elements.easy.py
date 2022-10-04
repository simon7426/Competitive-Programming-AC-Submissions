# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        prev = None
        while(head and head.val == val):
            head=head.next
        if not head:
            return head
        cur = head
        while(cur):
            if cur.val != val:
                if prev:
                    prev.next = cur
                prev = cur
            cur = cur.next
        prev.next = cur
        return head