package main

type Node struct {
	Val bool
	IsLeaf bool
	TopLeft *Node
	TopRight *Node
	BottomLeft *Node
	BottomRight *Node
}