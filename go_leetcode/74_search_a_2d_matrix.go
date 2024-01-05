package main

func searchMatrix(matrix [][]int, target int) bool {
	n := len(matrix[0])
	left, right :=  0, len(matrix) * n
	for right > left {
		mid := (right + left) / 2
		if matrix[mid / n][mid % n] == target {
			return true
		}
		if matrix[mid / n][mid % n] > target {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return false
}