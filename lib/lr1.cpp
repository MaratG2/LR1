#include "lr1.h"

std::vector<float> process(const std::vector<float>& arr, const std::pair<int, int>& cs) 
{
    float min_element = arr[cs.first];
    std::vector<float> results = arr;
    for (int i = cs.first; i <= cs.second; i++)
    {
        if (results[i] < min_element)
            min_element = results[i];
    }

    for (int i = cs.first; i <= cs.second; i++)
    {
        results[i] = min_element;
    }

    return results;
}