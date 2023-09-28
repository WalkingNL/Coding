
struct Solution{}

impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        if n == 0 {
            return 1.0;
        }

        let mut res = 1.0;
        let mut x = x;
        let mut n = n;

        if n < 0 {
            x = 1.0 / x;
            if (n == -2147483648) {
                n = 2147483647;
                res *= x;
            } else {
                n = -n;
            }

            // n = -n;
        }

        while n > 0 {
            if n & 1 == 1 {
                res *= x;
                println!("res: {}", res);
            }
            x *= x;
            n >>= 1;
            println!(" n: {}", n);
        }

        return res;    
    }
}

fn main() {

    let x = 2.0;
    // let n = 7;
    let n = -2147483648;
    let res = Solution::my_pow(x, n);
    println!("{}", res);

}
