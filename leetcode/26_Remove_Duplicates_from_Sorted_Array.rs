struct Solution {}

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if nums.len() == 0 {
            return 0;
        }

        let mut i = 0;
        let mut j = 1;

        while j < nums.len() {
            if nums[i] == nums[j] {
                j += 1;
            } else {
                i += 1;
                nums[i] = nums[j];
                j += 1;
            }
        }
        return (i + 1) as i32;
    }
}

fn main() {

    let mut nums = vec![1, 1, 2];
    let len = Solution::remove_duplicates(&mut nums);
    let mut i = 0;
    while i < len {
        println!("{}", nums[i as usize]);
        i += 1;
    }
}
