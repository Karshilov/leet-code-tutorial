class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (numRows == 1) return s;
        int pos = 1, cur = 0;
        vector<vector<char> > newString(numRows);
        for (int i = 0; i < numRows; i++) newString[i].clear();
        for (int i = 0; i < len; i++) {
            newString[pos - 1].push_back(s[i]);
            if (cur) {
                pos--;
            }
            else {
                pos++;
            }
            if (pos == numRows || pos == 1) {
                cur ^= 1;
            }
        }
        string ans = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < newString[i].size(); j++) {
                ans += newString[i][j];
            }
        }
        return ans;
    }
};