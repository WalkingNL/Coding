package main

import (
	"fmt"
	"sort"
)

func main() {
	s := "bcad"
	r := []int32(s)
	sort.Slice(r, func(i, j int) bool {
		return r[i] < r[j]
	})
	fmt.Println(string(r)) // "abcd"
}
