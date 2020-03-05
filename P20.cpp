class Solution {
public:
    bool isValid(string s) {
        if (s == "") return true;
        stack<char> S;
        while (!S.empty()) S.pop();
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') S.push(c);
            if (c == ')') {
                if (!S.empty() && S.top() == '(') {
                    S.pop();
                    continue;
                }
                else return false;
            }
            else if (c == '}') {
                if (!S.empty() && S.top() == '{') {
                    S.pop();
                    continue;
                }
                else return false;
            }
            else if (c == ']') {
                if (!S.empty() && S.top() == '[') {
                    S.pop();
                    continue;
                }
                else return false;
            }
        }
        if (S.empty()) return true;
        else return false;
    }
};