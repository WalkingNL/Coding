struct Solution {}

impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {

        if n == 0 {
            return
        }

        let mut i = 0;
        if m == 0 {
            while i < n {
                nums1[i as usize] = nums2[i as usize];
                i += 1;
            }            
        }

        let mut i = m - 1;
        let mut j = n - 1;
        let mut k = m + n - 1;

        while i >= 0 && j >= 0 {
            if nums1[i as usize] > nums2[j as usize] {
                nums1[k as usize] = nums1[i as usize];
                i -= 1;
            } else {
                nums1[k as usize] = nums2[j as usize];
                j -= 1;
            }

            k -= 1;
        }

        while j >= 0 {
            nums1[k as usize] = nums2[j as usize];
            k -= 1;
            j -= 1;
        }
    }
}

fn main() {

    Solution::merge(&mut vec![1,2,3,0,0,0], 3, &mut vec![2,5,6], 3);
}

