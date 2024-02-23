#include <iostream>
#include <vector>

#include <lib/lr1.h>

int main() {
    std::vector<int> arr = {10, 14, 15, 20, 21, 25, 30};
    std::pair<int, int> result = countAndSum(arr);
    std::cout << "Number of elements that are divisible by 5 and not divisible by 7: " << result.first << std::endl;
    std::cout << "Sum: " << result.second << std::endl;
    return 0;
}