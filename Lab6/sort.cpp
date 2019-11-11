#include <bits/stdc++.h>
#include "sort.h"

void Sort::swap(int *xp, int *yp){
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void Sort::bubbleSort(int array[], int length){
  bool swapped = true;
  int counter;
  while (swapped){
    for(int i = 0; i < length-1; i++){
      swapped = false;
      for (int j = 0; j < length - i - 1; j++){
        if (array[j] > array[j+1]){
          swap(&array[j], &array[j+1]);
          counter += 1;
          swapped = true;
        }
      }
      if (swapped == false){
        break;
      }
    }
  }
  std::cout << "Number of swaps using bubble sort: " << counter << std::endl;
}

void Sort::selectionSort(int array[], int length){
  int min, counter;
  for (int i = 0; i <= length -2; i++){
    min = i;
    for (int j = i+1; j < length; j++){
      if (array[j] < array[min]){
        min = j;
      }
    }
    swap(&array[min], &array[i]);
    counter += 1;
  }
  std::cout << "Number of swaps using selection sort: " << counter << std::endl;
}

void Sort::insertionSort(int array[], int length){
  int j, counter;
  for (int i = 1; i <= (length - 1); i++){
    j = i;
    while (j > 0 && array[j] < array[j-1]){
      swap(&array[j], &array[j-1]);
      counter += 1;
      j = j -1;
    }
  }
  std::cout << "Number of swaps using insertion sort: " << counter << std::endl;
}

void Sort::printArray(int array[], int length){
  for (int i = 0; i < length; i++){
    printf("%d", array[i]);
    printf("n");
  }
}
