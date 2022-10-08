#include "Exercise1.h"
#include <iostream>
#include "Components.h"


Exercise1::Exercise1(unsigned int elementsLength, bool hasArrayRandomValues)
{
	this->elementsLength = elementsLength;
	this->elements = new int[this->elementsLength];
	this->elementsBackup = new int[this->elementsLength];

	if (hasArrayRandomValues)
	{
		Components<int>::CreateArrayRandomValues(this->elements, this->elementsLength);
	}
	else {
		Components<int>::CreateArraySequenceValues(this->elements, this->elementsLength);
	}

	Components<int>::DuplicateArray(this->elements, this->elementsLength, this->elementsBackup);
}

Exercise1::~Exercise1()
{
	delete[] this->elements;
	delete[] this->elementsBackup;
}

void Exercise1::Example1()
{
	if (this->BruteForceElementUniqueness(this->elements, this->elementsLength))
	{
		std::cout << "Uniqueness is true" << std::endl;
	}
	else {
		std::cout << "Uniqueness is false" << std::endl;
	}
}

void Exercise1::Example2()
{
	if (this->PresortElementUniqueness(this->elements, this->elementsLength, &Components<int>::Compare))
	{
		std::cout << "Uniqueness is true" << std::endl;
	}
	else {
		std::cout << "Uniqueness is false" << std::endl;
	}
}

void Exercise1::Example3()
{
	int mode = this->BruteForceMode(elements, elementsLength);
	std::cout << "The mode is " << mode << std::endl;
}

void Exercise1::Example4()
{
	int mode = this->PresortMode(elements, elementsLength, &Components<int>::Compare);
	std::cout << "The mode is " << mode << std::endl;
}

int* Exercise1::GetElements()
{
	return this->elements;
}

int Exercise1::GetElementsLength()
{
	return this->elementsLength;
}

void Exercise1::ResetElements()
{
	for (int i = 0; i < this->elementsLength; i++)
	{
		this->elements[i] = this->elementsBackup[i];
	}
}

// (1/2)n^2 => O(n^2)
bool Exercise1::BruteForceElementUniqueness(int *elements, unsigned int elementsLength)
{
	for (int i = 0; i <= elementsLength - 2; i++)
	{
		for (int j = i + 1; j <= elementsLength - 1; j++)
		{
			if (elements[i] == elements[j])
				return false;
		}
	}

	return true;
}

// O(nlogn) + O(n) = O(nlogn)
bool Exercise1::PresortElementUniqueness(int *elements, unsigned int elementsLength, int (*compare)(const void*, const void*))
{
	// O(nlogn)
	std::qsort(elements, elementsLength, sizeof(int), compare);

	// O(n)
	for (int i = 0; i <= elementsLength - 2; i++)
	{
		if (elements[i] == elements[i + 1])
			return false;
	}

	return true;
}

// O(n^2)
int Exercise1::BruteForceMode(int *elements, unsigned int elementsLength)
{
	int modeFrequency = 0, modeValue = 0;

	// O(n^2)
	for (int i = 0; i <= elementsLength - 2; i++)
	{
		int runLength = 1;

		for (int j = i + 1; j <= elementsLength - 1; j++)
		{
			if (elements[i] == elements[j])
				runLength++;
		}

		if (runLength > modeFrequency)
		{
			modeFrequency = runLength;
			modeValue = elements[i];
		}
	}

	return modeValue;
}

// O(nlogn) + O(n) = O(nlogn)
int Exercise1::PresortMode(int *elements, unsigned int elementsLength, int (*compare)(const void*, const void*))
{
	int i = 0, modeFrequency = 0, modeValue = 0;

	// O(nlogn)
	std::qsort(elements, elementsLength, sizeof(int), compare);

	// O(n)
	while (i <= elementsLength - 1)
	{
		int runLength = 1;
		int runValue = elements[i];

		while (i + runLength <= elementsLength - 1 && elements[i + runLength] == runValue)
		{
			runLength = runLength + 1;
		}

		if (runLength > modeFrequency)
		{
			modeFrequency = runLength;
			modeValue = runValue;
		}
		i = i + runLength;
	}

	return modeValue;
}