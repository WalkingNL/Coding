
struct Solution {}

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut min_price = prices[0];
        let mut max_profits = 0;

        for i in 1..prices.len() {
            if prices[i] < min_price {
                min_price = prices[i];
            } else if prices[i] - min_price > max_profits {
                max_profits = prices[i] - min_price;
            }
        }

        return max_profits;
    }
}

fn main() {
    let prices = vec![7, 1, 5, 3, 6, 4];
    let max_profits = Solution::max_profit(prices);
    println!("{}", max_profits);
}
