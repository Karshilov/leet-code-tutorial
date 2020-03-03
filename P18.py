class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        if not nums or len(nums) < 4:
            return result
        nums.sort()
        length = len(nums)
        for k in range(length - 3):
            if k > 0 and nums[k] == nums[k - 1]:
                continue
            sumk = nums[k] + nums[k + 1] + nums[k + 2] + nums[k + 3]
            if sumk > target:
                break
            suml = nums[k] + nums [length-1] + nums[length - 2] + nums[length - 3]
            if suml < target:
                continue
            for i in range(k + 1, length - 2):
                if i > k + 1 and nums[i] == nums[i - 1]:
                    continue
                j = i + 1
                h = length - 1
                sumj = nums[k] + nums[i] + nums[j] + nums[j + 1]
                if sumj > target:
                    continue
                sumh = nums[k] + nums[i] + nums[h] + nums[h - 1]
                if sumh < target:
                    continue
                while j < h:
                    cur = nums[k] + nums[i] + nums[j] + nums[h]
                    if cur == target:
                        result.append([nums[k], nums[i], nums[j], nums[h]])
                        j += 1
                        while j < h and nums[j] == nums[j - 1]:
                            j += 1
                        h -= 1
                        while j < h and i < h and nums[h] == nums[h + 1]:
                            h -= 1
                    elif cur > target:
                        h -= 1
                    elif cur < target:
                        j += 1
        return result