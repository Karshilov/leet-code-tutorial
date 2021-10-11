import (
    "sort"
)

func thirdMax(nums []int) int {
    sort.Ints(nums)
    for i, j := 0, len(nums) - 1; i < j; i, j = i + 1, j - 1 {
        nums[i], nums[j] = nums[j], nums[i]
    }
    cnt := 0
    for i, v := range nums {
        if i == 0 || v != nums[i - 1] {
            cnt++;
            if (cnt == 3) {
                return v
            }
        }
    }
    return nums[0]
}