#include <ctime>
#include <iostream>
using namespace std;

/* Bubble Sort */
void bubble_sort (int array[], int size){
  for (int i = 0; i < size; i++){
    bool didSwap=false;
      for (int j = 0; j < size; j++){
        if (array[j] > array[j + 1]){
          didSwap=true;
          int temp = array[j];
          array[j] = array[j + 1];
          array[j + 1] = temp;
        }
      }
    if(!didSwap) break;
  }
}

/* Shaker Sort */
void shaker_sort(int array[], int size) {
    for (int i = 0; i < size/2; i++) {
        bool didSwap = false;
        for (int j = i; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
                didSwap = true;
            }
        }
        for (int j = size - 2 - i; j > i; j--) {
            if (array[j] < array[j-1]) {
                int tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
                didSwap = true;
            }
        }
        if(!didSwap) break;
    }
}

/* Shell Sort Version 1
	Gap 1/2 of array size */
void shell_sort1(int array[], int size) {
    int gap = size / 2;
    while (gap > 0) {
        for (int i = 0; i < size - gap; i++) {
            int j = i + gap;
            int tmp = array[j];
            while (j >= gap && tmp < array[j - gap]) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = tmp;
        }
        if (gap == 2) {
            gap = 1;
        } else {
            gap /= 2;
        }
    }
}

/* Shell Sort Version 2
	Gap 1/10 array size */
void shell_sort2(int array[], int size) {
    int gap = size / 10;
    while (gap > 0) {
        for (int i = 0; i < size - gap; i++) {
            int j = i + gap;
            int tmp = array[j];
            while (j >= gap && tmp < array[j - gap]) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = tmp;
        }
        if (gap == 2) {
            gap = 1;
        } else {
            gap /= 10;
        }
    }
}

/* 	Array fill function */
int fill(int *array, int size){
  srand(time(NULL));
  for(int i=0; i<size; i++){
        array[i] = (rand()%1000000); // limit random numbers to 0 MIN - 1,000,000 MAX
  }
  return *array;
}

/* 	Array print function */
int print (int *array, int n){
  for(int row=0; row<n/10; row++){
    for(int col=0; col<10; col++){
        printf("%i \t", array[(row*10)+col]);
      }
      printf("\n");
  }
  return *array;
}

/* Main */            
int main(){
  int array[100];                           //100 element array
  int n = sizeof(array)/sizeof(array[0]);   //number of elements in array
  clock_t t1,t2;                            //clock variables to measure execution time

/* Bubble Sort
  FIll, print, sort and measure execution time, print sorted
  and display sorting time */
  printf("\nBubble sort:\n");

  fill(array, n);
  printf("Original array:\n");
  print(array, n);

  t1=clock();
  bubble_sort (array, n);
  t2=clock();
  float diff = (t2-t1);
  float seconds = diff / CLOCKS_PER_SEC;

  printf("\nBubble Sorted array:\n");
  print(array, n);
  printf("\nBubble sort time: %.10f seconds.\n", seconds);


/* Shaker Sort
FIll, print, sort and measure execution time, print sorted
and display sorting time */
  printf("\nShaker sort:\n");

  fill(array, n);
  printf("Original array:\n");
  print(array, n);

  t1=clock();
  bubble_sort (array, n);
  t2=clock();
  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;

  printf("\nShaker Sorted array:\n");
  print(array, n);
  printf("\nShaker sort time: %.10f seconds.\n", seconds);


/* Shell Sort 1
FIll, print, sort and measure execution time, print sorted
and display sorting time */
  printf("\nShell sort 1:\n");

  fill(array, n);
  printf("Original array:\n");
  print(array, n);

  t1=clock();
  shell_sort1 (array, n);
  t2=clock();
  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;

  printf("\nShell Sorted array with gap = 1/2 array size:\n");
  print(array, n);
  printf("\nShell sort time: %.10f seconds.\n", seconds);


/* Shell Sort 2
FIll, print, sort and measure execution time, print sorted
and display sorting time */
  printf("\nShell sort 2:\n");

  fill(array, n);
  printf("Original array:\n");
  print(array, n);

  t1=clock();
  shell_sort1 (array, n);
  t2=clock();
  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;

  printf("\nShell Sorted array with gap = 1/10 array size:\n");
  print(array, n);
  printf("\nShell sort time: %.10f seconds.\n", seconds);

  return 0;
}
