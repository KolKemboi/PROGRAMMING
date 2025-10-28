package main

import "fmt"

func main() {
	// basic()
	// insa := "Hello"
	// sayHello(insa)
	// stringActs(insa)
	// numbersActs()
	// lists()
	moreListsStuff()
}

func moreListsStuff() {
	var a [2]string
	a[0] = "Hello"
	a[1] = "world"

	fmt.Println(a)

	var twoD [2][3]int
	for i := 0; i < 2; i++ {
		for j := 0; j < 3; j++ {
			twoD[i][j] = i + j
		}
	}

	fmt.Println(twoD)

}

func lists() {
	primrt := [...]int{1, 2, 3, 4, 6}
	fmt.Println(len(primrt))
	fmt.Println(primrt)
	fmt.Println(primrt[1:])
	fmt.Println(primrt[:0])
}

func numbersActs() {
	digit := 3
	flot := 3.
	compl := 3 + 4i
	bite := byte('a')

	fmt.Println(digit)
	fmt.Println(flot)
	fmt.Println(compl)
	fmt.Println(compl + compl)
	fmt.Println(compl * compl)
	fmt.Println(bite)
}

func stringActs(s1 string) {
	fmt.Println("Len of string", len(s1))
	fmt.Println("slicing... ", s1[0:2])

}

func sayHello(insa string) {
	fmt.Println("You said: ", insa)
}

func basic() {

	fmt.Println("Hello World")

	var s1 string
	s1 = "Learn Go!"
	fmt.Println(s1)

	var b, c int = 1, 2
	fmt.Println(b, c)

	s2 := "Learn Go Again"
	b2, c2 := 3, 4
	d := true
	fmt.Println(s2)
	fmt.Println(b2, c2)
	fmt.Println(d)

}
