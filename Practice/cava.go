package main

import (
	"fmt"
	"strconv"
	"strings"
)

const (
	maxBarHeight = 20  // max height of the bar display in rows
	barChar      = "█" // character to draw bars
)

func main() {
	data := `88;176;105;104;92;62;86;51;25;42;22;29;60;33;35;44;57;24;4;35;31;18;42;49;158;303;166;159;141;101;111;108;232;371;288;183;170;96;67;166;116;143;122;228;335;266;395;395;76;242;314;205;239;487;179;229;245;341;323;306;222;154;131;70;125;123;104;34;69;45;23;11;16;9;42;43;23;66;60;29;37;41;25;83;93;100;80;56;45;25;37;91;171;159;74;90;149;114;41;61;45;35;45;46;24;28;18;3;11;28;35;28;13;2;4;10;8;7;5;7;3;1;3;4;5;3;0;0;0;1;2;4;7;4;5;3;8;15;4;10;6;1;0;12;28;35;28;11;3;18;28;24;46;45;35;45;61;41;114;149;90;74;159;171;91;37;25;45;56;80;100;93;83;25;41;37;29;60;66;23;43;42;9;16;11;23;45;69;34;104;123;125;70;131;154;222;306;323;341;245;229;179;487;239;205;314;242;76;395;395;266;335;228;122;143;116;166;67;96;170;183;288;371;232;108;111;101;141;159;159;303;158;49;42;18;31;35;4;24;57;44;35;33;60;29;22;42;25;51;86;62;92;104;105;176;88`

	// Convert string into integer slice
	strVals := strings.Split(data, ";")
	intVals := make([]int, 0, len(strVals))
	maxVal := 0

	for _, s := range strVals {
		if s == "" {
			continue
		}
		n, err := strconv.Atoi(s)
		if err == nil {
			intVals = append(intVals, n)
			if n > maxVal {
				maxVal = n
			}
		}
	}

	// Normalize values to maxBarHeight
	normalized := make([]int, len(intVals))
	for i, val := range intVals {
		normalized[i] = (val * maxBarHeight) / maxVal
	}

	// Draw top-down bar chart
	for row := maxBarHeight; row > 0; row-- {
		for _, h := range normalized {
			if h >= row {
				fmt.Print(barChar)
			} else {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}
