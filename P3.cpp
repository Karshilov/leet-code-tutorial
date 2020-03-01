class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.length();
        if (n == 1) return 1;
        int ans = 0;
        unordered_map<char, int> ap;
        deque<char> q;
        ap.clear();
        for (int i = 0; i < n; i++) ap[s[i]] = 0;
        for (int i = 0; i < n; i++) {
            ap[s[i]]++;
            q.push_back(s[i]);
            while(ap[s[i]] == 2) {
                ap[q.front()] --;
                q.pop_front();
            }
            ans = max(ans, (int) q.size());
        }
        return ans;
    }
};