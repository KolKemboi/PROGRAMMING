package main

import "fmt"

type Usr struct {
	name string
	age  uint
}

func (usr Usr) printdetails() {
	fmt.Println(usr.name, " ", usr.age)
}

func (usr *Usr) changedetails(newName string, newAge uint) {
	usr.name = newName
	usr.age = newAge
}

func main() {
	var usr Usr = Usr{name: "kol", age: 10}
	usr.printdetails()
	usr.changedetails("newName", 100)
	usr.printdetails()
}
