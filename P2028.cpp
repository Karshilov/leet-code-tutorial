class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int res = mean * (n + rolls.size());
        int remain = res - accumulate(rolls.begin(), rolls.end(), 0);
        auto ans = vector<int>();
        if (remain < n || remain > 6 * n) return ans;
        ans = vector<int>(n, 0);
        int pos = 0;
        while (remain) {
            ans[pos]++;
            pos = (pos + 1) % n;
            remain--;
        }
        return ans;
    }
};