package main
import "fmt"

func main() {
	var list1 *ListNode = &ListNode{
        4,
        &ListNode{
            2,
            &ListNode{
                1,
                &ListNode{
                    3,
                    nil,
                },
            },
        },
    }

   list1 = sortList(list1)

    for (list1 != nil) {
        fmt.Println(list1.Val, " ")
        list1 = list1.Next
    }
}

