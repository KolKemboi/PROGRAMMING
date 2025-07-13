package main

import (
	"fmt"
	"strings"
)

func main() {
	strings := []string{"kol", "kemboi", "cheruiyot"}
	mapud := everything(strings)
	fmt.Println(mapud)
	printout(mapud)
}

func printout(mapud map[string]map[int]string) {
	for key, value := range mapud {
		for _, value_value := range value {
			fmt.Println(key, " ", value_value)
		}
	}
}

func everything(array []string) map[string]map[int]string {
	mapu := make(map[string]map[int]string)
	for idx, value := range array {
		str_ops := make(map[int]string)

		switch {
		case idx == 0:
			for i := range array {
				str_ops[i] = strings.ToUpper(array[i])
				mapu[value] = str_ops
			}
		case idx == 1:
			for i := range array {
				str_ops[i] = strings.ToLower(array[i])
				mapu[strings.ToUpper(value)] = str_ops
			}
		case idx == 2:
			for i := range array {
				str_ops[i] = strings.ToUpper(array[i])
				mapu[value] = str_ops
			}
		default:
			fmt.Println("")
		}
	}

	return mapu
}
