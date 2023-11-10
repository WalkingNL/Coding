package main

import "sort"

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]],
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

func threeSum(nums []int) [][]int {

	if len(nums) < 3 {
		return nil
	}

	sort.Ints(nums)

	var result [][]int

	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		low := i + 1
		high := len(nums) - 1

		for low < high {
			sum := nums[i] + nums[low] + nums[high]
			if sum == 0 {
				result = append(result, []int{nums[i], nums[low], nums[high]})
				for low < high && nums[low] == nums[low+1] {
					low += 1
				}
				for low < high && nums[high] == nums[high-1] {
					high -= 1
				}
				low += 1
				high -= 1
			} else if sum < 0 {
				low += 1
			} else {
				high -= 1
			}
		}
	}

	return result
}

func main() {

	nums := []int{0, 0, 0}
	// nums := []int{-1, 0, 1, 2, -1, -4}

	var result [][]int
	result = threeSum(nums)
	println("len = ", len(result))
	for i := 0; i < len(result); i++ {
		for j := 0; j < len(result[i]); j++ {
			print(result[i][j], " ")
		}
		println()
	}
}
