package main

// change to Node for task
type QuadNode struct {
	Val bool
	IsLeaf bool
	TopLeft *QuadNode
	TopRight *QuadNode
	BottomLeft *QuadNode
	BottomRight *QuadNode
}