package main

import "fmt"

func main() {
	var val int = 10
	var pval *int = &val
	fmt.Println(val)
	fmt.Println(pval)
	fmt.Println(*pval)
	*pval = 20
	fmt.Println(val)
	changevalue(&val)
	fmt.Println(val)
}

func changevalue(pval *int) {
	*pval = 100
}
