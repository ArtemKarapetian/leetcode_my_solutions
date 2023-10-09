#include <iostream>
#include <vector>
#include "helper_things.cpp"
#include "77_combinations.cpp"

int main() {
    Helper().PrintVectorVectorInt(Solution().combine(4, 2));
    Helper().PrintVectorVectorInt(Solution().combine(1, 1));
}
