package main

import (
	"fmt"
	"strings"
)

func main() {

	val_1 := 32
	val_2 := 33

	// if else control flow
	if val_1 > val_2 {
		fmt.Println("Hello")
	} else if val_2 > val_1 {
		fmt.Println("World")
	} else {
		fmt.Println("Hello Worlf")
	}

	// Switch statements
	switch {
	case val_1 == val_2:
		fmt.Println("Hjkhdfajsdklf")
	case val_1 < val_2:
		fmt.Println("mkjhkldfjl;as")
	case val_1 > val_2:
		fmt.Println("fdlg;jklfsjkglsfdjgk")
	default:
		fmt.Println("exit code _1")
	}

	// weird if clause
	if i := 2; i != 10 {
		fmt.Println("This Works for Some reason")
	}

	str_1 := "Hello"
	fmt.Println(strings.ToUpper(str_1))
	map_1 := map[string][]int{
		"kol": {1, 2, 3, 5, 6},
	}
	map_1["zheru"] = []int{11, 22, 33, 55, 66}
	map_1["kem"] = []int{111, 222, 333, 555, 666}
	list_1 := []int{10, 20, 30, 40, 50}

	fmt.Println(map_1)
	fmt.Println(list_1)
	// ----LOOPOS

	for i := 1; i < 10; i++ {
		fmt.Println(i)
	}

	for idx, val := range map_1["kem"] {
		fmt.Println(idx, "=>", val)
	}

	for key, val := range map_1 {
		for idx, val_val := range val {
			fmt.Println(key, " ", idx, " ", val_val)
		}
	}
}
