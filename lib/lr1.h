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
    { 2, std::make_shared <Error>(2, "Сообщение ошибки 2")},
    { 3, std::make_shared <Error>(3, "Сообщение ошибки 3")}
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

Result process(const std::vector<float>& arr, const std::pair<float, float>& cs)
{
    std::vector< std::shared_ptr<Error>> errors_caught;

    if (arr.size() > 1024)
    {
        errors_caught.push_back(ERRORS_MAP[1]);
    }

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