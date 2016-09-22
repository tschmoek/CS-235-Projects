#pragma once
#include "QSInterface.h"
class QuickSort :
	public QSInterface
{
private:
	int* list;
	int capacity;
	int count;
public:
	QuickSort();
	~QuickSort();
	 void sortAll();
	 void sort(int l, int r);
	 void swap(int index1, int index2);
     int medianOfThree(int left, int right);
     int partition(int left, int right, int pivotIndex);
     string getArray();
	 int getSize();
	 void addToArray(int value);
     bool createArray(int capacity);
     void clear();
};

