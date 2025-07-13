package main

import "fmt"

type Employee struct {
	name string
	age  uint
}

func (e *Employee) Setter(name string, age uint) {
	e.name = name
	e.age = age
}

func (e Employee) Echo() {
	fmt.Println(e.name, " ", e.age)
}

type Boss struct {
	name string
	age  uint
}

func (e *Boss) Setter(name string, age uint) {
	e.name = name
	e.age = age
}

func (e Boss) Echo() {
	fmt.Println(e.name, " ", e.age)
}

type info interface {
	Echo()
}

func makeItSing(i info) {
	i.Echo()
}

func main() {
	e := Employee{}
	e.Setter("kol", 30)
	makeItSing(e)

	b := Boss{}
	b.Setter("KOL", 300)
	makeItSing(b)
}
