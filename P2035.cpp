class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        map<int, set<int> > mp = map<int, set<int> >();
        for (int i = 0; i < (1 << n); i++) {
            int b = i;
            int sum0 = 0, sum1 = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) sum1 += nums[j];
                else sum0 += nums[j];
            }
            mp[__builtin_popcount(i)].insert(sum1 - sum0);
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < (1 << n); i++) {
            int b = i;
            int sum0 = 0, sum1 = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) sum1 += nums[n + j];
                else sum0 += nums[n + j];
            }
            int rev = n - __builtin_popcount(i);
            int sub = sum0 - sum1;
            auto pos1 = mp[rev].upper_bound(sub);
            if (pos1 != mp[rev].end()) ans = min(ans, abs(*pos1 - sub));
            if (pos1 != mp[rev].begin()) ans = min(ans, abs(*(--pos1) - sub));
        }
        return ans;
    }
};