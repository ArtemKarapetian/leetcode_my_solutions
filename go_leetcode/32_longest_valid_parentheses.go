package main

import "container/list"

func longestValidParentheses(s string) int {
	stack := list.New()
	stack.PushBack(-1)
	ans := 0
	for i, char := range s {
		if char == '(' {
			stack.PushBack(i)
			continue
		}
		stack.Remove(stack.Back())
		if stack.Len() == 0 {
			stack.PushBack(i)
			continue
		}
		ans = max(ans, i-stack.Back().Value.(int))
	}
	return ans
}
