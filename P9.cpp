class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int counter = 0, half = 0, cpy = x;
        bool fg = 0;
        for (; cpy; cpy /= 10, counter++);
        (counter & 1) && (fg = 1);
        counter >>= 1;
        for (; counter; half = half * 10 + x % 10, x /= 10, counter--);
        (fg) && (x /= 10);
        if (x == half) return true;
        else return false;
    }
};