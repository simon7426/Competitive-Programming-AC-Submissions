class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x:x[1])
        queue = []
        start = 0
        for course in courses:
            start+=course[0]
            heapq.heappush(queue, -course[0])
            while start > course[1]:
                tmp = heapq.heappop(queue)
                start -= (-tmp)
        return len(queue)