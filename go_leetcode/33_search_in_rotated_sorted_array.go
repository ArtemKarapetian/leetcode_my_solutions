package main

func search(nums []int, target int) int {
	pivot, left, right := nums[0], 0, len(nums)
	for left != right {
		mid := (right + left) / 2
		if nums[mid] == target {
			return mid
		}
		if (pivot <= target && nums[mid] >= pivot && nums[mid] > target) || (pivot > nums[mid] && ((pivot > target && nums[mid] > target) || pivot <= target)) {
			right = mid
		} else {
			left = mid + 1
		}
	}   
	return -1
}