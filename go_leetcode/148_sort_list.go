package main

func mergeList(left, right *ListNode) *ListNode {
	new_head := &ListNode{}
	node := new_head
	for left != nil && right != nil {
		if left.Val < right.Val {
			node.Next = left
			left = left.Next
		} else {
			node.Next = right
			right = right.Next
		}
		node = node.Next
	}
	for left != nil {
		node.Next = left
		left = left.Next
		node = node.Next
	}
	for right != nil {
		node.Next = right
		right = right.Next
		node = node.Next
	}

	return new_head.Next
}

func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	slow, fast := head, head
	for fast.Next != nil && fast.Next.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	mid := slow.Next
	slow.Next = nil

	left, right := sortList(head), sortList(mid)

	return mergeList(left, right)
}
