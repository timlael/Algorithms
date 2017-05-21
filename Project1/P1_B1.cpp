#include <ctime>
#include <iostream>
using namespace std;

/* Shell Sort Version 1
	Gap 1/2 of array size */
void shell_sort1(int array[], int size) {
    int gap = size/2;
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

/* Linear Search */
int linear_search(int array[], int n, int value){
  int i = 0;
  while (i < n && array[i] != value) {
      i++;
	}
  if (i == n){
    return -1;
  }
  else {
    return i;
  }
}

/* Binary Search */
int binary_search(int array[], int n, int value) {
  int left=0;
      while (left <= n) {
            int middle = (left + n) / 2;
            if (array[middle] == value)
                  return middle;
            else if (array[middle] > value)
                  n = middle - 1;
            else
                  left = middle + 1;
      }
      return -1;
}


/* 	Array fill function */
int fill(int *array, int n){
  srand(time(NULL));
  for(int i=0; i<n; i++){
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

//Main Function
int main(){
  int array[100];
  int value;                           //array to search
  int n = sizeof(array)/sizeof(array[0]);   //number of elements in array
  clock_t t1,t2;                            //clock time to measure execution time

  /* Fill and sort array */
  fill(array, n);
  shell_sort1 (array, n);
  printf("\nSorted array:\n");
  print(array, n);
  value = (rand()%1000000);                                //holds search value

  printf("\nSearching for %i using linear search...\n", value);
  /* perform linear search, measure execution time
  and report results */
  t1=clock();
  if (linear_search(array, n, value) == -1){
    cout << value << " was NOT found in the array." << endl;
  }
  else
  cout << value << " was found in the array!" << endl;
  t2=clock();

  float diff = (t2-t1);
  float seconds = diff / CLOCKS_PER_SEC;
  printf("\nElapsed linear search time: %.10f seconds.\n", seconds);
  /* perform binary search, measure execution time
  and report results */
  printf("\nSearching for %i using binary search...\n", value);
  t1=clock();
  if (binary_search(array, n, value) == -1){
    cout << value << " was NOT found in the array." << endl;
  }
  else
  cout << value << " was found in the array!" << endl;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  printf("\nElapsed binary search time: %.10f seconds.\n", seconds);


  return 0;
}
