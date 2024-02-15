#pragma once

#include <vector>

class Error;
class Result;

Result process(const std::vector<float>& arr, const std::pair<int, int>& cs);