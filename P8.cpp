class Solution {
public:
    int myAtoi(string str) {
        if (str == "") return 0;
        int pos = 0, ans = 0;
        while(pos < str.length() && str[pos] == ' ') pos++;
        if (pos == str.length()) return 0;
        if (!isdigit(str[pos])) {
            if (str[pos] == '+' || str[pos] == '-') {
                int fg = 1;
                if (str[pos] == '-') fg = -1;
                pos++;
                if(pos >= str.length() || !isdigit(str[pos])) return 0;
                else {
                    while(pos < str.length() && isdigit(str[pos])) {
                        if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && (int) (str[pos] - '0') > 8)) return INT_MIN;
                        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (int) (str[pos] - '0') > 7)) return INT_MAX;
                        ans *= 10;
                        ans += (int) (str[pos] - '0') * fg;
                        pos++;
                    }
                    return ans;
                }
            }
            else {
                return 0;
            }
        }
        else {
            while(pos < str.length() && isdigit(str[pos])) {
                if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && (int) (str[pos] - '0') < -8)) return INT_MIN;
                if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (int) (str[pos] - '0') > 7)) return INT_MAX;
                ans *= 10;
                ans += (int) (str[pos] - '0');
                pos++;
            }
            return ans;
        }
    }
};