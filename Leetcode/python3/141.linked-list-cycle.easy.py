# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        cur = head
        if (head):
            while(cur.next):
                if (not cur.val):
                    return True
                cur.val=None
                cur = cur.next
        return False