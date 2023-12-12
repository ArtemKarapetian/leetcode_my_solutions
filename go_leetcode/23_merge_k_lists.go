package main

func mergeKLists(lists []*ListNode) *ListNode {
	return mergeLists(&lists)
}

func mergeLists(lists *[]*ListNode) *ListNode {
	var n int = len(*lists)
	if n == 0 {
		return nil
	}
	if n == 1 {
		return (*lists)[0]
	}
	if n == 2 {
		return merge2Lists((*lists)[0], (*lists)[1])
	}
	var newLists []*ListNode = make([]*ListNode, 0, n / 2 + n % 2)
	for i := 0; i < n - 1; i += 2 {
		newLists = append(newLists, merge2Lists((*lists)[i], (*lists)[i + 1]))
	}
	if n % 2 == 1 {
		newLists = append(newLists, (*lists)[n - 1])
	}
	return mergeLists(&newLists)
}

func merge2Lists(listA, listB *ListNode) *ListNode {
	var newList *ListNode = new(ListNode)
	var newListEnd *ListNode = newList
	for listA != nil && listB != nil {
		if listA.Val <= listB.Val {
			newListEnd.Next = listA
			listA = listA.Next
		} else {
			newListEnd.Next = listB
			listB = listB.Next
		}
		newListEnd = newListEnd.Next
	}
	if listA != nil {
		newListEnd.Next = listA
	}
	if listB != nil {
		newListEnd.Next = listB
	}
	return newList.Next
}
