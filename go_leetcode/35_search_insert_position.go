package main

func searchInsert(nums []int, target int) int {
	var left, right int = 0, len(nums)
	for left < right {
		mid := (right + left) / 2
		if nums[mid] == target {
			return mid
		}
		if (nums[mid] > target) {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return right
}