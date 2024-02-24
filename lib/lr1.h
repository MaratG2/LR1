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
    PRINT_STEP(1);
    std::vector< std::shared_ptr<Error>> errors_caught; //1
    std::pair<int, float> min(-1, std::nanf("")); //1
    std::vector<float> res = arr; //1

    if (arr.size() > 1024)
    {
        errors_caught.push_back(ERRORS_MAP[1]);
        Result results(min, arr, res, errors_caught);
        return results;
    }

    bool _notSet = true;

    for (int i = 0; i < arr.size(); i++)
    {
        if (floatLess(arr[i], min.second) || _notSet)
        {
            if (floatMore(arr[i], cs.first))
            {
                if (floatLess(arr[i], cs.second))
                {
                    min.first = i;
                    min.second = arr[i];
                    _notSet = false;
                }
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (floatMore(res[i], cs.first))
        {
            if (floatLess(res[i], cs.second))
            {
                res[i] = min.second;
            }
        }
    }

    Result results(min, arr, res, errors_caught);

    return results;
}