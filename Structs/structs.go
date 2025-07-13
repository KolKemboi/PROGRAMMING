package main

import "fmt"

type Usr struct {
	name string
	age  int
}

type Moreinfo struct {
	usr  Usr
	info map[string]int
}

func main() {
	var usr Usr = Usr{name: "Kol", age: 10}
	fmt.Println(usr)
	fmt.Println(usr.name)
	fmt.Println(usr.name)
	var info map[string]int = make(map[string]int)
	info["Agee"] = 10
	info["Kenye"] = 1
	var moreinfo Moreinfo = Moreinfo{usr: usr, info: info}
	fmt.Println(moreinfo)
	fmt.Println(moreinfo.usr.name)
	fmt.Println(moreinfo.usr.age)
}
