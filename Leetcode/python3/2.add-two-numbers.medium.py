# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        in_hand = 0
        cur1 = l1
        cur2 = l2
        ret_head = None
        while(cur1 and cur2):
            val = cur1.val + cur2.val + in_hand
            if val>9:
                val-=10
                in_hand = 1
            else:
                in_hand = 0
            newNode = ListNode(val, None)
            if not ret_head:
                ret = newNode
                ret_head = ret
            else:
                ret.next = newNode
                ret = ret.next
            cur1 = cur1.next
            cur2 = cur2.next
        while(cur1):
            val = cur1.val + in_hand
            if val>9:
                val-=10
                in_hand = 1
            else:
                in_hand = 0
            newNode = ListNode(val, None)
            if not ret_head:
                ret = newNode
                ret_head = ret
            else:
                ret.next = newNode
                ret = ret.next
            cur1 = cur1.next
        while(cur2):
            val = cur2.val + in_hand
            if val>9:
                val-=10
                in_hand = 1
            else:
                in_hand = 0
            newNode = ListNode(val, None)
            if not ret_head:
                ret = newNode
                ret_head = ret
            else:
                ret.next = newNode
                ret = ret.next
            cur2 = cur2.next
        if in_hand:
            newNode = ListNode(1, None)
            if not ret_head:
                ret = newNode
                ret_head = ret
            else:
                ret.next = newNode
                ret = ret.next
        return ret_head