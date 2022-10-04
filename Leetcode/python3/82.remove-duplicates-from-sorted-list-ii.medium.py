# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ans = ListNode()
        cnt = {}
        cur = head
        while(cur):
            if cur.val in cnt:
                cnt[cur.val] +=1
            else:
                cnt[cur.val] = 1
            cur = cur.next
        cur = head
        cur2 = ans
        while(cur):
            if cnt[cur.val] == 1:
                cur2.next = cur
                cur2 = cur2.next
            cur = cur.next
        cur2.next = None
        return ans.next