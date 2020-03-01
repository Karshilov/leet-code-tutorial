class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int width = r - l;
        int ans = width * min(height[l], height[r]);
        while (l != r) {
            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
            ans = max(ans, (--width) * min(height[l], height[r]));
        }
        return ans;
    }
};