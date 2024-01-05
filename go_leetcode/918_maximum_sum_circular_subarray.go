package main

func maxSubarraySumCircular(nums []int) int {
    var cur, minSum, maxSum, sum int
	maxSum = -30000
	for _, elem := range nums {
		sum += elem
		cur += elem
		if (cur > maxSum) {
			maxSum = cur
		}
		if (cur < 0) {
			cur = 0
		}
	}
	cur = 0
	for _, elem := range nums {
		cur += elem
		if (cur < minSum) {
			minSum = cur
		}
		if (cur > 0) {
			cur = 0
		}
	}
	if (maxSum > 0 && maxSum < sum - minSum) {
		return sum - minSum
	}
	return maxSum
}