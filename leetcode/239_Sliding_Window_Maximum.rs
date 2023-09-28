use std::collections::VecDeque;
use std::convert::TryInto;

struct Solution {}

impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut vec = Vec::<i32>::new();
        let mut dp = VecDeque::<i32>::new();
        
        // let l = k as usize;

        let mut i: i32 = 0;
        while i<nums.len() as i32 {
            // 1, 3, -1, -3, 5, 3, 6, 7
            while !dp.is_empty() && *dp.front().unwrap()<(i-k+1).try_into().unwrap() {
                dp.pop_front();
            }

            while !dp.is_empty() && nums[*dp.back().unwrap() as usize]<nums[i as usize] {
                dp.pop_back();
            }
            
            dp.push_back(i.try_into().unwrap());

            if i >= k-1 {
                // vec.push_back(nums[*dp.front().unwrap() as usize]);
                vec.push(nums[*dp.front().unwrap() as usize]);
                // vec.push_back(23);
            }

            i += 1;
        }

        return vec;
    }
}

fn main() {
    // let vec = Vector![1,3,-1,-3,5,3,6,7];
    let vec = vec![1,3,-1,-3,5,3,6,7];
    let k = 4;

    let result = Solution::max_sliding_window(vec, k);

    println!("{:?}", result);
}
