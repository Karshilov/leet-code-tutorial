class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        vector<vector<long long>> sum = vector<vector<long long>>(2, vector<long long>(grid[0].size(), 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                sum[i][j] = j == 0 ? grid[i][j] : sum[i][j - 1] + grid[i][j];
            }
        }
        long long ans = (1LL << 60);
        for (int i = 0; i < grid[0].size(); i++) {
            auto cur = max(sum[0].back() - sum[0][i], (i == 0 ? 0 : sum[1][i - 1]));
            ans = min(ans, cur);
        }
        return ans;
    }
};