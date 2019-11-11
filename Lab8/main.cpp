#include <bits/stdc++.h>
#include <stdio.h>
#include <time.h>


// Created by Jacob Duncan @ Salisbury University

void swap(int& val1, int& val2) // function that takes two integers and swaps them
{
  int temp = val1;
  val1 = val2;
  val2 = temp;
}

int partition (int arr[], int start, int end) // function that takes an array and its start and end as parameters
{
  int pivot = arr[start]; // pivot pre-defined by me as the start of the array
  int i = start + 1; // second index

  for (int j = start + 1; j <= end; j++)
  {
    if (arr[j] < pivot) // if, as we traverse the array, the value is less than the pivot
    {
      swap(arr[i], arr[j]); // swap the values
      i++; // increment i
    }
  }
  swap(arr[start], arr[i - 1]);
  return i - 1;
}

void quickSort(int arr[], int start, int end)
{
  int pivot;
  if (start <= end - 1)
  {
    pivot = partition(arr, start, end); // call partition method on the array and set the return equal to pivot
    quickSort(arr, start, pivot - 1); // calls quicksort once for left side
    quickSort(arr, pivot + 1, end); // calls quicksort once for right side
  }
}

void printArray(int arr[], int size) // function to print the contents of the array
{
  int i;
  for (i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int* createArray(int size) // function to create an array of random integers from 1-9
{
  srand(time(NULL));
  int *rtn = new int[size];
  for (int i = 0; i < size; i++)
  {
    rtn[i] = rand()%9+1;
  }
  return rtn;
}

int main()
{
  int a = 10;
  int b = 5;
  std::cout << "=================== " << std::endl;
  std::cout << "Swap Functionality: " << std::endl;
  std::cout << "=================== " << std::endl;
  std::cout << "a: " << a << " - " << "b: " << b << std::endl;
  swap(a,b);
  std::cout << "a: " << a << " - " << "b: " << b << std::endl;

  int arr[] = {10, 5};
  std::cout << "=================== " << std::endl;
  std::cout << " Swapping Index's:  " << std::endl;
  std::cout << "=================== " << std::endl;
  std::cout << "   Pre Swap:      " << std::endl;
  std::cout << "[0]: " << arr[0] << " [1]: " << arr[1] << std::endl;
  swap(arr[0], arr[1]);
  std::cout << "   Post Swap:      " << std::endl;
  std::cout << "[0]: " << arr[0] << " [1]: " << arr[1] << std::endl;
  std::cout << "===================" << std::endl;
  std::cout << " Partition Testing " << std::endl;
  std::cout << "===================" << std::endl;
  int array[] = {4, 9, 8, 2, 3};
  printArray(array, 5);
  int p = partition(array, 0, 5);
  std::cout << "Pivot Location: " << p << std::endl;
  std::cout << "Pivot Value: " << array[p] << std::endl;
  printArray(array, 5);
  std::cout << "====================" << std::endl;
  std::cout << "  Pre-Sorted Array  " << std::endl;
  std::cout << "====================" << std::endl;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // already sorted array
  printArray(arr1, 10);
  quickSort(arr1, 0, 9);
  printArray(arr1, 10);
  std::cout << "=====================" << std::endl;
  std::cout << "Backward Sorted Array" << std::endl;
  std::cout << "=====================" << std::endl;
  int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // backward sorted array
  printArray(arr2, 10);
  quickSort(arr2, 0, 9);
  printArray(arr2, 10);
  std::cout << "=====================" << std::endl;
  std::cout << " 25 Random Int Array " << std::endl;
  std::cout << "=====================" << std::endl;
  int len = 25; // 25 random numbers in array
  int *arr3 = createArray(len);
  printArray(arr3, len);
  quickSort(arr3, 0, len-1);
  printArray(arr3, len);
  std::cout << "=================================================" << std::endl;
  std::cout << "               50 Random Int Array               " << std::endl;
  std::cout << "=================================================" << std::endl;
  int len1 = 50; // 50 random numbers in array
  int *arr4 = createArray(len1);
  printArray(arr4, len1);
  quickSort(arr4, 0, len1-1);
  printArray(arr4, len1);
  return 0;
}
