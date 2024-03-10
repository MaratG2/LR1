#include <iostream>
#include <fstream>
#include <string>
#include <lib/lr1.h>
#include <filesystem>
#include <limits>

const std::string DATA_PATH = "../../LR1/tests/data/";

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
// 
//8. Ќеоб€зательно ведь c2 больше c1? Ёто не будет считатьс€ ошибкой? Ёто ошибка втора€

void printArray(const std::vector<float>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
            printf("%g", arr[i]);
        else
            printf(" %g", arr[i]);
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    double input_value;
    std::ifstream data_file(DATA_PATH + "Test5_1.txt");
    std::vector<float> arr;
    int len = 0;
    while (data_file >> input_value)
    {
        bool isInBounds = ((static_cast<float>(input_value) >= std::numeric_limits<float>().lowest()) &&
            static_cast<float>(input_value) <= (std::numeric_limits<float>().max()));
        if (isInBounds)
            arr.push_back((float)input_value);
        len++;
    }
    //std::cout << len << " | " << arr.size() << std::endl;
    std::pair<float, float> cs(std::nanf(""), std::nanf(""));
    if (arr.size() > 0 && arr.size() >= len)
    {
        cs.second = arr.back();
        arr.pop_back();
    }
    if (arr.size() > 0 && arr.size() >= len - 1)
    {
        cs.first = arr.back();
        arr.pop_back();
    }
    printf("From: %g | To: %g\n", cs.first, cs.second);
    Result result = process(arr, cs);
    std::cout << "First index and value: " << result.min.first << " | " << result.min.second << std::endl;
    std::cout << "Source elements: ";
    printArray(result.initial);
    std::cout << "\n\nModified elemets: ";
    printArray(result.corrected);
    std::cout << "\nArray of errors:";
    for (int i = 0; i < result.errors.size(); i++)
        std::cout << std::endl << result.errors[i]->ToString();

    return 0;
}