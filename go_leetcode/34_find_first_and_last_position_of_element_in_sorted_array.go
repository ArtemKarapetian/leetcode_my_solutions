package main

func searchRange(nums []int, target int) []int {
    left, right := 0, len(nums)
	var mid, temp int
	for left != right {
		mid = (right + left) / 2
		if nums[mid] == target {
			break
		}
		if nums[mid] > target {
			right = mid
		} else {
			left = mid + 1
		}
	}
	if left == right {
		return []int{-1, -1}
	}
	leftInd, rightInd := 0, len(nums)
	left, right = mid, mid
	for leftInd != left {
		temp = (left + leftInd) / 2
		if nums[temp] < target {
			leftInd = temp + 1
		} else {
			left = temp
		}
	}
	for rightInd != right {
		temp = (right + rightInd) / 2
		if nums[temp] > target {
			rightInd = temp
		} else {
			right = temp + 1
		}
	}
	return []int{leftInd, rightInd - 1}
}