# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        if not head or not head.next: return head
        dummy_head = prv = ListNode("inf")
        prv.next = head
        while head and head.next:
            if head.val >= x and head.next.val<x:
                temp = head.next.next
                head.next.next = prv.next
                prv.next = head.next
                head.next = temp
            else:
                head = head.next
            if prv.next.val < x:
                prv=prv.next
        return dummy_head.next