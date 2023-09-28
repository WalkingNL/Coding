package main

func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 {
		return false
	}
	row := len(matrix)
	col := len(matrix[0])
	low := 0
	high := row*col - 1
	for low <= high {
		mid := (low + high) / 2
		if matrix[mid/col][mid%col] == target {
			return true
		} else if matrix[mid/col][mid%col] < target {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	return false
}

func main() {

	// matrix := [][]int{
	// 	{1, 3, 5, 7},
	// 	{10, 11, 16, 20},
	// 	{23, 30, 34, 50},
	// }
	matrix := [][]int{
		{1, 1},
	}

	println(searchMatrix(matrix, 0))
}
