#include "QuickSort.h"


QuickSort::QuickSort()
{
	count = 0;
	list = NULL;
	capacity = 0;
}


QuickSort::~QuickSort()
{
	clear();
}
/*
* sortAll()
*
* Sorts elements of the array.  After this function is called, every
* element in the array is less than or equal its successor.
*
* Does nothing if the array is empty.
*/
void QuickSort::sortAll()
{
	sort(0, count - 1);
}
void QuickSort::sort(int left, int right)
{
	if (right - left == 1)
	{
		if (list[right] > list[left])
		{
			return;
		}
		else
		{
			swap(right, left);
			return;
		}
	}

	if (right == left || left < 0 || right > count - 1 || right < left || left > right)
	{
		return;
	}

	int pivot = medianOfThree(left, right);
	int fin = partition(left, right, pivot);
	sort(left, fin - 1);
	sort(fin + 1, right);
}
/*
* medianOfThree()
*
* The median of three pivot selection has two parts:
*
* 1) Calculates the middle index by averaging the given left and right indices:
*
* middle = (left + right)/2
*
* 2) Then bubble-sorts the values at the left, middle, and right indices.
*
* After this method is called, data[left] <= data[middle] <= data[right].
* The middle index will be returned.
*
* Returns -1 if the array is empty, if either of the given integers
* is out of bounds, or if the left index is not less than the right
* index.

*		 * @param left
* 		the left boundary for the subarray from which to find a pivot
* @param right
* 		the right boundary for the subarray from which to find a pivot
* @return
*		the index of the pivot (middle index); -1 if provided with invalid input
*/
void QuickSort::swap(int index1, int index2)
{
	int temp = list[index1];
	list[index1] = list[index2];
	list[index2] = temp;
}
int QuickSort::medianOfThree(int left, int right)
{
	if (list == NULL || left < 0 || left >= capacity || right >= capacity || left >= right)
	{
		return -1;
	}
	int mid = (left + right) / 2;
	if (list[left] > list[mid])
	{
		swap(left, mid);
	}
	else if (list[left] > list[right])
	{
		swap(left, right);
	}
	else if (list[mid] > list[right])
	{
		swap(mid, right);
	}
	return mid;
}

/*
* Partitions a subarray around a pivot value selected according to
* median-of-three pivot selection.
*
* The values which are smaller than the pivot should be placed to the left
* of the pivot; the values which are larger than the pivot should be placed
* to the right of the pivot.
*
* Returns -1 if the array is null, if either of the given integers is out of
* bounds, or if the first integer is not less than the second integer, or if the
* pivot is not between the two boundaries.
*
* @param left
* 		the left boundary for the subarray to partition
* @param right
* 		the right boundary for the subarray to partition
* @param pivotIndex
* 		the index of the pivot in the subarray
* @return
*		the pivot's ending index after the partition completes; -1 if
* 		provided with bad input
*/
int QuickSort::partition(int left, int right, int pivotIndex)
{
	if (list == NULL || left < 0 || left >= count || right >= count || left >= right || count < 2 || right < 0 || pivotIndex >= right || pivotIndex <= left)
	{
		return -1;
	}
	int i = left + 1;
	int j = right;
	swap(left, pivotIndex);

	while (i <= j && j > 0 && i < count - 1)
	{
		while (list[i] <= list[left] && i < count - 1)
		{
			i++;
		}
		while (list[j] > list[left] && j > 0)
		{
			j--;
		}
		if (i < j)
		{
			swap(i, j);
			i++;
			j--;
		}
	}
	swap(left, j);

	return j;
}

/*
* Produces a comma delimited string representation of the array. For example: if my array
* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
* with no trailing comma.  The number of cells included equals the number of values added.
* Do not include the entire array if the array has yet to be filled.
*
* Returns an empty string, if the array is NULL or empty.
*
* @return
*		the string representation of the current array
*/
string QuickSort::getArray()
{
	string str = "";
	if (count < 1 || list == NULL)
	{
		return "";
	}
	for (int i = 0; i < count; i++)
	{
		if (i < count - 1)
		{
			str += to_string(list[i]) + ",";
		}
		else
			str += to_string(list[i]);
	}
	return str;
}

/*
* Returns the number of elements which have been added to the array.
*/
int QuickSort::getSize()
{
	if (list == NULL)
	{
		return 0;
	}
	return count;
}

/*
* Adds the given value to the end of the array starting at index 0.
* For example, the first time addToArray is called,
* the give value should be found at index 0.
* 2nd time, value should be found at index 1.
* 3rd, index 2, etc up to its max capacity.
*
* If the array is filled, do nothing.
*/
void QuickSort::addToArray(int value)
{
	if (count < capacity)
	{
		list[count] = value;
		count++;
	}

}

/*
* Dynamically allocates an array with the given capacity.
* If a previous array had been allocated, delete the previous array.
* Returns false if the given capacity is non-positive, true otherwise.
*
* @param
*		size of array
* @return
*		true if the array was created, false otherwise
*/
bool QuickSort::createArray(int capacity)
{
	if (list != NULL)
	{
		clear();
	}
	else
	{
		this->capacity = 0;
		if (capacity >= 1)
		{
			list = new int[capacity];  // Allocate n ints and save ptr in a.
			this->capacity = capacity;
		}
		else
			return false;
	}

}

/*
* Resets the array to an empty or NULL state.
*/
void QuickSort::clear()
{

	delete[] list;
	list = NULL;
	capacity = 0;
	count = 0;

}

