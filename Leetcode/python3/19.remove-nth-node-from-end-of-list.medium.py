# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        length = 0
        cur = head
        while(cur!=None):
            length+=1
            cur = cur.next
        to_be_removed = length-n+1
        cur = head
        if to_be_removed==1:
            return head.next
        for i in range(1,to_be_removed-1):
            cur = cur.next
        if cur.next.next!=None:
            cur.next = cur.next.next
        else:
            cur.next = None
        return head