#include "lr1.h"

std::pair<int, int> countAndSum(const std::vector<int>& array) {
    int count = 0;
    int total = 0;
    for (int num : array) {
        if (num % 5 == 0 && num % 7 != 0) {
            count++;
            total += num;
        }
    }
    return std::make_pair(count, total);
}