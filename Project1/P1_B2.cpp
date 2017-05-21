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


int main(){
/* 10 of each of the array sizes */
  int array[500],array2[500],array3[500],array4[500],array5[500],
  array6[500],array7[500],array8[500],array9[500],array0[500];                           		//500 element array
  int sarray[1000],sarray2[1000],sarray3[1000],sarray4[1000],sarray5[1000],
  sarray6[1000],sarray7[1000],sarray8[1000],sarray9[1000],sarray0[1000];                        //1000 element array
  int marray[2500],marray2[2500],marray3[2500],marray4[2500],marray5[2500],
  marray6[2500],marray7[2500],marray8[2500],marray9[2500],marray0[2500];                        //2500 element array
  int larray[5000],larray2[5000],larray3[5000],larray4[5000],larray5[5000],
  larray6[5000],larray7[5000],larray8[5000],larray9[5000],larray0[5000];                        //5000 element array



  int n = sizeof(array)/sizeof(array[0]);   	//number of elements in 500 element array
  int o = sizeof(sarray)/sizeof(sarray[0]);   	//number of elements in 1000 element array
  int p = sizeof(marray)/sizeof(marray[0]);   	//number of elements in 2500 element array
  int q = sizeof(larray)/sizeof(larray[0]);   	//number of elements in 5000 element array

  int value;                                	//holds search value
  float diff, seconds, c, avg;
  clock_t t1,t2;                            	//clock time to measure execution time


/* Fill the arrays */
  fill(array, n);  fill(array2, n);  fill(array3, n);  fill(array4, n);  fill(array5, n);
  fill(array6, n);  fill(array7, n);  fill(array8, n);  fill(array9, n);  fill(array0, n);
  fill(sarray, o);  fill(sarray2, o);  fill(sarray3, o);  fill(sarray4, o);  fill(sarray5, o);
  fill(sarray6, o);  fill(sarray7, o);  fill(sarray8, o);  fill(sarray9, o);  fill(sarray0, o);
  fill(marray, p);  fill(marray2, p);  fill(marray3, p);  fill(marray4, p);  fill(marray5, p);
  fill(marray6, p);  fill(marray7, p);  fill(marray8, p);  fill(marray9, p);  fill(marray0, p);
  fill(larray, q);  fill(larray2, q);  fill(larray3, q);  fill(larray4, q);  fill(larray5, q);
  fill(larray6, q);  fill(larray7, q);  fill(larray8, q);  fill(larray9, q);  fill(larray0, q);
/* Sort the arrays */
  shell_sort1 (array, n);shell_sort1 (array2, n);shell_sort1 (array3, n);shell_sort1 (array4, n);shell_sort1 (array5, n);
  shell_sort1 (array6, n);shell_sort1 (array7, n);shell_sort1 (array8, n);shell_sort1 (array9, n);shell_sort1 (array0, n);
  shell_sort1 (sarray, o);shell_sort1 (sarray2, o);shell_sort1 (sarray3, o);shell_sort1 (sarray4, o);shell_sort1 (sarray5, o);
  shell_sort1 (sarray6, o);shell_sort1 (sarray7, o);shell_sort1 (sarray8, o);shell_sort1 (sarray9, o);shell_sort1 (sarray0, o);
  shell_sort1 (marray, p);shell_sort1 (marray2, p);shell_sort1 (marray3, p);shell_sort1 (marray4, p);shell_sort1 (marray5, p);
  shell_sort1 (marray6, p);shell_sort1 (marray7, p);shell_sort1 (marray8, p);shell_sort1 (marray9, p);shell_sort1 (marray0, p);
  shell_sort1 (larray, q);shell_sort1 (larray2, q);shell_sort1 (larray3, q);shell_sort1 (larray4, q);shell_sort1 (larray5, q);
  shell_sort1 (larray6, q);shell_sort1 (larray7, q);shell_sort1 (larray8, q);shell_sort1 (larray9, q);shell_sort1 (larray0, q);

/* Linear search on the arrays for random values
	measure execution time, display search results and time statistics */
  srand(time(NULL));

/* Linear search on 500 element arrays */
  value = (rand()%1000000);
  t1=clock();
	linear_search(array, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(array2, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(array3, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(array4, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(array5, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(array6, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(array7, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(array8, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(array9, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(array0, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  avg = c/10;

  printf("\nAverage search time using linear search on a 500 element array: %.10f\n", avg);
  printf("\n---------------------------------------------------------------------\n");
  printf("\n---------------------------------------------------------------------\n");
/* Linear search on 1000 element arrays */
  c=0;
  value = (rand()%1000000);
  t1=clock();
	linear_search(sarray, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(sarray2, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(sarray3, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(sarray4, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(sarray5, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(sarray6, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(sarray7, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(sarray8, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(sarray9, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(sarray0, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  avg = c/10;

  printf("\nAverage search time using linear search on a 1000 element array: %.10f\n", avg);
  printf("\n---------------------------------------------------------------------\n");
  printf("\n---------------------------------------------------------------------\n");
/* Linear search on 2500 element arrays */
  c=0;
  value = (rand()%1000000);
  t1=clock();
	linear_search(marray, p, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(marray2, p, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(marray3, p, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(marray4, p, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(marray5, p, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(marray6, p, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(marray7, p, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(marray8, p, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(marray9, p, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(marray0, p, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  avg = c/10;

  printf("\nAverage search time using linear search on a 2500 element array: %.10f\n", avg);
  printf("\n---------------------------------------------------------------------\n");
  printf("\n---------------------------------------------------------------------\n");
/* Linear search on 5000 element arrays */
  c=0;
  value = (rand()%1000000);
  t1=clock();
	linear_search(larray, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(larray2, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(larray3, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(larray4, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(larray5, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(larray6, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(larray7, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(larray8, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(larray9, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	linear_search(larray0, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  avg = c/10;

  printf("\nAverage search time using linear search on a 5000 element array: %.10f\n", avg);
  printf("\n---------------------------------------------------------------------\n");
  printf("\n*********************************************************************\n");
  printf("\n---------------------------------------------------------------------\n");


/* Binary search on the arrays for random values
	measure execution time, display search results and time statistics */
/* Binary search on 500 element arrays */
  c=0;
  value = (rand()%1000000);
  t1=clock();
	binary_search(array, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(array2, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(array3, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(array4, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(array5, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(array6, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(array7, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(array8, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(array9, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(array0, n, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  avg = c/10;

  printf("\nAverage search time using binary search on a 500 element array: %.10f\n", avg);
  printf("\n---------------------------------------------------------------------\n");
  printf("\n---------------------------------------------------------------------\n");
/* Binary search on 1000 element arrays */
  c=0;
  value = (rand()%1000000);
  t1=clock();
	binary_search(sarray, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(sarray2, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(sarray3, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(sarray4, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(sarray5, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(sarray6, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(sarray7, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(sarray8, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(sarray9, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(sarray0, o, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  avg = c/10;

  printf("\nAverage search time using binary search on a 1000 element array: %.10f\n", avg);
  printf("\n---------------------------------------------------------------------\n");
  printf("\n---------------------------------------------------------------------\n");
/* Binary search on 2500 element arrays */
  c=0;
  value = (rand()%1000000);
  t1=clock();
	binary_search(marray, p, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(marray2, p, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(marray3, p, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(marray4, p, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(marray5, p, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(marray6, p, value);;
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(marray7, p, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(marray8, p, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(marray9, p, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(marray0, p, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  avg = c/10;

  printf("\nAverage search time using binary search on a 2500 element array: %.10f\n", avg);
  printf("\n---------------------------------------------------------------------\n");
  printf("\n---------------------------------------------------------------------\n");
/* Binary search on 5000 element arrays */
  c=0;
  value = (rand()%1000000);
  t1=clock();
	binary_search(larray, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(larray2, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(larray3, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(larray4, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(larray5, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(larray6, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(larray7, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(larray8, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(larray9, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  value = (rand()%1000000);
  t1=clock();
	binary_search(larray0, q, value);
  t2=clock();

  diff = (t2-t1);
  seconds = diff / CLOCKS_PER_SEC;
  c += seconds;

  avg = c/10;

  printf("\nAverage search time using binary search on a 5000 element array: %.10f\n", avg);
  printf("\n---------------------------------------------------------------------\n");
  printf("\n---------------------------------------------------------------------\n");

return 0;
}
