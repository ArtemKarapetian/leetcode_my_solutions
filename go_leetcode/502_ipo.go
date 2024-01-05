package main

import (
	"container/heap"
	"sort"
)

type CapitalAndProfit struct {
	capital, profit int
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeap) Swap(i, j int) 	  { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x any) 		  { *h = append(*h, x.(int)) }

func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func findMaximizedCapital(k int, w int, profits []int, capital []int) int {
	capitalsAndProfits := make([]CapitalAndProfit, len(capital))
	for i := 0; i < len(capital); i++ {
		capitalsAndProfits[i] = CapitalAndProfit{capital[i], profits[i]}
	}

	sort.Slice(capitalsAndProfits, func(i, j int) bool {
		return capitalsAndProfits[i].capital < capitalsAndProfits[j].capital
	})

	h := &IntHeap{}
	ind := 0
	for ; k != 0 ; k-- {
		for ind < len(capital) && capitalsAndProfits[ind].capital <= w {
			heap.Push(h, capitalsAndProfits[ind].profit)
			ind++
		}

		if h.Len() == 0 {
			break
		}

		w += heap.Pop(h).(int)
	}

	return w
}
