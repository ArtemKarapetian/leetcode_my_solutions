package main
import "fmt"

func main() {
	var lists []*ListNode = []*ListNode{
        &ListNode{
            1, &ListNode{
                4, &ListNode{
                    5, nil,
                },
            },
        },
        &ListNode{
            1, &ListNode{
                3, &ListNode{
                    4, nil,
                },
            },
        },
        &ListNode{
            2, &ListNode{
                6, nil,
            },
        },
    }
    var list *ListNode = mergeKLists(lists)
    fmt.Println(list.Val)
}

