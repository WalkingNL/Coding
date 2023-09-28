package main

func removeDuplicates(nums []int) int {

	if len(nums) == 0 {
		return 0
	}

	i := 0
	j := 1

	for j < len(nums) {

		if nums[i] == nums[j] {
			j += 1
		} else {
			i += 1
			nums[i] = nums[j]
			j += 1
		}
	}

	return i + 1
}

func main() {

}
