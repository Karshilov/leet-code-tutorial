class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        ans.clear();
        if (nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        for (int i = 0; i < nums.size() - 2;) {
            //cout << i << endl;
            if (nums[i] > 0) break;
            l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    vector<int> tmp; tmp.clear();
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[l]);
                    tmp.push_back(nums[r]);
                    ans.push_back(tmp);
                }
                if (sum > 0) for(; l < r && nums[r] == nums[--r]; );
                else for (; l < r && nums[l] == nums[++l]; );
            }
            for ( ;i < nums.size() - 1 && nums[i] == nums[++i];);
        }
        return ans;
    }
};