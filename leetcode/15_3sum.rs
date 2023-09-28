/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

struct Solution {}

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();
        let mut nums = nums;
        nums.sort();
        let mut i = 0;
        while i < nums.len() {
            let mut j = i + 1;
            let mut k = nums.len() - 1;
            while j < k {
                let sum = nums[i] + nums[j] + nums[k];
                if sum == 0 {
                    result.push(vec![nums[i], nums[j], nums[k]]);
                    while j < k && nums[j] == nums[j + 1] {
                        j += 1;
                    }
                    while j < k && nums[k] == nums[k - 1] {
                        k -= 1;
                    }
                    j += 1;
                    k -= 1;
                } else if sum < 0 {
                    j += 1;
                } else {
                    k -= 1;
                }
            }
            while i + 1 < nums.len() && nums[i] == nums[i + 1] {
                i += 1;
            }
            i += 1;
        }
        result
    }
}

fn main() {
    // let nums = vec![-1,0,1,2,-1,-4];
    // let nums = vec![0, 0, 0, 0];
    // let nums = vec![-2, 0, 0, 2, 2];
    // let nums = vec![-2, 0, 1, 1, 2];
    let nums = vec![-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6];
    let result = Solution::three_sum(nums);
    println!("{:?}", result);
}
