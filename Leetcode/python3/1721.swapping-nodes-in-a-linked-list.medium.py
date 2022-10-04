# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        first = head
        for i in range(k-1):
            first = first.next
        tmp = first
        second = head
        while first.next:
            first = first.next
            second = second.next
        tmp.val, second.val = second.val, tmp.val
        return head