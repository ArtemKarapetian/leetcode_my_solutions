package main

import "fmt"

func main() {
	nums1, nums2 := []int{1, 7, 11}, []int{2, 4, 6}
	fmt.Println(kSmallestPairs(nums1, nums2, 3))

	nums1, nums2 = []int{1, 1, 2}, []int{1, 2, 3}
	fmt.Println(kSmallestPairs(nums1, nums2, 2))

	nums1, nums2 = []int{1, 2}, []int{3}
	fmt.Println(kSmallestPairs(nums1, nums2, 2))
}
