struct Solution;

impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        
        if n == 0 {
            return true;
        }

        if flowerbed.len() == 1 {
            if flowerbed[0] == 0 {
                return true;
            } else {
                return false;
            }
        }
        let mut n = n;
        let mut i = 0;
        let mut count = 0;
        println!("len = {}", flowerbed.len());
        while i < flowerbed.len() {
            if flowerbed[i] == 0 {
                count += 1;
            } else {
                count = 0;
                i += 1;
                continue;
            }
            if count >= 3 || (count==2 && i==flowerbed.len()-1) {
                count = 1;
                n -= 1;
                if n <= 0 {
                    break;
                }
            }
            println!("i = {}", i);
            i += 1;
        }
        if n == 0 {
            return true;
        }
        return false;
    }
}

fn main() {
    let vec = vec![1,0,0,0,1];
    let n = 2;
    let b = Solution::can_place_flowers(vec, n);
    if b {
        println!("ok");
    } else {
        println!("not ok");
    }
}
