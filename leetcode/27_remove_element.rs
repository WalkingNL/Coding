use std::convert::TryInto;

struct Solution;

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut count = 0;

        let mut i = 0;

        while i < nums.len() {
            if nums[i] == val {
                count = count + 1;
                i = i + 1;
                continue;
            }
            if count > 0 {
                nums[i-count] = nums[i];
            }
            i = i + 1;
        }
        
        while count > 0 {
            nums.pop();
            count = count - 1;
        }

        // return nums.len() as i32;
        return nums.len().try_into().unwrap();
    }
}

fn main() {

    Solution::remove_element(&mut vec![0,1,2,2,3,0,4,2], 2);
}