# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        cur = head
        length = 0
        if (not head.next):
            return True
        while(cur):
            length+=1
            cur = cur.next
        mid_length = (length+1)>>1
        mid = head
        for i in range(mid_length):
            mid = mid.next
        mid_tmp = mid
        prev = None
        while(mid_tmp):
            next_node = mid_tmp.next
            mid_tmp.next=prev
            prev = mid_tmp
            mid_tmp = next_node
        cur = head
        mid = prev
        while(mid):
            if (cur.val != mid.val):
                return False
            cur = cur.next
            mid = mid.next
        return True