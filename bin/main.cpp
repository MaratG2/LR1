#include <iostream>
#include <fstream>
#include <string>
#include <lib/lr1.h>
#include <filesystem>
#include <limits>

const std::string DATA_PATH = "../../LR1/tests/data/";

//�������:
//1. (c1, c2) - ������������? ������������
// ���� ��������� �����������, �� ������ ����������, ���� ���� ���������� ����
//2. (c1, c2) - �������? - ���� �������������� �����. 
//   �� ���� ������� �� ����� ���� ������ c1. ��� ����� ����� ������� ��������, � ������� ���������
//3. ���������� �������� � ����������������� �������: ��� ��������, ����� ���������
//   � ����� �������? ����� �������
//   � ���� ������ ������� ���� ��������, �������� ����� �������, ������ ����� �������,
//   ����� �� ����� ������ ����� ������ � ����� �� �������?
// �������� �� ����, �� �� �����������, �� �� �������� , �������� - 6 ���� - ���� ���������, ������ �� 7 � �� 8? 
//4. ����� �� ��������� ����� ����� ����?
//5. ������ ��������� �������� 2 ����� �� ��������, ���� ������?
//6. ������ �� ���� ������� ������� � ��������� �������? ��� ����� ������� ��������. 
//   �������� 1024 ��������, ������ ����� - ���������.
//7. ������ ������ - ������ ������ �� ����� ������ ��������, ������ �������� ���: ���������? 
//   ����� ������� � ����� ������, ������ �������?
//   ���������� ��������� ������
//   ���� �� �������, �� ������ � ������ ���������� �����? -1 ��� ������� � std::nanf ��� ��������
// 
//8. ������������� ���� c2 ������ c1? ��� �� ����� ��������� �������? ��� ������ ������

void printArray(const std::vector<float>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
            printf("%g", arr[i]);
        else
            printf(" %g", arr[i]);
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    double input_value;
    std::ifstream data_file(DATA_PATH + "data_range_out1.txt");
    std::vector<float> arr;
    while (data_file >> input_value)
    {
        bool isInBounds = ((input_value > (double)(- 1 * std::numeric_limits<float>().max())) &&
                            input_value < (double)(std::numeric_limits<float>().max()));
        if (isInBounds)
            arr.push_back((float)input_value);
    }
    if (arr.size() < 2)
    {
        std::cout << "������ ������� �������";
        return 0;
    }
    std::pair<float, float> cs;
    cs.second = arr.back();
    arr.pop_back();
    cs.first = arr.back();
    arr.pop_back();
    printf("From: %g | To: %g\n", cs.first, cs.second);
    Result result = process(arr, cs);
    std::cout << "First index and value: " << result.min.first << " | " << result.min.second << std::endl;
    std::cout << "Source elements: ";
    printArray(result.initial);
    std::cout << "\n\nModified elemets: ";
    printArray(result.corrected);
    std::cout << "\nArray of errors:";
    for (int i = 0; i < result.errors.size(); i++)
        std::cout << std::endl << result.errors[i]->ToString();

    return 0;
}