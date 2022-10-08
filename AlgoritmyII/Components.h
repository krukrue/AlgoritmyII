#pragma once
#include <iostream>
#include <chrono>
#include "Equation.h"

template<class T>
class Components
{
public:
    static void CreateArraySequenceValues(T*&, unsigned int);
    static void CreateArrayRandomValues(T*&, unsigned int);
    static void DuplicateArray(T*, unsigned int, T*&);
    static void InitializeElements(T**&, unsigned int, unsigned int);
    static void DeleteElements(T**&, unsigned int);
    static void SwapValues(T&, T&);
    static void PrintElements(T*, unsigned int, char = ';');
    static void PrintMatrix(Equation);
    static void PrintMatrix(T**, unsigned int);
    static void PrintMatrixWithElementsB(Equation);
    static void PrintMatrixResult(Equation, float*);

    static int Compare(const void*, const void*);
    static void MeasureMethod(void(*)(void*), void*);
    static void MeasureMethodTask1(void(*)(void*, int), void*, int);
};

template<class T>
void Components<T>::CreateArraySequenceValues(T*& elements, unsigned int elementsLength)
{
    for (unsigned int i = 0; i < elementsLength; i++)
    {
        elements[i] = i;
    }
}

template<class T>
void Components<T>::CreateArrayRandomValues(T*& elements, unsigned int elementsLength)
{
    srand(time(0));

    for (unsigned int i = 0; i < elementsLength; i++)
    {
        elements[i] = 1 + (rand() % 10);
    }
}

template<class T>
void Components<T>::DuplicateArray(T* elements, unsigned int elementsLength, T*& elementsOutput)
{
    for (unsigned int i = 0; i < elementsLength; i++)
    {
        elementsOutput[i] = elements[i];
    }
}

template<class T>
void Components<T>::InitializeElements(T**& elements, unsigned int elementsLength, unsigned int initializeLength)
{
    for (unsigned int i = 0; i < elementsLength; i++)
    {
        elements[i] = new T[initializeLength];
    }
}

template<class T>
void Components<T>::DeleteElements(T**& elements, unsigned int elementsLength)
{
    for (unsigned int i = 0; i < elementsLength; i++)
    {
        delete[] elements[i];
    }
}

template<class T>
void Components<T>::SwapValues(T& a, T& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

template<class T>
void Components<T>::PrintElements(T* elements, unsigned int elementsLength, char separator)
{
    std::cout << '{';
    for (unsigned int i = 0; i < elementsLength; i++)
    {
        std::cout << elements[i] << separator;
    }
    std::cout << '}' << std::endl;
}

template<class T>
inline void Components<T>::PrintMatrix(Equation equation)
{
    //std::cout << "A matrix:" << std::endl;
    for (unsigned int i = 0; i < equation.size; i++)
    {
        Components<float>::PrintElements(equation.matrixA[i], equation.size, '\t');
    }
}

template<class T>
inline void Components<T>::PrintMatrix(T** matrix, unsigned int size)
{
    //std::cout << "A matrix:" << std::endl;
    for (unsigned int i = 0; i < size; i++)
    {
        Components<float>::PrintElements(matrix[i], size, '\t');
    }
}

template<class T>
void Components<T>::PrintMatrixWithElementsB(Equation equation)
{
    //std::cout << "A matrix with all ElementsB:" << std::endl;
    for (unsigned int i = 0; i < equation.size; i++)
    {
        std::cout << '{';
        for (unsigned int j = 0; j < equation.size; j++)
        {
            std::cout << equation.matrixA[i][j] << '\t';
        }
        std::cout << '|' << '\t' << equation.elementsB[i] << '\t';
        std::cout << '}' << std::endl;
    }
}

template<class T>
void Components<T>::PrintMatrixResult(Equation equation, float* result)
{
    std::cout << "Final result of the matrix:" << std::endl;
    for (unsigned int i = 0; i < equation.size; i++)
    {
        Components<float>::PrintElements(equation.matrixA[i], equation.size + 1, '\t');
    }

    std::cout << "X results:" << std::endl;
    for (unsigned int i = 0; i < equation.size; i++)
        std::cout << 'X' << i << ": " << result[i] << std::endl;
}

template<class T>
int Components<T>::Compare(const void* a, const void* b)
{
    if (*(int*)a < *(int*)b) return -1;
    if (*(int*)a == *(int*)b) return 0;
    if (*(int*)a > *(int*)b) return 1;
}

template<class T>
void Components<T>::MeasureMethod(void (*function)(void*), void* context)
{
    auto start = std::chrono::high_resolution_clock::now();
    function(context);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;
}

template<class T>
void Components<T>::MeasureMethodTask1(void (*function)(void*, int), void* context, int sumValue)
{
    auto start = std::chrono::high_resolution_clock::now();
    function(context, sumValue);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;
}