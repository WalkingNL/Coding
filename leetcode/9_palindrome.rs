struct Solution {}

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }

        let mut x = x;
        let mut reverse = 0;
        let original = x;

        while x > 0 {
            println!("x: {}", x);
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        println!("reverse: {}, x: {}", reverse, x);

        return original == reverse;
    }
}

fn main() {
    if Solution::is_palindrome(121) {
        println!("yes");
    } else {
        println!("no");
    }
}