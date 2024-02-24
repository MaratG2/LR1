#include <iostream>
#include <fstream>
#include <string>
#include <lib/lr1.h>
#include <filesystem>

const std::string DATA_PATH = "../../LR1/Data/";

//¬опросы:
//1. (c1, c2) - включительно? включительно
// если несколько минимальных, то первый возвращаем, даже если одинаковые есть
//2. (c1, c2) - индексы? - сами действительные числа. 
//   “о есть минимум не может быть меньше c1. Ќам нужно вз€ть степень точности, с которой провер€ть
//3. Ќапечатать исходный и скорректированный массивы: оба печатать, чтобы отследить
//   в каком формате? ћожно сначала
//   в одну строку вывести весь исходный, элементы через зап€тую, пробел после зап€той,
//   потом на новой строке новый массив в таком же формате?
// печатать не надо, мы их возвращаемы, мы не печатаем , точность - 6 могу - надо объ€снить, почему не 7 и не 8? 
//4. ћожно ли оставл€ть после точки нули?
//5. ѕочему сравнение векторов 2 теста не проход€т, хот€ должны?
//6. ƒелать ли ввод размера массива и элементов массива? »ли можно заранее заданные. 
//   ћаксимум 1024 элемента, больше можно - провер€ть.
//7. ћассив ошибок -  аждую ошибку на новой строке выводить, формат например код: по€снение? 
//    ласс сделать с двум€ пол€ми, вектор классов?
//   ¬озвращаем структуру данных
//   ≈сли не нашлось, то минмум и индекс возвращать какие? -1 дл€ индекса и std::nanf дл€ значени€

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
    setlocale(LC_ALL, "Russian");

    float input_value;
    std::ifstream data_file(DATA_PATH + "data1025.txt");
    std::vector<float> arr;
    while (data_file >> input_value)
        arr.push_back(input_value);
    std::pair<float, float> cs;
    cs.second = arr.back();
    arr.pop_back();
    cs.first = arr.back();
    arr.pop_back();

    std::cout << "From: " << cs.first << " | To: " << cs.second << std::endl;
    Result result = process(arr, cs);
    std::cout << "First index and value: " << result.min.first << " | " << result.min.second << std::endl;
    std::cout << "Source elements: ";
    printArray(result.initial);
    std::cout << "\nModified elemets: ";
    printArray(result.corrected);
    std::cout << "\nArray of errors:";
    for (int i = 0; i < result.errors.size(); i++)
        std::cout << std::endl << result.errors[i]->ToString();

    return 0;
}