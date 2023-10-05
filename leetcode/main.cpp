#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include "helper_things"

int main() {
    std::vector<std::vector<int>> prerequisite = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}};
    std::cout << Solution().snakesAndLadders(prerequisite) << std::endl;
    prerequisite = {{-1, -1}, {-1, 3}};
    std::cout << Solution().snakesAndLadders(prerequisite) << std::endl;
    prerequisite = {{-1,1,2,-1},{2,13,15,-1},{-1,10,-1,-1},{-1,6,2,8}};
    std::cout << Solution().snakesAndLadders(prerequisite) << std::endl;
    prerequisite = {
        {-1,-1,27,13,-1,25,-1},
        {-1,-1,-1,-1,-1,-1,-1},
        {44,-1,8,-1,-1,2,-1},
        {-1,30,-1,-1,-1,-1,-1},
        {3,-1,20,-1,46,6,-1},
        {-1,-1,-1,-1,-1,-1,29},
        {-1,29,21,33,-1,-1,-1}
        };
    std::cout << Solution().snakesAndLadders(prerequisite) << std::endl;
    prerequisite = {{-1,1,1,1},{-1,7,1,1},{1,1,1,1},{-1,1,9,1}};
    std::cout << Solution().snakesAndLadders(prerequisite) << std::endl;
    
}
