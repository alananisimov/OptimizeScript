package main

import (
	"bufio"

	"fmt"

	"os"

	"unicode"
)

func main() {

	file, err := os.Open("str.txt")

	if err != nil {

		fmt.Println("Error opening file:", err)

		return

	}

	defer file.Close()

	scanner := bufio.NewScanner(file)

	scanner.Scan()

	textLine := scanner.Text()

	modifiedText := ""

	for _, char := range textLine {

		if unicode.ToTitle(char) == 's' || unicode.ToTitle(char) == 'S' {

			modifiedText += "!" + string(char)

		} else {

			modifiedText += string(char)

		}

	}

	fmt.Println(modifiedText)

}
