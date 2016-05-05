package main

import "fmt"

func main() {
    var flags [3]bool
    powers := [5]int{1, 2, 4, 8, 16}
    identity := [2][2]float64{{1,0},{0,1}}

    actual := fmt.Sprintf("%v %v %v", flags, powers, identity)
    expected := "[false false false] [1 2 4 8 16] [[1 0] [0 1]]"
    if actual != expected {panic("")}
}
