#include <iostream>
#include <vector>
#include "helper_things.cpp"
#include "43_multiply_strings.cpp"

int main() {
    std::cout << Solution().multiply("123", "0") << std::endl;
    std::cout << Solution().multiply("123", "123123") << std::endl;
    std::cout << Solution().multiply("1223523523452545435123123213213312123123123123123213343453", "1232311241241241212312312312213123213123213213123123123213123123123123123123123213122121312312312123123123123123124124124124") << std::endl;
}
