#include <lib/lr1.h>
#include <gtest/gtest.h>
#include <vector>
#include <utility>

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
        arr = { 3 / 7.0, 1933 / 77.0, 12, 15, 999999, 135 / 17.0 * 31, 3, -91 / 5.0, 1 / 9999999.0, 0, 7 / 9.0, 3.1415, 35 };
        cs = { 2, 5 };
    }

    // Здесь вы можете освободить ресурсы, если это необходимо
    // в функции TearDown()
    void TearDown() override 
    {
        // Например, очистка данных
        arr.clear();
    }

    // Объявляем переменные, которые будут использоваться в тестах
    std::vector<float> arr;
    std::pair<int, int> cs;
    std::vector<float> result;
};

// Пример теста1
TEST_F(ProcessTest, CTest1) 
{
// Вызываем функцию process с тестовыми данными
    result = process(arr, cs);

// Проверяем ожидаемые результаты
    std::vector<float> expected_result = { 0.428571, 25.103895, 12.000000, 12.000000,
        12.000000, 12.000000, 3.000000, -18.200001, 0.000000, 0.000000, 0.777778, 3.141500, 35.000000 };
    EXPECT_EQ(result, expected_result);
}

// Пример теста2
TEST_F(ProcessTest, CTest2)
{
// Вызываем функцию process с тестовыми данными
    std::pair<int, int> test_cs = { 2, 6 };
    result = process(arr, cs);

// Проверяем ожидаемые результаты
    std::vector<float> expected_result = { 0.428571, 25.103895, 3.000000, 3.000000,
        3.000000, 3.000000, 3.000000, -18.200001, 0.000000, 0.000000, 0.777778, 3.141500, 35.000000 };
    EXPECT_EQ(result, expected_result);
}
