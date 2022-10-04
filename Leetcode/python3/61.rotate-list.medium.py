# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next: 

            return head

        

        tail = head

        n = 1

        while head.next :

            head = head.next

            n += 1

        head.next = tail

        head = head.next

        

        for i in range(n - k % n - 1):

            head = head.next

        res = head.next

        head.next = None

        return res