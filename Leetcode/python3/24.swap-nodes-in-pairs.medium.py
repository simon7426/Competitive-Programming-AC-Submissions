# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        tmp = ListNode(0)
        top = tmp
        tmp.next = head
        while (tmp.next and tmp.next.next):
            first = tmp.next
            second = tmp.next.next
            first.next = second.next
            second.next = first
            tmp.next = second
            tmp = tmp.next.next
        return top.next
        