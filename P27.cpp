class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                ans++;
                continue;
            }
            nums[i - ans] = nums[i];
        }
        return nums.size() - ans;
    }
};