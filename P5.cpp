class Solution {
public:
    string longestPalindrome(string s) {
        short len1 = s.length();
        short len2 = 0;
        string s2 = "";
        s2 += '$';
	    s2 += '#';
	    for (short i = 0; i < len1; i++) {
		    s2 += s[i];
		    s2 += '#';
	    }
	    len2 = len1 * 2 + 2;
	    s2 += '&';
        vector<short> p(len2);
        short id = 0, mx = 0;
	    for (short i = 1; i < len2; i++) {
		    if (mx > i) p[i] = min((short) p[2 * id - i], (short) (mx - i));
		    else p[i] = 1;
		    while (s2[i + p[i]] == s2[i - p[i]]) p[i]++;
		    if (i + p[i] > mx) {
			    mx = i + p[i];
			    id = i;
		    }
	    }
        mx = -1, id = 0;
        for (short i = 1; i < len2; i++) {
            if (p[i] > mx) {
                id = i;
                mx = p[i];
            }
        }
        string ans = "";
        for (short i = id - mx + 1; i < id + mx - 1; i++) {
            if (s2[i] == '#' || s2[i] == '&' || s2[i] == '$') continue;
            ans += s2[i];
        }
        return ans;
    }
};