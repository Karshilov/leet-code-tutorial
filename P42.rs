impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        if height.len() == 0 { return 0; }
        let mut ans = 0;
        let mut l = 0;
        let mut r = height.len() - 1;
        let mut lx = 0;
        let mut rx = 0;
        loop {
            if l == r { break; }
            lx = if height[l] > lx { height[l] } else { lx };
            rx = if height[r] > rx { height[r] } else { rx };
            if lx < rx {
                ans += lx - height[l];
                l = l + 1;
            } else {
                ans += rx - height[r];
                r = r - 1;
            }
        }
        ans
    }
}