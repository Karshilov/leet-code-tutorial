func arrangeCoins(n int) int {
    l, r, ans := 1, 1 << 16, 0
    for l <= r {
        mid := (l + r) >> 1
        sum := ((1 + mid) * mid) >> 1
        if sum > n { 
            r = mid - 1
        } else { 
            ans = mid; l = mid + 1
        }
    }
    return ans
}