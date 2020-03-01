class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        int counter = 0, len = 0x3f3f3f3f;
        for (int i = 0; i < strs.size(); i++) len = min(len, (int) strs[i].length());
        for (int i = 0; i < len; i++) {
            int fg = 0;
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] == strs[0][i]) {
                    if (j == strs.size() - 1) counter++;
                    else continue;
                }
                else {
                    fg = 1;
                    break;
                }
            }
            if (fg) break;
        }
        string ans = "";
        for (int i = 0; i < counter; i++) ans += strs[0][i];
        return ans;
    }
};