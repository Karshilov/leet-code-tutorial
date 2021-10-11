func twoOutOfThree(nums1 []int, nums2 []int, nums3 []int) []int {
    cnt := make(map[int]int)
    for _, v := range nums1 {
        if cnt[v] == 0 {
            cnt[v]++
        }
    }
    for _, v := range nums2 {
        if cnt[v] < 2 {
            cnt[v] += 2
        }
    }
    for _, v := range nums3 {
        if cnt[v] < 4 {
            cnt[v] += 4
        }
    }
    var ans []int
    for k, v := range cnt {
        if v != 1 && v != 2 && v != 4 {
            ans = append(ans, k)
        }
    }
    return ans
}