#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <bits/stdc++.h>
#include "sort.h"

//By Jacob Duncan @ Salisbury University
//Course: COSC-220
//Professor: Joseph Anderson

/*
  This program sorts various arrays (random, sorted, backwards sorted) with
  different sorting algorithms (bubble, selection, insertion), and tests
  their efficiency and timing with arrays of various sizes
*/

int *makeRandArray(int len){ // makes an array of random numbers 1-9
  srand(time(NULL));
  int *rtn = new int[len];
  for (int i = 0; i < len; i++){
    rtn[i] = rand()%9+1;
  }
  return rtn;
}

int *makeBackArray(int len){ // makes a pre-sorted array, highest to lowest, numbers 1-9
  srand(time(NULL));
  int* rtn = new int[len];
  int temp;
  int n = sizeof(rtn)/sizeof(rtn[0]);
  for (int j = 0; j < len; j++){
    rtn[j] = rand()%9+1;
  }
  int flag = 1;
  int temp1;
  for (int i = 1; (i <= len) && flag; i++){
    flag = 0;
    for (int j = 0; j < (len-1); j++){
      if (rtn[j+1] > rtn[j]){
        temp1 = rtn[j];
        rtn[j] = rtn[j+1];
        rtn[j+1] = temp1;
        flag = 1;
      }
    }
  }
  return rtn;
}

int *makeSortArray(int len){ // make a pre-sorted array, lowest to highest, numbers 1-9
  srand(time(NULL));
  int *rtn = new int[len];
  for (int j = 0; j < len; j++){
    rtn[j] = rand()%9+1;
  }
  for (int i = 0; i < len; i++){
    rtn[i] = i;
  }
  return rtn;
}

void printArray(int *arr, int len){ // function to print array, used for testing
  for (int i = 0; i < len; i++){
    std::cout << arr[i] << std::endl;
  }
}

bool isSorted (int *arr, int len){ // function to check if array is sorted
  if (len == 0 || len == 1){
    std::cout << "***Array is sorted***" << std::endl;
    return true;
  }
  for (int i = 1; i < len; i++){
    if (arr[i-1] > arr [i]){
      std::cout << "***Array not sorted***" << std::endl;
      return false;
    }
  }
  std::cout << "***Array is sorted***" << std::endl;
  return true;
}

int main (){
  Sort s;
  for (int i = 0; i < 3; i++){ // First run with 100 elements
    if (i == 0){
      std::cout << "================================================" << std::endl;
      std::cout << "                Array of Random #'s  (100)      " << std::endl;
      std::cout << "================================================" << std::endl;
      for (int i = 0; i < 3; i++){
        if (i == 0){
          int len = 100;
          int *arr = makeRandArray(len); // makes new array with desired length
          auto start = std::chrono::system_clock::now(); // starts time
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.bubbleSort(arr, len); // calls bubble sort function on array
          std::cout << std::endl;
          isSorted(arr, len); // checks to see if it was sorted
          auto end = std::chrono::system_clock::now(); // ends time
          std::chrono::duration<double>elapsed_seconds = end-start; // gets elapsed time
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 1){
          int len = 100;
          int *arr = makeRandArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.selectionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 2){
          int len = 100;
          int *arr = makeRandArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.insertionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
        }
      }
    }
    if (i == 1){
      std::cout << "================================================" << std::endl;
      std::cout << "                Array of Sorted #'s  (100)      " << std::endl;
      std::cout << "================================================" << std::endl;
      for (int i = 0; i < 3; i++){
        if (i == 0){
          int len = 100;
          int *arr = makeSortArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.bubbleSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 1){
          int len = 100;
          int *arr = makeSortArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.selectionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 2){
          int len = 100;
          int *arr = makeSortArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.insertionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
        }
      }
    }
    if (i == 2){
      std::cout << "================================================" << std::endl;
      std::cout << "        Array of #'s in Descending Order (100)  " << std::endl;
      std::cout << "================================================" << std::endl;
      for (int i = 0; i < 3; i++){
        if (i == 0){
          int len = 100;
          int *arr = makeBackArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.bubbleSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 1){
          int len = 100;
          int *arr = makeBackArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.selectionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 2){
          int len = 100;
          int *arr = makeBackArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.insertionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
        }
      }
    }
  }
  for (int i = 0; i < 3; i++){ // Second run with 1,000 elements
    if (i == 0){
      std::cout << "================================================" << std::endl;
      std::cout << "                Array of Random #'s  (1000)     " << std::endl;
      std::cout << "================================================" << std::endl;
      for (int i = 0; i < 3; i++){
        if (i == 0){
          int len = 1000;
          int *arr = makeRandArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.bubbleSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 1){
          int len = 1000;
          int *arr = makeRandArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.selectionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 2){
          int len = 1000;
          int *arr = makeRandArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.insertionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
        }
      }
    }
    if (i == 1){
      std::cout << "================================================" << std::endl;
      std::cout << "                Array of Sorted #'s  (1000)     " << std::endl;
      std::cout << "================================================" << std::endl;
      for (int i = 0; i < 3; i++){
        if (i == 0){
          int len = 1000;
          int *arr = makeSortArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.bubbleSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 1){
          int len = 1000;
          int *arr = makeSortArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.selectionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 2){
          int len = 1000;
          int *arr = makeSortArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.insertionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
        }
      }
    }
    if (i == 2){
      std::cout << "================================================" << std::endl;
      std::cout << "        Array of #'s in Descending Order (1000) " << std::endl;
      std::cout << "================================================" << std::endl;
      for (int i = 0; i < 3; i++){
        if (i == 0){
          int len = 1000;
          int *arr = makeBackArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.bubbleSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 1){
          int len = 1000;
          int *arr = makeBackArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.selectionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 2){
          int len = 1000;
          int *arr = makeBackArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.insertionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
        }
      }
    }
  }
  for (int i = 0; i < 3; i++){ // Third and final run with 10,000 elements
    if (i == 0){
      std::cout << "================================================" << std::endl;
      std::cout << "                Array of Random #'s  (10000)   " << std::endl;
      std::cout << "================================================" << std::endl;
      for (int i = 0; i < 3; i++){
        if (i == 0){
          int len = 10000;
          int *arr = makeRandArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.bubbleSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 1){
          int len = 10000;
          int *arr = makeRandArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.selectionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 2){
          int len = 10000;
          int *arr = makeRandArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.insertionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
        }
      }
    }
    if (i == 1){
      std::cout << "================================================" << std::endl;
      std::cout << "                Array of Sorted #'s  (10000)   " << std::endl;
      std::cout << "================================================" << std::endl;
      for (int i = 0; i < 3; i++){
        if (i == 0){
          int len = 10000;
          int *arr = makeSortArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.bubbleSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 1){
          int len = 10000;
          int *arr = makeSortArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.selectionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 2){
          int len = 10000;
          int *arr = makeSortArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.insertionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
        }
      }
    }
    if (i == 2){
      std::cout << "================================================" << std::endl;
      std::cout << "      Array of #'s in Descending Order (10000) " << std::endl;
      std::cout << "================================================" << std::endl;
      for (int i = 0; i < 3; i++){
        if (i == 0){
          int len = 10000;
          int *arr = makeBackArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.bubbleSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 1){
          int len = 10000;
          int *arr = makeBackArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.selectionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
        if (i == 2){
          int len = 10000;
          int *arr = makeBackArray(len);
          auto start = std::chrono::system_clock::now();
          std::time_t start_time = std::chrono::system_clock::to_time_t(start);
          std::cout << "Started at " << std::ctime(&start_time) << std::endl;
          s.insertionSort(arr, len);
          std::cout << std::endl;
          isSorted(arr, len);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double>elapsed_seconds = end-start;
          std::time_t end_time = std::chrono::system_clock::to_time_t(end);
          std::cout << std::endl;
          std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: "<< elapsed_seconds.count() << std::endl;
          std::cout << "================================================" << std::endl;
        }
      }
    }
  }

  return 0;
}
