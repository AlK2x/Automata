package main

import (
	"fmt"
	"math"
	"token"
)

func changeStruct(ps *token.FooStruct) {
	ps.B = 100500
	ps.Str = "Sto Pitsot"
}

func changeMap(s *[4]string) {
	s[1] = "changed";
}

var a = [...]string{
	1: "odin",
	2: "dva",
	3: "tri",
}

func main() {
	fmt.Println(a);
	for i, v := range a {
		fmt.Printf("Id: %d contain string: %s\n", i, v )
	}

	changeMap(&a)
	fmt.Println(a)

	fmt.Printf(token.EOF.String());
	fmt.Printf("Now you have %g problems.", math.Nextafter(2, 3))
}