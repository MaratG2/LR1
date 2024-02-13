#include <iostream>
#include <vector>

#include <lib/lr1.h>
//Вопросы:
//1. (c1, c2) - включительно?
//2. (c1, c2) - индексы?
//3. Напечатать исходный и скорректированный массивы: в каком формате? Можно сначала
//   в одну строку вывести весь исходный, элементы через запятую, пробел после запятой,
//   потом на новой строке новый массив в таком же формате?
//4. Можно ли оставлять после точки нули?
//5. Почему сравнение векторов 2 теста не проходят, хотя должны?
//6. Делать ли ввод размера массива и элементов массива? Или можно заранее заданные

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
    std::vector<float> arr = { 3/7.0, 1933 / 77.0, 12, 15, 999999, 135/17.0*31, 3, -91/5.0, 1/9999999.0, 0, 7/9.0, 3.1415, 35};
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