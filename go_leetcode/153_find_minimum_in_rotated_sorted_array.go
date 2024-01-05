package main

func findMin(nums []int) int {
	if nums[0] < nums[len(nums)-1] {
		return nums[0]
	}
	pivot, left, right := nums[0], 0, len(nums)
	for left != right {
		mid := (left + right) / 2
		if nums[mid] >= pivot {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return nums[left]
}
