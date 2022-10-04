class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        tasks_cnt = [val for val in Counter(tasks).values()]
        tasks_cnt.sort()
        divisions = tasks_cnt.pop()-1
        free_slots = divisions * n
        while tasks_cnt and free_slots > 0:
            free_slots -= min(divisions, tasks_cnt.pop())
        return max(0, free_slots)+len(tasks)