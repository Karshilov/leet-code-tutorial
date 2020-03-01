class Solution {
public:
    int romanToInt(string s) {
        string byte[] = {"", "", "", "", ""};
        bool fg[] = {0, 0, 0, 0};
        int counter = 4;
        unordered_map<char, int> mp;
        mp['V'] = mp['D'] = mp['L'] = 5;
        mp['I'] = mp['X'] = mp['C'] = 1;
        for (auto c : s) {
            if (((!fg[3]) && (!fg[2]) && (!fg[1])) && (c == 'D' || c == 'C')) counter = 3, fg[3] = 1;
            if (((!fg[2]) && (!fg[1])) && (c == 'L' || c == 'X')) counter = 2, fg[2] = 1;
            if ((!fg[1]) && (c == 'V' || c == 'I')) counter = 1, fg[1] = 1;
            byte[counter] += c;
        }
        counter = 4;
        int ans = 0;
        while (counter) {
            ans *= 10;
            if (byte[counter] == "") {
                counter--;
                continue;
            }
            if (counter == 4) {
                for (auto c : byte[counter]) {
                    ans ++;
                }
            }
            else if (counter == 3) {
                if (byte[counter] == "CD") {
                    ans += 4;
                }
                else if (byte[counter] == "CM") {
                    ans += 9;
                }
                else {
                    for (auto c : byte[counter]) {
                        ans += mp[c];
                    }
                }
            }
            else if (counter == 2) {
                if (byte[counter] == "XL") {
                    ans += 4;
                }
                else if (byte[counter] == "XC") {
                    ans += 9;
                }
                else {
                    for (auto c : byte[counter]) {
                        ans += mp[c];
                    }
                }
            }
            else if (counter == 1) {
                if (byte[counter] == "IV") {
                    ans += 4;
                }
                else if (byte[counter] == "IX") {
                    ans += 9;
                }
                else {
                    for (auto c : byte[counter]) {
                        ans += mp[c];
                    }
                }
            }
            counter --;
        }
        return ans;
    }
};