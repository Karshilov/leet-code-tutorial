class Solution {
private: 
    void Dfs(vector<vector<int> > e, vector<bool> &mark, int x) {
        mark[x] = 1;
        for (auto v : e[x]) {
            if (!mark[v]) {
                Dfs(e, mark, v);
            }
        }
    }
    vector<bool> dfs1(vector<vector<int> > a, int x, int m) {
        vector<bool> newMark(m); newMark.clear();
        Dfs(a, newMark, x);
        return newMark;
    }
    vector<bool> dfs2(vector<vector<int> > a, vector<bool> mark, int m) {
        vector<bool> newMark(m); newMark.clear();
        for (int i = 0; i < mark.size(); i++) {
            if (mark[i]) {
                Dfs(a, newMark, i);
            }
        }
        return newMark;
    }
    bool checkMatch(string s, string p) {
        p += '$';
        int n = s.length(), m = p.length() + 1;
        vector<vector<int> > edge(m);
        vector<bool> mark(m);
        for (int i = 0; i < m - 1; i++) {
            if (p[i] == '*') {
                edge[i - 1].push_back(i);
                edge[i].push_back(i - 1);
                edge[i].push_back(i + 1);
            }
            else if (p[i] == '$') {
                edge[i].push_back(i + 1);
            }
        }
        mark = dfs1(edge, 0, m);
        for (int i = 0; i < n; i++) {
            vector<bool> match(m);
            for (int j = 0; j < m; j++) {
                if (mark[j]) {
                    if (j == m - 1) {
                        continue;
                    }
                    if (p[j] == s[i] || p[j] == '.') {
                        match[j + 1] = true;
                    }
                }
            }
            mark = dfs2(edge, match, m);
        }
        return mark[m - 1];
    }
public:
    bool isMatch(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        int mLen = min(sLen, pLen);
        if (s == "") {
            for (int i = 0; i < pLen; i++) {
                if (islower(p[i]) || p[i] == '.') {
                    if (i + 1 < pLen && p[i + 1] == '*') {
                        continue;
                    }
                    else return 0;
                }
            }
            return 1;
        }
        if (p == "" || p[0] == '*') {
            return 0;
        }
        return checkMatch(s, p);
    }
};