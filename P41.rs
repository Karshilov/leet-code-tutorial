impl Solution {
    pub fn first_missing_positive(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let n = nums.len();
        for i in 0..nums.len() {
            if nums[i] <= 0 { nums[i] = n as i32 + 1; }
        }
        for i in 0..n {
            let mut pos = if nums[i] < 0 { -nums[i] } else { nums[i] } as usize;
            if pos <= n {
                nums[pos - 1] = -(if nums[pos - 1] < 0 { -nums[pos - 1] } else { nums[pos - 1] } as i32);
            }
        }
        for i in 0..n {
            if nums[i] > 0 {
                return (i as i32 + 1);
            }
        }
        return (n as i32 + 1);
    }
}