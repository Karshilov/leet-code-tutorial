import (
    "sort"
    "math"
)

func minOperations(grid [][]int, x int) int {
    base := grid[0][0]
    var sub []int
    for _, v := range grid {
        for _, e := range v {
            sub = append(sub, e - base)
            if (e - base) % x != 0 {
                return -1
            }
        }
    }
    sort.Ints(sub)
    n := len(sub)
    if n % 2 != 0 {
        ans := 0
        for i := range sub {
            ans += int(math.Abs(float64((sub[n >> 1] - sub[i]) / x)))
        }
        return ans
    } else {
        ans := 0
        res := 0
        for i := range sub {
            ans += int(math.Abs(float64((sub[n >> 1] - sub[i]) / x)))
            res += int(math.Abs(float64((sub[(n >> 1) - 1] - sub[i]) / x)))
        }
        if ans > res {
            return res
        } else {
            return ans
        }
    }
}