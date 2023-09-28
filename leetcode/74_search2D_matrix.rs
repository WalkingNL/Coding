struct Solution {}

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        if matrix.len() == 0 {
            return false;
        }
        
        let row = matrix.len() as i32;
        let col = matrix[0].len() as i32;

        let mut low: i32 = 0;
        let mut high: i32 = row*col - 1;
        let mut mid: i32;

        if high == 0 {
            return matrix[0][0] == target;
        }

        while low <= high {
            mid = (low + high) / 2;
            if matrix[(mid/col) as usize][(mid%col) as usize] == target {
                return true;
            } else if matrix[(mid/col) as usize][(mid%col) as usize] < target {
                low = mid + 1;
            } else {
                println!("mid: {}", mid);
                println!("low: {}, high: {}", low, high);
                high = mid - 1;
            }
        }

        false
    }
}

fn main() {

    let matrix = vec![vec![1,1]];

    println!("{}", Solution::search_matrix(matrix, 0))
}
