impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
        let l = nums.len();
        if (l == 1) {
            return ;
        }
        let mut i = l - 1;
        while i > 0 {
            if nums[i] > nums[i - 1] {
                i = i - 1;
                break;
            }
            i -= 1;
        }
        if (nums[1] <= nums[0] && i == 0) {
            nums.reverse();
            return ;
        }
        let mut j = l - 1;
        while j > 0 {
            if (nums[j] > nums[i]) { break; }
            j -= 1;
        }
        nums.swap(i, j);
        let mut v = nums.clone();
        v.reverse();
        let tmp = i + 1;
        i += 1;
        while i < l {
            nums[i] = v[i - tmp];
            i += 1;
        }
    }
}