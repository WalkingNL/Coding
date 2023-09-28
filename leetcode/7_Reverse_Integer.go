package main

func reverse(x int) int {

	var result int = 0

	// 2,147,483,648
	for x != 0 {

		if result > 214748364 || result < -214748364 {
			return 0
		}

		result = result*10 + x%10
		x /= 10
	}

	return result
}

func main() {

	println(reverse(123))
	println(reverse(-123))
	println(reverse(120))
	println(reverse(0))
	println(reverse(1534236469))
	println(reverse(-2147483648))
	println(reverse(-2147483412))
}
