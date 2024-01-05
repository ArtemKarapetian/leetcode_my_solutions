package main

import "math/rand"

func findKthLargest(nums []int, k int) int {
	k--
	left, right := 0, len(nums) - 1
	for left < right {
		pivot, leftPointer, rightPointer := rand.Int() % (right - left + 1) + left, left + 1, right
		nums[pivot], nums[left] = nums[left], nums[pivot]
		pivotNum := nums[left]
		for {

			for nums[leftPointer] > pivotNum {
				if leftPointer == right {
					break
				}
				leftPointer++
			}
			
			for nums[rightPointer] < pivotNum {
				if rightPointer == left {
					break
				}
				rightPointer--
			}
			
			if leftPointer >= rightPointer {
				break
			}
			nums[leftPointer], nums[rightPointer] = nums[rightPointer], nums[leftPointer]
			leftPointer++
			rightPointer--
		}
		nums[left], nums[rightPointer] = nums[rightPointer], nums[left]

		if k < rightPointer {
			right = rightPointer - 1
		} else if k > rightPointer {
			left = rightPointer + 1
		} else {
			return nums[rightPointer]
		}
	}
	if left == right {
		return nums[left]
	}
	return -1
}
