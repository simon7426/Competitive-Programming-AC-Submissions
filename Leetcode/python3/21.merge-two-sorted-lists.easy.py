# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        cur = None
        prev = None
        head = None
        while(list1 and list2):
            if list1.val <= list2.val:
                cur = ListNode(list1.val, None)
                list1 = list1.next
            else:
                cur = ListNode(list2.val, None)
                list2 = list2.next
            if not prev:
                head = cur
                prev = cur
            else:
                prev.next = cur
                prev = cur
        while(list1):
            cur = ListNode(list1.val, None)
            list1 = list1.next
            if not prev:
                head = cur
                prev = cur
            else:
                prev.next = cur
                prev = cur
        while(list2):
            cur = ListNode(list2.val, None)
            list2 = list2.next
            if not prev:
                head = cur
                prev = cur
            else:
                prev.next = cur
                prev = cur
        return head