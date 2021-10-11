import "math"

func findDuplicates(nums []int) []int {
    var ans []int
    for _, v := range nums {
        e := int(math.Abs(float64(v))) - 1
        if nums[e] < 0 {
            ans = append(ans, e + 1)
        } else {
            nums[e] = -nums[e]
        }
    }
    return ans
}