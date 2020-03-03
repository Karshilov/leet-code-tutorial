class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 998244353;
        if (nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        for (int i = 0; i < nums.size(); i++) {
            l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return sum;
                if (ans == 998244353 || abs(target - sum) < abs(ans - target)) ans = sum;
                if (sum > target) r--;
                else l++;
            }
        }
        return ans;
    }
};