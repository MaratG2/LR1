#include <iostream>
#include <vector>

#include <lib/lr1.h>
//¬опросы:
//1. (c1, c2) - включительно?
//2. (c1, c2) - индексы?
//3. Ќапечатать исходный и скорректированный массивы: в каком формате? ћожно сначала
//   в одну строку вывести весь исходный, элементы через зап€тую, пробел после зап€той,
//   потом на новой строке новый массив в таком же формате?
//4. ћожно ли оставл€ть после точки нули?

void printArray(const std::vector<float>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
            printf("%f", arr[i]);
        else
            printf(" %f", arr[i]);
    }
}

int main() 
{
    std::vector<float> arr = { 3/7.0, 1933 / 77.0, 12, 15, 999999, 135/17.0*31, 3, -91/5.0, 1/999999.0, 0, 7/9.0, 3.1415, 35};
    std::pair<int, int> cs = {3, 6};
    std::vector<float> result_arr = process(arr, cs);
    std::cout << "Source elements: ";
    printArray(arr);
    std::cout << std::endl;
    std::cout << "Modified elemets:";
    printArray(result_arr);
    std::cout << std::endl;
    return 0;
}