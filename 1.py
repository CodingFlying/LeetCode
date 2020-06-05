class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for x in range(n):
            for y in range(x + 1, n):
                if nums[x] + nums[y] == target:
                    return x, y
                    break
                else:
                    continue