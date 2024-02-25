#include <lib/lr1.h>
#include <fstream>
#include <filesystem>
#include <gtest/gtest.h>
#include <vector>
#include <utility>

const std::string DATA_PATH = "../../LR1/Data/";


// Подробнее https://google.github.io/googletest/reference/testing.html

// Тестовый класс
class ProcessTest : public ::testing::Test
{
protected:
    // Здесь вы можете добавить дополнительные настройки для тестов
    // в функции SetUp()
    void SetUp() override 
    {
        // Например, инициализация данных
    }

    // Здесь вы можете освободить ресурсы, если это необходимо
    // в функции TearDown()
    void TearDown() override 
    {
        // Например, очистка данных
    }

    // Объявляем переменные, которые будут использоваться в тестах
};

// Пример теста1
TEST_F(ProcessTest, CTest1) 
{
    float input_value;
    std::ifstream data_file(DATA_PATH + "test1.txt");
    std::vector<float> arr;
    while (data_file >> input_value)
        arr.push_back(input_value);
    std::pair<float, float> cs;
    cs.second = arr.back();
    arr.pop_back();
    cs.first = arr.back();
    arr.pop_back();

// Вызываем функцию process с тестовыми данными
    Result result = process(arr, cs);

// Проверяем ожидаемые результаты
    std::vector<float> expected_initial = {};
    std::vector<float> expected_corrected = {};
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<std::shared_ptr<Error>> errors_caught;

    EXPECT_EQ(result.initial, expected_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_EQ(result.min.second, expected_min.second);
    EXPECT_EQ(result.errors, errors_caught);
}

// Пример теста2
TEST_F(ProcessTest, CTest2)
{
// Вызываем функцию process с тестовыми данными
    std::pair<int, int> test_cs = { 2, 6 };
    result = process(arr, test_cs);

// Проверяем ожидаемые результаты
    std::vector<float> expected_result = { 3 / 7.0, 1933 / 77.0, 3, 3, 3, 3, 3, -91 / 5.0, 1 / 9999999.0, 0, 7 / 9.0, 3.1415, 35 };
    EXPECT_EQ(result, expected_result);
}
