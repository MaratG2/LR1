#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <memory>

const std::string DATA_PATH = "../../LR1/tests/data/";

class Error
{
public:
    Error(int code, std::string message)
    {
        _code = code;
        _message = message;
    }
    std::string ToString()
    {
        return std::to_string(_code) + ". " + _message;
    }
private:
    int _code;
    std::string _message;
};

class Result
{
public:
    std::pair<int, float> min;
    std::vector<float> initial;
    std::vector<float> corrected;
    std::vector<Error> errors;
    Result(std::pair<int, float> _min, std::vector<float> _initial,
        std::vector<float> _corrected, std::vector<Error> _errors)
    {
        min = _min;
        initial = _initial;
        corrected = _corrected;
        errors = _errors;
    }
};

bool floatEquals(float a, float b, int precision = 6) 
{
    float epsilon = std::pow(10, -precision);
    return std::abs(a - b) < epsilon;
}

bool floatLess(float a, float b, int precision = 6)
{
    float epsilon = std::pow(10, -precision);
    return (b - a) > epsilon;
}

bool floatMore(float a, float b, int precision = 6)
{
    float epsilon = std::pow(10, -precision);
    return (a - b) > epsilon;
}

bool PRINT_STEP(int step) 
{
    //std::cout << "[TEST OUTPUT] Step: " << step << std::endl;
    return true;
}

std::pair<std::vector<float>, std::pair<float, float>> LoadTest(std::string name)
{
    double input_value;
    std::ifstream data_file(DATA_PATH + name);
    std::vector<float> arr;
    int len = 0;
    bool isLastInBounds = false;
    while (data_file >> input_value)
    {
        isLastInBounds = false;
        bool isInBounds = ((static_cast<float>(input_value) >= std::numeric_limits<float>().lowest()) &&
            static_cast<float>(input_value) <= (std::numeric_limits<float>().max()));
        if (isInBounds)
        {
            arr.push_back((float)input_value);
            isLastInBounds = true;
        }
        len++;
    }
    //std::cout << len << " | " << arr.size() << std::endl;
    std::pair<float, float> cs(std::nanf(""), std::nanf(""));
    if (arr.size() > 0 && arr.size() >= len - 1 && isLastInBounds)
    {
        cs.second = arr.back();
        arr.pop_back();
        if (arr.size() >= len - 1)
        {
            cs.first = arr.back();
            arr.pop_back();
        }
    }
    else if (arr.size() > 0 && arr.size() >= len - 1 && !isLastInBounds)
    {
        cs.first = arr.back();
        arr.pop_back();
    }
    else if (arr.size() == 2 && len > 2)
    {
        cs.second = arr.back();
        arr.pop_back();
        cs.first = arr.back();
        arr.pop_back();
    }
    else if (arr.size() == 1 && len > 1 && isLastInBounds)
    {
        cs.second = arr.back();
        arr.pop_back();
    }
    else if (arr.size() == 1 && len > 1 && !isLastInBounds)
    {
        cs.first = arr.back();
        arr.pop_back();
    }
    return std::pair<std::vector<float>, std::pair<float, float>>(arr, cs);
}

Result process(const std::vector<float>& arr, const std::pair<float, float>& cs)
{
    PRINT_STEP(1); //1
    std::vector<Error> errors_caught = {}; //1
    std::pair<int, float> min(-1, std::nanf("")); //1
    std::vector<float> res = arr; //1
    //1
    if (PRINT_STEP(2) && arr.size() > 1024) //2
    {
        PRINT_STEP(3); //3
        errors_caught.push_back(Error(1, "Количество элементов массива не может быть больше 1024")); //3
        Result results(min, arr, res, errors_caught); //3
        PRINT_STEP(27); //27
        return results; //27
    } //27
    //4
    if (PRINT_STEP(4) && floatMore(cs.first, cs.second)) //4
    {
        PRINT_STEP(5); //5
        errors_caught.push_back(Error(2, "Нижняя граница не может быть больше верхней границы")); //5
        Result results(min, arr, res, errors_caught); //5
        PRINT_STEP(27); //27
        return results; //27
    } //27

    PRINT_STEP(6); //6
    int i = 0; //6

    while (PRINT_STEP(7) && i < arr.size()) //7
    {
        if (PRINT_STEP(8) && floatMore(arr[i], cs.first)) //8
        {
            if (PRINT_STEP(9) && floatLess(arr[i], cs.second)) //9
            {
                if (PRINT_STEP(10) && floatLess(arr[i], min.second)) //10
                {
                    PRINT_STEP(11); //11
                    min.first = i; //11
                    min.second = arr[i]; //11
                } //13
                else if (PRINT_STEP(12) && min.first == -1) //12
                {
                    PRINT_STEP(11); //11
                    min.first = i; //11
                    min.second = arr[i]; //11
                } //13
                PRINT_STEP(13); //13
            } //14
            PRINT_STEP(14); //14
        } //15
        PRINT_STEP(15); //15
        PRINT_STEP(16); //16
        i++; //16
    } //17
    PRINT_STEP(17); //17
    PRINT_STEP(18); //18
    i = 0; //18
    while (PRINT_STEP(19) && i < arr.size()) //19
    {
        if (PRINT_STEP(20) && floatMore(res[i], cs.first)) //20
        {
            if (PRINT_STEP(21) && floatLess(res[i], cs.second)) //21
            {
                PRINT_STEP(22); //22
                res[i] = min.second; //22
            } //23
            PRINT_STEP(23); //23
        } //24
        PRINT_STEP(24); //24
        PRINT_STEP(25); //25
        i++; //25
    } //26
    PRINT_STEP(26); //26
    PRINT_STEP(27); //27
    Result results(min, arr, res, errors_caught); //27
    return results; //27
}