//Code by Jacob Duncan
//Salisbury University
//COSC 220 Joseph Anderson

//This program takes input from the user and populates
//an array based off their input
//The array is then passed into two different functions
//mean and mean2. These functions find the mean
//of the contents of the array and returns into the main
//the mean function finds the mean using bracket notation
//where as mean2 finds the mean using pointer notation


#include <iostream> // input, output
#include <limits> // cin operater, input validation

using namespace std;

double mean (int array[], int size){ //finds average of array's content using bracket notation
  double sum = 0;
    for (int i = 0; i < size; i++){
      sum += array[i];
    }
  return sum/ (double)size;
}

double mean2 (int *array, int size){ //finds average of array's content using pointer notation
   double sum = 0;
    for (int i = 0; i < size; i++){
       sum += *(array + i);
    }
   return sum/ (double)size;
}

int main (){

  int *array = NULL;
  int size = 0;
  cout << "How many values are you adding?\n";
  cin >> size;

  while(cin.fail()){ //input validation to check if user enters an integer 
    cout << "That is not a valid input, please try again: " << endl;
    cin.clear();
    cin.ignore(256, '\n');
    cin >> size;
  }

  array = new int[size]; //dynamically allocates memory for array depending on the size the user inputs

  cout << "Please insert " << size << " values now: " << endl;

    for (int i = 0; i < size; i++){
      cin >> array[i];
      while(cin.fail()){
        cout << "That is not a valid input, please try again: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> size;
      }
    }

  cout << "The average value of the array using bracket notation is: " << mean(array,size) << endl;
  cout << "The average value of the array using pointer notation is: " << mean2(array,size) << endl;

  delete [] array; //deletes memory pointed to by array 
  array = NULL; //makes sure that the deleted memory is not re-used

  return 0;
}
