package main

import "container/heap"

type PairHeap [][3]int

func (ph PairHeap) Len() int			{ return len(ph)}
func (ph PairHeap) Less(i, j int) bool	{ return ph[i][0] + ph[i][1] < ph[j][0] + ph[j][1]}
func (ph PairHeap) Swap(i, j int)		{ ph[i], ph[j] = ph[j], ph[i]}
func (ph *PairHeap) Push(x any)			{ *ph = append(*ph, x.([3]int))}
func (ph *PairHeap) Pop() any {
	old := *ph
	n := len(old)
	x := old[n - 1]
	*ph = old[0 : n - 1]
	return x
}

func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
	if len(nums1) == 0 || len(nums2) == 0 || k == 0 {
		return [][]int{}
	}
    ph := &PairHeap{}
	for i := 0; i < k && i < len(nums1); i++ {
		heap.Push(ph, [3]int{ nums1[i], nums2[0], 0})
	}
	res, ind := make([][]int, k), 0
	for ; k != 0; k-- {
		pair := heap.Pop(ph).([3]int)
		res[ind] = []int{ pair[0], pair[1]}
		if pair[2] != len(nums2) - 1 {
			heap.Push(ph, [3]int{ pair[0], nums2[pair[2] + 1], pair[2] + 1})
		}
		ind++
	}
	return res
}