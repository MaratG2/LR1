#pragma once

#include <vector>
#include <string>
#include <cmath>
#include <map>

class Error
{
public:
    int code;
    std::string message;
    Error(int _code, std::string _message)
    {
        code = _code;
        message = _message;
    }
    std::string ToString()
    {
        return code + ". " + message;
    }
};

std::map<int, Error*> ERRORS_MAP =
{
    { 1, new Error(1, "Сообщение ошибки 1")},
    { 2, new Error(2, "Сообщение ошибки 2")},
    { 3, new Error(3, "Сообщение ошибки 3") }
};

class Result
{
public:
    std::pair<int, float> min;
    std::vector<float> initial;
    std::vector<float> corrected;
    std::vector<Error> errors;
    Result(std::pair<int, float> _min, std::vector<float> _initial, std::vector<float> _corrected, std::vector<Error> _errors)
    {
        min = _min;
        initial = _initial;
        corrected = _corrected;
        errors = _errors;
    }
};

Result process(const std::vector<float>& arr, const std::pair<float, float>& cs)
{
    std::vector<Error> errors_caught;
    std::pair<int, float> min(-1, std::nanf(""));
    std::vector<float> res = arr;
    bool _notSet = true;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min.second || _notSet)
        {
            if (arr[i] > cs.first)
            {
                if (arr[i] < cs.second)
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
        if (res[i] > cs.first)
        {
            if (res[i] < cs.second)
            {
                res[i] = min.second;
            }
        }
    }

    Result results(min, arr, res, errors_caught);

    return results;
}