class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        test_rounds = minutesToTest//minutesToDie+1
        if test_rounds == 1:
            return 0  # unable to test
        else:
            return int(math.ceil(math.log(buckets, test_rounds)))