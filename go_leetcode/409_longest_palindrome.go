package main

func longestPalindrome(s string) int {
	m := ['z' - 'A' + 1]int{}
	ans := 0
	for _, char := range s {
		m[char - 'A']++
		if (m[char - 'A'] & 1) == 0 {
			ans += 2
		}
	}
	for _, number := range m {
		if number & 1 == 1 {
			ans++
			break
		}
	}
    return ans
}