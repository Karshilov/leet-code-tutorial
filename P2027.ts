function minimumMoves(s: string): number {
    let ans = 0;
    for (let i = 0; i < s.length;) {
        if (s[i] == 'O') {
            i++;
            continue;
        }
        if (s.slice(i, Math.min(i + 3, s.length)).includes('X')) {
            ans++;
            i += 3;
        }
    }
    return ans;
};