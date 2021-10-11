class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        auto dif = vector<long long>(nums.size(), 0);
        auto sum = vector<long long>(nums.size(), 0);
        auto pre = vector<int>(nums.size(), 0);
        unordered_map<long long, int> mp = unordered_map<long long, int>();
        unordered_map<long long, int> mp2 = unordered_map<long long, int>();
        for (int i = 0; i < nums.size(); i++) {
            sum[i] = i == 0 ? nums[i] : sum[i - 1] + nums[i];
            if (i >= 1) {
                if (sum[i] == sum[i - 1]) pre[i] = pre[i - 1] + 1;
            }
        }
        int originAns = 0;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            dif[i] = (sum.back() - sum[i - 1]) - sum[i - 1];
            mp[dif[i]]++;
            if (dif[i] == 0) originAns++;
        }
        for (int i = 0; i < nums.size(); i++) {
           // cout << mp[k - nums[i]] << " " << mp2[nums[i] - k] + mp[k - nums[i]] << " "<< (k - nums[i]) << " "  << i << " " << endl;
            if (i > 0 && i < nums.size()) mp2[dif[i]]++;
            if (i > 0 && i < nums.size()) mp[dif[i]] = max(0, mp[dif[i]] - 1);
            if (mp[k - nums[i]] != 0 || mp2[nums[i] - k] != 0) {
                ans = max(ans, mp[k - nums[i]] + mp2[nums[i] - k]);
            }
            
        }
        return max(ans, originAns);
    }
};