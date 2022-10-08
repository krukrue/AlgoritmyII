#pragma once
#include "Equation.h"
#include "Components.h"

class Exercise2
{
private:

public:
    template <size_t rows, size_t cols>
    void GaussianForwardElimination(float[rows][cols], unsigned int, float[rows], bool(*)(Equation&));
    template <size_t rows, size_t cols>
    void GaussianForwardElimination1(float[rows][cols], unsigned int, bool(*)(Equation&));

    static bool ForwardElimination(Equation&);
    static bool BetterForwardElimination(Equation&);
    static void BackSubstitution(Equation&, float*&);
    static bool LinearDecomposition(Equation&);
};



template<size_t rows, size_t cols>
void Exercise2::GaussianForwardElimination(float matrixA[rows][cols], unsigned int size, float elementsB[rows], bool (*eliminationMethod)(Equation&))
{
    Equation equation;
    equation.size = size;
    equation.matrixA = new float* [equation.size];
    equation.elementsB = new float[equation.size];

    // Initialization of matrixA
    Components<float>::InitializeElements(equation.matrixA, equation.size, equation.size + 1);

    // Duplication of values for our Equation structure
    for (unsigned int i = 0; i < equation.size; i++)
    {
        Components<float>::DuplicateArray(matrixA[i], equation.size, equation.matrixA[i]);
    }
    Components<float>::DuplicateArray(elementsB, equation.size, equation.elementsB);

    // Print a plain matrix
    std::cout << "A matrix:" << std::endl;
    Components<float>::PrintMatrix(equation);

    // Print a matrix with ElementsB
    std::cout << std::endl << "A matrix with all ElementsB:" << std::endl;
    Components<float>::PrintMatrixWithElementsB(equation);

    // Do the forward elimination
    if (!eliminationMethod(equation))
        return;

    // Do the back substitution
    float* result = new float[equation.size];
    Exercise2::BackSubstitution(equation, result);

    // Print the result
    std::cout << std::endl;
    Components<float>::PrintMatrixResult(equation, result);

    // Clear the memory
    Components<float>::DeleteElements(equation.matrixA, equation.size);
    delete[] equation.matrixA;
    delete[] equation.elementsB;
    delete[] result;
}


template<size_t rows, size_t cols>
void Exercise2::GaussianForwardElimination1(float matrixA[rows][cols], unsigned int size, bool (*eliminationMethod)(Equation&)){
    Equation equation;
    equation.size = size;
    equation.matrixA = new float* [equation.size];
    Components<float>::InitializeElements(equation.matrixA, equation.size, equation.size + 1);

    // Duplication of values for our Equation structure
    for (unsigned int i = 0; i < equation.size; i++)
    {
        Components<float>::DuplicateArray(matrixA[i], equation.size, equation.matrixA[i]);
    }
    std::cout << "A matrix:" << std::endl;
    Components<float>::PrintMatrix(equation);
    float* result = new float[equation.size];
    Exercise2::LinearDecomposition(equation);

    Components<float>::DeleteElements(equation.matrixA, equation.size);
    delete[] equation.matrixA;
    delete[] result;


}
