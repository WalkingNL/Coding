#include <functional>
#include <iostream>

std::function<int(int)> make_adder(int x) {
    return x { return x + y; };
}

int main() {
    auto add5 = make_adder(5);
    auto add10 = make_adder(10);
    std::cout << add5(3) << std::endl;  // prints 8
    std::cout << add10(3) << std::endl; // prints 13
}
