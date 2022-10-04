class Node:

    def __init__(self, s, e):

        self.s = s

        self.e = e

        self.left = None

        self.right = None



class MyCalendar:

    def __init__(self):
        self.root = None

        
    def insert(self, node: Node, s: int, e: int) -> Node:

        if not node:

            return Node(s, e)

        if e <= node.s:

            left = self.insert(node.left, s, e)

            if left is None:

                return None

            node.left = left

            return node

        elif s >= node.e:

            right = self.insert(node.right, s, e)

            if right is None:

                return None

            node.right = right

            return node

        else:

            return None
    
    def book(self, start: int, end: int) -> bool:
        ret = self.insert(self.root, start, end)

        if ret is None:

            return False

        self.root = ret

        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)