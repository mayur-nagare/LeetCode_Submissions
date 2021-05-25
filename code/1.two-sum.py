class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        output = {}
        for i in range(len(nums)):
            if target - nums[i] in output:
                return([output[target - nums[i]], i])
            else:
                output[nums[i]]=i