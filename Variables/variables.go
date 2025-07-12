package main

import "fmt"
import "strings"

func main() {
	// Integers In Go
	var val_1 int = 12
	var val_2 int = -12
	var val_3 uint = 255
	fmt.Println(val_1)
	fmt.Println(val_2)
	fmt.Println(val_3)

	var val_4 uint = uint(val_1 + val_2)
	fmt.Println(val_4)

	// floats
	var float_1 float32 = 10.0
	var float_2 float64 = 10.9
	fmt.Println(float_1 + float32(float_2))

	// Strings
	var string_1 string = "Hello"
	var string_2 string = "World"
	var string_3 string = " "
	var HelloWorld = string_1 + string_3 + string_2

	fmt.Println(HelloWorld)
	fmt.Println(strings.ToUpper(HelloWorld))
	fmt.Println(strings.ToLower(HelloWorld))
	fmt.Println(strings.Compare(HelloWorld, "Hell Wrd"))
	fmt.Println(len(HelloWorld))

	// Arrays
	var list_1 [4]uint
	list_1[1] = 10
	list_1[3] = 3
	fmt.Println(list_1)
	fmt.Println(list_1[1:3])

	var list_2 = [...]int{1, 2, 4, 66, 90}
	fmt.Println(list_2)

	var list_3 = []string{"Kol", "Kemboi", "Cheruiyot"}
	fmt.Println(list_3)
	list_3 = append(list_3, "Collind")
	fmt.Println(list_3)

	// HashiMapu
	var hashmap_1 = map[string]int{
		"kol":  20,
		"cher": 30,
	}
	fmt.Println(hashmap_1)
	fmt.Println(hashmap_1["kol"])
	fmt.Println(hashmap_1["cher"])

	var hashmap_2 = map[string][]int{
		"kol":  {1, 2, 3, 5},
		"cher": {10, 20, 30},
	}
	fmt.Println(hashmap_2)
	fmt.Println(hashmap_2["kol"][2:4])
	fmt.Println(hashmap_2["cher"])
}
