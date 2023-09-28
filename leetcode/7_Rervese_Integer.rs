struct Solution {}

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut result = 0;

        let mut x = x;

        while (x != 0) {
            if result > 214748364 || result < -214748364 {
                return 0;
            }

            result = result * 10 + x % 10;
            x /= 10;
        }

        result
    }
}

fn main() {

}
