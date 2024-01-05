package main

import "math"

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	if len(nums1) > len(nums2) {
		return findMedianSortedArrays(nums2, nums1)
	}
	m, n := len(nums1), len(nums2)
	left, right, answer := 0, m, 0.0
	for left <= right {
		midA := (right + left) / 2
		midB := (m + n + 1) / 2 - midA

		var leftMaxA, leftMaxB, rightMinA, rightMinB int
		
		if midA == 0 {
			leftMaxA = math.MinInt
		} else {
			leftMaxA = nums1[midA - 1]
		}

		if midB == 0 {
			leftMaxB = math.MinInt
		} else {
			leftMaxB = nums2[midB - 1]
		}

		if midA == m {
			rightMinA = math.MaxInt
		} else {
			rightMinA = nums1[midA]
		}

		if midB == n {
			rightMinB = math.MaxInt
		} else {
			rightMinB = nums2[midB]
		}

		if leftMaxA > rightMinB {
			right = midA - 1
			continue
		} else if leftMaxB > rightMinA {
			left = midA + 1
			continue
		}

		if leftMaxA > leftMaxB {
			answer += float64(leftMaxA)
		} else {
			answer += float64(leftMaxB)
		}

		if (m + n) % 2 == 0 {
			if rightMinA < rightMinB {
				answer += float64(rightMinA)
			} else {
				answer += float64(rightMinB)
			}
			answer /= 2.0
		}

		break
	}
	return answer
}
