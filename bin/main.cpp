#include <iostream>
#include <fstream>
#include <string>
#include <lib/lr1.h>
#include <filesystem>
#include <limits>

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
    std::pair<std::vector<float>, std::pair<float, float>> data = LoadTest("Test1_1.txt");
    std::vector<float> arr = data.first;
    std::pair<float, float> cs = data.second;
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