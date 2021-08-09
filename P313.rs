use std::collections::BinaryHeap;
use std::cmp::Reverse;
use std::collections::HashSet;

impl Solution {
    pub fn nth_super_ugly_number(n: i32, primes: Vec<i32>) -> i32 {
        let mut heap = BinaryHeap::new();
        let mut s: HashSet<i64> = HashSet::new();
        if n == 1 { return 1; }
        heap.push(Reverse(1 as i64)); s.insert(1);
        let mut cnt = 1;
        loop {
            let base = heap.pop().unwrap().0;
            if cnt == n { return base as i32; }
            // println!("{} {}", base, cnt); 
            for i in primes.iter() {
                match s.get(&((base * (*i) as i64) as i64)) {
                    Some(_) => {}
                    None => { 
                        heap.push(Reverse((base * (*i) as i64) as i64)); 
                        s.insert((base * (*i) as i64) as i64); 
                    }
                };
            }
            cnt += 1;
        }
    }
}