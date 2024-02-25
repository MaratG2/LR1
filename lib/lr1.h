#pragma once

#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <memory>

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

std::map<int, std::shared_ptr<Error>> ERRORS_MAP =
{
    { 1, std::make_shared <Error>(1, "Количество элементов массива не может быть больше 1024")},
    { 2, std::make_shared <Error>(2, "Сообщение об ошибке")},
    { 3, std::make_shared <Error>(3, "Сообщение об ошибке")}
};

class Result
{
public:
    std::pair<int, float> min;
    std::vector<float> initial;
    std::vector<float> corrected;
    std::vector<std::shared_ptr<Error>> errors;
    Result(std::pair<int, float> _min, std::vector<float> _initial,
        std::vector<float> _corrected, std::vector<std::shared_ptr<Error>> _errors)
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
    std::cout << "[TEST OUTPUT] Step: " << step << std::endl;
    return true;
}


Result process(const std::vector<float>& arr, const std::pair<float, float>& cs)
{
    PRINT_STEP(1); //1
    std::vector< std::shared_ptr<Error>> errors_caught; //1
    std::pair<int, float> min(-1, std::nanf("")); //1
    std::vector<float> res = arr; //1

    if (PRINT_STEP(2) && arr.size() > 1024) //2
    {
        PRINT_STEP(3); //3
        errors_caught.push_back(ERRORS_MAP[1]); //3
        Result results(min, arr, res, errors_caught); //3
        PRINT_STEP(4); //4
        return results; //4
    } //4

    PRINT_STEP(5); //5
    bool _notSet = true; //5
    int i = 0; //5

    while (PRINT_STEP(6) && i < arr.size()) //6
    {
        if ((PRINT_STEP(7) && floatLess(arr[i], min.second)) || (PRINT_STEP(8) && _notSet)) //7, 8
        {
            if (PRINT_STEP(9) && floatMore(arr[i], cs.first)) //9
            {
                if (PRINT_STEP(10) && floatLess(arr[i], cs.second)) //10
                {
                    PRINT_STEP(11); //11
                    min.first = i; //11
                    min.second = arr[i]; //11
                    _notSet = false; //11
                } //12
                PRINT_STEP(12); //12
            } //13
            PRINT_STEP(13); //13
        } //14
        PRINT_STEP(14); //14
        i++; //14
    } //15
    PRINT_STEP(15); //15
    PRINT_STEP(16); //16
    i = 0; //16
    while (PRINT_STEP(17) && i < arr.size()) //17
    {
        if (PRINT_STEP(18) && floatMore(res[i], cs.first)) //18
        {
            if (PRINT_STEP(19) && floatLess(res[i], cs.second)) //19
            {
                PRINT_STEP(20); //20
                res[i] = min.second; //20
            } //21
            PRINT_STEP(21); //21
        } //22
        PRINT_STEP(22); //22
        i++; //22
    } //23
    PRINT_STEP(23); //23
    PRINT_STEP(24); //24
    Result results(min, arr, res, errors_caught); //24
    PRINT_STEP(4); //4
    return results;
}