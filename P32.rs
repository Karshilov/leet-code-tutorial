use std::cmp::max;
impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let mut cnt = 0;
        let mut ret = 0;
        let mut cur = 0;
        let v = &s[..];
        let mut cur_char: Vec<char> = v.chars().collect();
        for c in cur_char.iter() {
            let i = *c;
            if i == '(' {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            cur += 1;
            if (cnt == 0) {
                ret = max(ret, cur);
            }
            if (cnt < 0) {
                cur = 0;
                cnt = 0;
            }
        }
        cur_char.reverse();
        for c in cur_char.iter_mut() {
            if *c == '(' {
                *c = ')'
            }
            else {
                *c = '('
            }
        }
        cnt = 0;
        cur = 0;
        for c in cur_char.iter() {
            let i = *c;
            if i == '(' {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            cur += 1;
            if (cnt == 0) {
                ret = max(ret, cur);
            }
            if (cnt < 0) {
                cur = 0;
                cnt = 0;
            }
        }
        ret
    }
}