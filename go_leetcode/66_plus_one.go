package main

func plusOne(digits []int) []int {
    for i := len(digits) - 1; i >= 0; i-- {
        digits[i]++
        if digits[i] == 10 {
            digits[i] = 0
        } else {
            break
        }
    }
    if digits[0] == 0 {
        digits[0] = 1
        digits = append(digits, 0)
    }
    return digits
}