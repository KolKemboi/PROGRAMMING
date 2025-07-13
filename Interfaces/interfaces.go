package main

import "fmt"

type Cat struct{}

func (cat Cat) speak() {
	fmt.Println("Hi I am Kitty")
}

type Dog struct{}

func (dog Dog) speak() {
	fmt.Println("Hello I am Doggy")
}

type AnimSpeak interface {
	speak()
}

func makeItSpeak(a AnimSpeak) {
	a.speak()
}

func main() {
	cat := Cat{}
	dog := Dog{}

	makeItSpeak(cat)
	makeItSpeak(dog)

}
