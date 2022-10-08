/*  VSB - Technical University of Ostrava - Faculty of Electrical Engineering and Computer Science
    This project was made as a part of study materials for a subject Algorithms II
    Author: Ing. Michael Machů
*/

#include <iostream>
#include "Exercise1.h"
#include "Components.h"
#include "Exercise2.h"

void MeasureWrapperExample1(void*);
void MeasureWrapperExample2(void*);
void MeasureWrapperExample3(void*);
void MeasureWrapperExample4(void*);

int main()
{
    const int size = 3;

    float matrixA1[size][size] = { {2, -1, 1}, {4, 1, -1}, {1, 1, 1} };
    float elementsB1[size] = { 1, 5, 0 };

    float matrixA2[size][size] = { {1, -1, 2}, {0, 0, -1}, {0, 2, -1} };
    float elementsB2[size] = { 8, -11, -3 };

    float matrixA3[size][size] = { {3, 2, -4}, {2, 3, 3}, {5, -3, 1} };
    float elementsB3[size] = { 3, 15, 14 };

    Exercise2 exercise2;
    exercise2.GaussianForwardElimination<size, size>(matrixA1, size, elementsB1, Exercise2::ForwardElimination);
    std::cout << "-------------------------------" << std::endl;
    //exercise2.GaussianForwardElimination<size, size>(matrixA2, size, elementsB2, Exercise2::ForwardElimination);
    //std::cout << "-------------------------------" << std::endl;
    //exercise2.GaussianForwardElimination<size, size>(matrixA3, size, elementsB3, Exercise2::ForwardElimination);

    //exercise2.GaussianForwardElimination<size, size>(matrixA1, size, elementsB1, Exercise2::BetterForwardElimination);
    //std::cout << "-------------------------------" << std::endl;
    //exercise2.GaussianForwardElimination<size, size>(matrixA2, size, elementsB2, Exercise2::BetterForwardElimination);
    //std::cout << "-------------------------------" << std::endl;
  //  exercise2.GaussianForwardElimination<size, size>(matrixA3, size, elementsB3, Exercise2::BetterForwardElimination);
    std::cout << "-------------------------------" << std::endl;
    exercise2.GaussianForwardElimination1<size, size>(matrixA1, size, Exercise2::LinearDecomposition);
    std::cout << "-------------------------------" << std::endl;
    exercise2.GaussianForwardElimination1<size, size>(matrixA3, size, Exercise2::LinearDecomposition);

    // ----------- Domaci uloha -----------
    /*
        Vytvorte novou tridu Task 2, ktera bude resit problem "Task 2".
        
        Pro reseni vyuzijte strukturu Equation, kterou budete zasilat jako parametr do funkce.
        Pozor: neprepisujte hodnoty ve strukture Equation, metody budou vracet nove pole!

        Priklad metod:
        float **Task2::DecompositionLU(Equation equation);
        float *Task2::DecompositionSolving(Equation equation, float **matrixLU);

    */

    /* Task 2
    *   Vytvorte dve metody, ktere budou resit soustavu rovnic resenim LU rozkladem matice.
    *   Prvni metoda bude obsahovat vypocet samotneho LU rozkladu, ktery pak nasledne bude vracet jako jednu matici.
    *   Druha metoda pak ze samotneho LU rozkladu vypocita vysledky jednotlivych x-ovych hodnot.
    */
    
    
    return 0;
}

void MeasureWrapperExample1(void* context)
{
    static_cast<Exercise1*>(context)->Example1();
}

void MeasureWrapperExample2(void* context)
{
    static_cast<Exercise1*>(context)->Example2();
}

void MeasureWrapperExample3(void* context)
{
    static_cast<Exercise1*>(context)->Example3();
}

void MeasureWrapperExample4(void* context)
{
    static_cast<Exercise1*>(context)->Example4();
}
