#include <lib/lr1.h>
#include <fstream>
#include <filesystem>
#include <gtest/gtest.h>
#include <vector>
#include <utility>
namespace fs = std::filesystem;

const std::string DATA_PATH2 = "../tests/data/";


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
    std::ifstream data_file2(DATA_PATH2+name);
    std::vector<float> expected_corrected;
    double input_value;
    while (data_file2 >> input_value)
    {
        expected_corrected.push_back((float)input_value);
    }
    return expected_corrected;
}

// Тест 1-1
TEST_F(ProcessTest, CTest1_1)
{
    std::vector<float> expected_corrected = LoadExpected("Test1_1_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2+"Test1_1.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};
    errors_expected.push_back(Error(1, "Number of elements should not be more than 1024"));

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 2-1
TEST_F(ProcessTest, CTest2_1)
{
    std::vector<float> expected_corrected = LoadExpected("Test2_1_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test2_1.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};
    errors_expected.push_back(Error(2, "Lower bound should not be more than higher bound"));

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 3-1
TEST_F(ProcessTest, CTest3_1)
{
    std::vector<float> expected_corrected = LoadExpected("Test3_1_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test3_1.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 4-1
TEST_F(ProcessTest, CTest4_1)
{
    std::vector<float> expected_corrected = LoadExpected("Test4_1_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test4_1.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 4-2
TEST_F(ProcessTest, CTest4_2)
{
    std::vector<float> expected_corrected = LoadExpected("Test4_2_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test4_2.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 4-3
TEST_F(ProcessTest, CTest4_3)
{
    std::vector<float> expected_corrected = LoadExpected("Test4_3_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test4_3.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 4-4
TEST_F(ProcessTest, CTest4_4)
{
    std::vector<float> expected_corrected = LoadExpected("Test4_4_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test4_4.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}


// Тест 4-5
TEST_F(ProcessTest, CTest4_5)
{
    std::vector<float> expected_corrected = LoadExpected("Test4_5_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test4_5.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 4-6
TEST_F(ProcessTest, CTest4_6)
{
    std::vector<float> expected_corrected = LoadExpected("Test4_6_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test4_6.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 4-7
TEST_F(ProcessTest, CTest4_7)
{
    std::vector<float> expected_corrected = LoadExpected("Test4_7_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test4_7.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 5-1
TEST_F(ProcessTest, CTest5_1)
{
    std::vector<float> expected_corrected = LoadExpected("Test5_1_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test5_1.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 5-2
TEST_F(ProcessTest, CTest5_2)
{
    std::vector<float> expected_corrected = LoadExpected("Test5_2_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test5_2.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 5-3
TEST_F(ProcessTest, CTest5_3)
{
    std::vector<float> expected_corrected = LoadExpected("Test5_3_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test5_3.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 5-4
TEST_F(ProcessTest, CTest5_4)
{
    std::vector<float> expected_corrected = LoadExpected("Test5_4_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test5_4.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 5-5
TEST_F(ProcessTest, CTest5_5)
{
    std::vector<float> expected_corrected = LoadExpected("Test5_5_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test5_5.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 5-6
TEST_F(ProcessTest, CTest5_6)
{
    std::vector<float> expected_corrected = LoadExpected("Test5_6_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test5_6.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 5-7
TEST_F(ProcessTest, CTest5_7)
{
    std::vector<float> expected_corrected = LoadExpected("Test5_7_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test5_7.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 6-1
TEST_F(ProcessTest, CTest6_1)
{
    std::vector<float> expected_corrected = LoadExpected("Test6_1_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test6_1.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(96, -2.42944e+38f);
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 6-2
TEST_F(ProcessTest, CTest6_2)
{
    std::vector<float> expected_corrected = LoadExpected("Test6_2_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test6_2.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(545, -1.41651e+37f);
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 6-3
TEST_F(ProcessTest, CTest6_3)
{
    std::vector<float> expected_corrected = LoadExpected("Test6_3_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test6_3.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 6-4
TEST_F(ProcessTest, CTest6_4)
{
    std::vector<float> expected_corrected = LoadExpected("Test6_4_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test6_4.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 6-5
TEST_F(ProcessTest, CTest6_5)
{
    std::vector<float> expected_corrected = LoadExpected("Test6_5_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test6_5.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 6-6
TEST_F(ProcessTest, CTest6_6)
{
    std::vector<float> expected_corrected = LoadExpected("Test6_6_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test6_6.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(-1, std::nanf(""));
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_FALSE(result.min.second == result.min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_FALSE(expected_min.second == expected_min.second); //Убеждаемся, что минимума нет - он NaN
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 6-7
TEST_F(ProcessTest, CTest6_7)
{
    std::vector<float> expected_corrected = LoadExpected("Test6_7_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test6_7.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(0, -3.39504e+38f);
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 6-8
TEST_F(ProcessTest, CTest6_8)
{
    std::vector<float> expected_corrected = LoadExpected("Test6_8_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test6_8.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(440, -1.92662e+38f);
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}

// Тест 6-9
TEST_F(ProcessTest, CTest6_9)
{
    std::vector<float> expected_corrected = LoadExpected("Test6_9_expected.txt");
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest(DATA_PATH2 + "Test6_9.txt", true);
    std::vector<float> got_arr_initial = data.first;
    std::pair<float, float> got_cs = data.second;

    // Вызываем функцию process с тестовыми данными
    Result result = process(got_arr_initial, got_cs);

    // Проверяем ожидаемые результаты
    std::pair<int, float> expected_min(920, -1.53413e+38f);
    std::vector<Error> errors_expected = {};

    EXPECT_EQ(result.initial, got_arr_initial);
    EXPECT_EQ(result.corrected, expected_corrected);
    EXPECT_EQ(result.min.first, expected_min.first);
    EXPECT_EQ(result.errors.size(), errors_expected.size());
}