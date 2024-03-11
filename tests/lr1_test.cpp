#include <lib/lr1.h>
#include <fstream>
#include <filesystem>
#include <gtest/gtest.h>
#include <vector>
#include <utility>

const std::string DATA_PATH2 = "./tests/data/";


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

std::vector<float> LoadExpected(std::string name)
{
    std::ifstream data_file(DATA_PATH2 + name);
    std::vector<float> expected_corrected;
    float input_value;
    while (data_file >> input_value)
    {
        expected_corrected.push_back(input_value);
    }
    return expected_corrected;
}

// Тест 1-1
TEST_F(ProcessTest, CTest1_1)
{
    std::vector<float> expected_corrected = LoadExpected("Test1_1_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest("Test1_1.txt");
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};
    errors_expected.push_back(Error(1, "Количество элементов массива не может быть больше 1024"));

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
    if(result.errors.size() > 0 && errors_expected.size() > 0)
        EXPECT_EQ(result.errors[0].ToString(), errors_expected[0].ToString());
    EXPECT_FALSE(true) << result.corrected.size();
}