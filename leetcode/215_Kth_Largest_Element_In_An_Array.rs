use std::cmp::Reverse;

struct Solution {}

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;
        nums.sort_by_key(|x| Reverse(*x));
        return nums[(k-1) as usize];
    }
}

fn main() {
    let v = vec![3, 2, 1, 5, 6, 4];
    // let v = vec![3, 2, 3, 1, 2, 4, 5, 5, 6];
    // let v = vec![2, 1];
    
    let x = Solution::find_kth_largest(v, 2);


    // let mutable v = vec![2, 1, 3, 4, 5];
    // v.sort_by_key(|x| Reverse(*x)); // descending sort
    // v.sort_by(|a, b| b.cmp(a));
    // v.sort();
    // let x = Solution::find_kth_largest(v, 2);

    println!("{}", x);
    // println!("{:?}", v);
}
