class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int, bool> ap;
        map<int, int> pos;
        ret.clear(), ap.clear(), pos.clear();
        int i = 0;
        for (auto x : nums) {
            if (ap.count(target - x)) {
                ret.push_back(pos[target - x]);
                ret.push_back(i);
                break;
            }
            ap[x] = 1;
            pos[x] = i;
            i++;
        }
        return ret;
    }
};