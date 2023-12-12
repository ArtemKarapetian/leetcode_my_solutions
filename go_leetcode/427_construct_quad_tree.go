package main

func construct(grid [][]int) *Node {
	return constructNode(&grid, 0, 0, len(grid))
}

func constructNode(grid *[][]int, firstX, firstY, n int) *Node{
	var firstElement int = (*grid)[firstY][firstX]
	if n == 1 {
		return &Node{firstElement == 1, true, nil, nil, nil, nil}
	}
	var flag bool = true
	for i := firstX; i < firstX + n; i++ {
		for j := firstY; j < firstY + n; j++ {
			if (*grid)[j][i] != firstElement {
				flag = false
				break
			}
		}
	}
	if flag {
		return &Node{firstElement == 1, true, nil, nil, nil, nil}
	}
	return &Node{
		true, 
		false, 
		constructNode(grid, firstX, firstY, n / 2),
		constructNode(grid, firstX + n / 2, firstY, n / 2),
		constructNode(grid, firstX, firstY + n / 2, n / 2),
		constructNode(grid, firstX + n / 2, firstY + n / 2, n / 2),
	}
}
