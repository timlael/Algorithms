/*
  Tim M. Lael
  CS 3010 e01
  Project 2
  Part B - Quicksort
*/
#include <iostream>
#include <ctime>
#include <cmath>


/* Array fill function */
int fill(int *array, int size){
  for(int i=0; i<size; i++){
        array[i] = (rand()%1000000);
  }
  return *array;
}

/* Array zero function */
int clear(int *array, int size){
  for(int i=0; i<size; i++){
        array[i] = 0;
  }
  return *array;
}

/* Array print function */
int print (int *array, int n){
  for(int row=0; row<n/10; row++){
    for(int col=0; col<10; col++){
        printf("%i \t", array[(row*10)+col]);
      }
      printf("\n");
  }
  return *array;
}

/* Element swap function */
void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
  return;
}

/* Determine and position right pivot */
int rpivot(int a[], int left, int right){
  int element = a[right];
  int i = left - 1;

  for(int j = left; j<right; ++j){
    if(a[j] <=  element){
      ++i;
      swap(&a[i],&a[j]);
    }
  }
  int temp = a[i+1];
  a[i+1] = a[right];
  a[right] = temp;
  return a[i+1];
}

/* Determine and position median of three pivot */
int median3(int a[], int left, int right){
  int center = (left + right)/2;

  if (a[center] < a[left])
    swap(&a[left],&a[center]);

  if (a[right] < a[left])
    swap(&a[left],&a[right]);

  if (a[right]< a[center])
    swap(&a[center],&a[right]);
    swap(&a[center], &a[right - 1]);

  return a[right - 1];
}

/* Determine and position pivot from 5 random elements */
int ran5(int a[], int left, int right){
  int index;
  int r1 = left + rand() % (right - left +1);
  int r2 = left + rand() % (right - left +1);
  int r3 = left + rand() % (right - left +1);
  int r4 = left + rand() % (right - left +1);
  int r5 = left + rand() % (right - left +1);

  if (r1 > r2)
  	swap(&r1, &r2);

  if (r3 > r4)
	  swap(&r3, &r4);

  if (r3 < r1){
  	swap(&r2, &r4);
	   r3 = r1;
  }
  r1 = r5;

  if (r1 > r2)
  	swap(&r1, &r2);

  if (r1 < r3){
  	swap(&r2, &r4);
	   r1 = r3;
  }
  if (r4 > r1)
  	index = r1;

  else
  	index = r4;
    int pivot = a[index];
    swap(&a[index], &a[right]);
    index = right;
    int i = left -1;

  for(int j = left; j <= right - 1; j++){
  	if (a[j] <= pivot){
		    i++;
		    swap(&a[i], &a[j]);
	  }
  }
  swap(&a[i+1], &a[index]);
  return a[i+1];
}

/* Quicksort using right pivot */
void qrp(int a[], int left, int right){
  if (left < right) {
    int pivot = rpivot(a,left,right);

    if (left == right - 1) return;
    int i = left;
    int j = right - 1;

    for ( ; ;) {
      while(a[++i]<pivot) {}
      while(pivot<a[--j]) {}

      if ( i < j)
        swap(&a[i],&a[j]);

      else
        break;
    }
  swap(&a[i],& a[right -1]);
  qrp(a,left,i-1);
  qrp(a,i+1,right);
  }
  return;
}

/* Quicksort using median of three pivot */
void qm3(int a[], int left, int right){
  if (left < right) {
    int pivot = median3(a,left,right);

    if (left == right - 1) return;

    int i = left;
    int j = right - 1;

    for ( ; ;) {
      while(a[++i]<pivot) {}
      while(pivot<a[--j]) {}

      if ( i < j)
        swap(&a[i],&a[j]);

      else
        break;
    }
  swap(&a[i],& a[right -1]);
  qm3(a,left,i-1);
  qm3(a,i+1,right);
  }
  return;
}

/* Quicksort using medion of 5 random elements pivot */
void q5r(int a[], int left, int right){
  if (left < right) {
    int pivot = ran5(a,left,right);

    if (left == right - 1) return;

    int i = left;
    int j = right - 1;

    for ( ; ;) {
      while(a[++i]<pivot) {}
      while(pivot<a[--j]) {}

      if ( i < j)
        swap(&a[i],&a[j]);
      else
        break;
      }
  swap(&a[i],& a[right -1]);
  q5r(a,left,i-1);
  q5r(a,i+1,right);
  }
  return;
}

/* Verbose quicksort right pivot function
    used in main loop calls */
float qrpl (int x){
  clock_t t1,t2;
  int a[x];
  int n = sizeof(a)/sizeof(a[0]);

  clear(a, n);
  fill(a, n);
  printf("Original array:\n");
  print(a, n);
  t1=clock();
  qrp(a,0,n-1);
  t2=clock();
  float diff = (t2-t1);
  float seconds = diff / CLOCKS_PER_SEC;

  printf("\nQuick Sorted array:\n");
  print(a, n);
  printf("\nQuicksort Right Pivot Sort Time On %i Elements: %.10f seconds.\n", x, seconds);
  return seconds;
}

/* Verbose quicksort median of three pivot function
    used in main loop calls */
float qm3l (int x){
  clock_t t1,t2;
  int a[x];
  int n = sizeof(a)/sizeof(a[0]);

  clear(a, n);
  fill(a, n);
  printf("Original array:\n");
  print(a, n);
  t1=clock();
  qm3(a,0,n-1);
  t2=clock();
  float diff = (t2-t1);
  float seconds = diff / CLOCKS_PER_SEC;

  printf("\nQuick Sorted array:\n");
  print(a, n);
  printf("\nQuicksort Median of Three Sort Time On %i Elements: %.10f seconds.\n", x, seconds);
  return seconds;
}

/* Verbose quicksort median of 5 random pivot function
    used in main loop calls */
float q5rl (int x){
  clock_t t1,t2;
  int a[x];
  int n = sizeof(a)/sizeof(a[0]);

  clear(a, n);
  fill(a, n);
  printf("Original array:\n");
  print(a, n);
  t1=clock();
  q5r(a,0,n-1);
  t2=clock();
  float diff = (t2-t1);
  float seconds = diff / CLOCKS_PER_SEC;

  printf("\nQuick Sorted array:\n");
  print(a, n);
  printf("\nQuicksort Median of Five Random Pivot Sort Time On %i Elements: %.10f seconds.\n", x, seconds);
  return seconds;
}

/* Silent quicksort right pivot function
  used to display sort time in main */
float qrps (int y){
  clock_t t1,t2;
  int a[y];
  int n = sizeof(a)/sizeof(a[0]);

  fill(a, n);
  t1=clock();
  qrp(a,0,n-1);
  t2=clock();
  float diff = (t2-t1);
  float seconds = diff / CLOCKS_PER_SEC;

  printf("\nQuicksort Right Pivot Sort Time On %i Elements: %.10f seconds.\n", y, seconds);
  return seconds;
}

/* Silent quicksort median of three pivot function
  used to display sort time in main */
float qm3s (int y){
  clock_t t1,t2;
  int a[y];
  int n = sizeof(a)/sizeof(a[0]);

  clear(a, n);
  fill(a, n);
  t1=clock();
  qm3(a,0,n-1);
  t2=clock();
  float diff = (t2-t1);
  float seconds = diff / CLOCKS_PER_SEC;

  printf("\nQuicksort Median of Three Sort Time On %i Elements: %.10f seconds.\n", y, seconds);
  return seconds;
}

/* Silent quicksort median of 5 random pivot function
  used to display sort time in main */
float q5rs (int y){
  clock_t t1,t2;
  int a[y];
  int n = sizeof(a)/sizeof(a[0]);

  clear(a, n);
  fill(a, n);
  t1=clock();
  q5r(a,0,n-1);
  t2=clock();
  float diff = (t2-t1);
  float seconds = diff / CLOCKS_PER_SEC;

  printf("\nQuicksort Median of Five Random Pivot Sort Time On %i Elements: %.10f seconds.\n", y, seconds);
  return seconds;
}

void script (int s, int y){
  float rt = 0;                   //sort running time
  float art = 0;                  //sort average running time

  /* Running times for each algorithm using 50 element arrays
      and verbose functions */
    printf("\nExample of each algorithm working on %i random element arrays.\n", s);


    printf("\nQuicksort Right Pivot sort on %i elements.\n", s);
    rt += qrpl(s);
    art = rt/10;

    rt = 0;
    art = 0;

    printf("\nQuicksort Median of Three Pivot sort on %i elements.\n", s);
    rt += qm3l(s);
    art = rt/10;

    rt = 0;
    art = 0;

    printf("\nQuicksort Median of Five Random Pivot sort on %i elements.\n", s);
    rt += q5rl(s);
    art = rt/10;

    rt = 0;
    art = 0;

  /* Sort times for each algorithm using 10^3 element arrays
      and silent functions */
    printf("\nSort Times For %i Elements:", y);
    qrps(y);
    qm3s(y);
    q5rs(y);
}

void analysis(){
  int x = pow(10,2);              //used to initialize 10^2 element arrays
  int y = pow(10,3);              //used to initialize 10^3 element arrays
  int z = pow(10,4);              //used to initialize 10^4 element arrays
  float rt = 0;                   //sort running time
  float art = 0;                  //sort average running time

/* Below used for gathering required comparison statistics */
  for (int i=0; i<10; i++){
    rt += qrps(x);
  }
  art = rt/10;
  printf("\nAvg (of 10) Right Pivot Running Time For %i elements: %.10f seconds.\n", x, art);
  rt = 0;
  art = 0;

  for (int i=0; i<10; i++){
    rt += qm3s(x);
  }
  art = rt/10;
  printf("\nAvg (of 10) Median of Three Pivot Running Time For %i elements: %.10f seconds.\n", x, art);
  rt = 0;
  art = 0;

  for (int i=0; i<10; i++){
    rt += q5rs(x);
  }
  art = rt/10;
  printf("\nAvg (of 10) Median of Random 5 Pivot Running Time For %i elements: %.10f seconds.\n", x, art);
  rt = 0;
  art = 0;

  for (int i=0; i<10; i++){
    rt += qrps(y);
  }
  art = rt/10;
  printf("\nAvg (of 10) Right Pivot Running Time For %i elements: %.10f seconds.\n", y, art);
  rt = 0;
  art = 0;

  for (int i=0; i<10; i++){
    rt += qm3s(y);
  }
  art = rt/10;
  printf("\nAvg (of 10) Median of Three Pivot Running Time For %i elements: %.10f seconds.\n", y, art);
  rt = 0;
  art = 0;

  for (int i=0; i<10; i++){
    rt += q5rs(y);
  }
  art = rt/10;
  printf("\nAvg (of 10) Median of Random 5 Pivot Running Time For %i elements: %.10f seconds.\n", y, art);
  rt = 0;
  art = 0;

  for (int i=0; i<10; i++){
    rt += qrps(z);
  }
  art = rt/10;
  printf("\nAvg (of 10) Right Pivot Running Time For %i elements: %.10f seconds.\n", z, art);
  rt = 0;
  art = 0;

  for (int i=0; i<10; i++){
    rt += qm3s(z);
  }
  art = rt/10;
  printf("\nAvg (of 10) Median of Three Pivot Running Time For %i elements: %.10f seconds.\n", z, art);
  rt = 0;
  art = 0;

  for (int i=0; i<10; i++){
    rt += q5rs(z);
  }
  art = rt/10;
  printf("\nAvg (of 10) Median of Random 5 Pivot Running Time For %i elements: %.10f seconds.\n", z, art);
  rt = 0;
  art = 0;

}

int main(int argc, char* argv[]){
  srand(time(NULL));
  int y = pow(10,3);              //used to initialize 10^3 element arrays
  int s = 50;                     //used to initialize 50 element arrays

/* Uncomment lines between here and end script to run script */

  //script(s, y);

/* End script */

/* Uncomment lines between here and end analysis to run analysis */

  analysis();

/* End analysis */
  return 0;
}
