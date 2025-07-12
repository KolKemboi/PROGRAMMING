package main

import (
	"fmt"
	"strings"
)

func main() {
	str_1 := "Hello Functions"
	fmt.Println(strings.ToUpper(str_1))

	printMaps()

	slice_1 := []uint{1, 2, 3, 4, 5}
	sum := addList(slice_1)
	fmt.Println(sum)

	array_1 := []int{100, 2, 15, 3, 12, 10}
	fizzbuzz := FizzBuzz(array_1)
	fmt.Println(fizzbuzz)

}

func FizzBuzz(array []int) map[int]string {
	fizzbuzz := make(map[int]string)
	for _, val := range array {
		if val%15 == 0 {
			fizzbuzz[val] = "FizzBuzz"
		} else if val%5 == 0 {
			fizzbuzz[val] = "Buzz"
		} else if val%3 == 0 {
			fizzbuzz[val] = "Fizz"
		} else {
			fizzbuzz[val] = "None"
		}
	}
	return fizzbuzz
}

func printMaps() {
	map_1 := map[string]int{
		"kol_1": 10, "kol_2": 20, "kol_3": 30,
	}
	for key, value := range map_1 {
		fmt.Println(key, value)
	}
}

func addList(array []uint) uint {
	var sum uint = 0
	for _, val := range array {
		sum += val
	}
	return sum
}
