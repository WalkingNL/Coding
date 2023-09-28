package main

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	return x == reverse(x)

}

func reverse(x int) int {
	var result int
	for x != 0 {
		result = result*10 + x%10
		x /= 10
	}
	return result
}

func main() {
	println(isPalindrome(121))
	println(isPalindrome(-121))
	println(isPalindrome(10))
	println(isPalindrome(-101))
	println(isPalindrome(0))
	println(isPalindrome(1))
	println(isPalindrome(11))
	println(isPalindrome(100))
	println(isPalindrome(101))
	println(isPalindrome(111))
	println(isPalindrome(121))
	println(isPalindrome(1221))
	println(isPalindrome(12321))
	println(isPalindrome(123321))
	println(isPalindrome(1234321))
	println(isPalindrome(12344321))
	println(isPalindrome(123454321))
	println(isPalindrome(1234554321))
	println(isPalindrome(12345654321))
	println(isPalindrome(123456654321))
	println(isPalindrome(1234567654321))
	println(isPalindrome(12345677654321))
	println(isPalindrome(123456787654321))
	println(isPalindrome(1234567887654321))
	println(isPalindrome(12345678987654321))
	println(isPalindrome(123456789987654321))
	// println(isPalindrome(1234567891987654321))
	// println(isPalindrome(12345678910987654321))
	// println(isPalindrome(123456789110987654321))
	// println(isPalindrome(1234567891110987654321))
	// println(isPalindrome(12345678911110987654321))
	// println(isPalindrome(123456789111110987654321))
	// println(isPalindrome(1234567891111110987654321))
	// println(isPalindrome(12345678911111110987654321))
	// println(isPalindrome(123456789111111110987654321))
	// println(isPalindrome(1234567891111111110987654321))
	// println(isPalindrome(12345678911111111110987654321))
	// println(isPalindrome(123456789111111111110987654321))
	// println(isPalindrome(1234567891111111111110987654321))
	// println(isPalindrome(12345678911111111111110987654321))
	// println(isPalindrome(123456789111111111111110987654321))
	// println(isPalindrome(1234567891111111111111110987654321))
	// println(isPalindrome(12345678911111111111111110987654321))
	// println(isPalindrome(123456789111111111111111110987654321))
	// println(isPalindrome(1234567891111111111111111110987654321))
	// println(isPalindrome(12345678911111111111111111110987654321))
}
