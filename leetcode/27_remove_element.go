package main

func removeElement(nums []int, val int) int {
	count := 0

	for i := 0; i < len(nums); i++ {
		if nums[i] == val {
			count++
			continue
		}
		if count > 0 {
			nums[i-count] = nums[i]
		}
	}

	println("count: ", count)
	if count > 0 {
		nums = nums[:len(nums)-count]
	}

	for i := 0; i < len(nums); i++ {
		print(nums[i], " ")
	}
	println()

	return len(nums)
}

func main() {

	nums := []int{3, 2, 3, 3}

	println("reserve_length: ", removeElement(nums, 3))

	// for i := 0; i < len(nums); i++ {
	// 	print(nums[i], " ")
	// }
	// println()
}
