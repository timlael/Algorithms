/*
  Tim M. Lael
  CS 3010 e01
  Project 2
  Part C - Heapsort
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

/* Sift elements down function */
void sift_down(int a[], int size, int l){
	int i,j, x;
  i = l;
  j = 2*i+1;
  x = a[i];

  while (j < size){
    if ( j < size - 1)
      if ( a[j] < a[j+1])
        ++j;
    	if (x >= a[j])
        break;
    	a[i] = a[j];
    	i = j;
    	j = 2*i + 1; // sift
  }
  a[i] = x;
}

/* Build heap function */
void build_heap(int a[], int size){
  int l = size / 2;

  while (l){
    --l;
    sift_down(a, size, l);
  }
}

/* Silent heapsort function */
void heapsorts(int a[], int size){
	clock_t b1,b2;
	clock_t s1,s2;
  int l = 0, r = size;

	/* Heap build phase */
	b1=clock();
	build_heap(a, size);
  b2=clock();
	float build = (b2-b1);
  float bsec = build / CLOCKS_PER_SEC;
	printf("\nHeap build time: %.10f seconds.\n", bsec);

  build = bsec = 0;

  /*Heap sort phase */
	s1=clock();
  while ( r > 1){
    int tmp = a[0];
    --r;
    a[0] = a[r];
    a[r] = tmp;
    sift_down(a, r, 0);
  }
	s2=clock();
  float srt = (s2-s1);
  float ssec = srt / CLOCKS_PER_SEC;
	printf("\nActual sorting time: %.10f seconds.\n", ssec);
  srt = ssec = 0;
}

/* Verbose heapsort function
	used to display heap after building*/
void heapsortv(int a[], int size){
	clock_t b1,b2;
	clock_t s1,s2;
  int l = 0, r = size;

/* Heap build phase */
	b1=clock();
	build_heap(a, size);
  b2=clock();
	float build = (b2-b1);
  float bsec = build / CLOCKS_PER_SEC;
/* Show built heap */
  printf("\nHeap:\n");
  print(a, size);
	printf("\nHeap build time: %.10f seconds.\n", bsec);

  build = bsec = 0;

/* Heap sort phase */
	s1=clock();
  while ( r > 1){
    int tmp = a[0];
    --r;
    a[0] = a[r];
    a[r] = tmp;
    sift_down(a, r, 0);
  }
	s2=clock();
  float srt = (s2-s1);
  float ssec = srt / CLOCKS_PER_SEC;
	printf("\nActual sorting time: %.10f seconds.\n", ssec);
  srt = ssec = 0;
}

/* Silent heapsort function with no array output
  used to display sort times only in analysis */
float heaps (int p){
  clock_t t1,t2;
  int a[p];
  int n = sizeof(a)/sizeof(a[0]);

  fill(a, n);
  t1=clock();
  heapsorts(a, n);
  t2=clock();
  float diff = (t2-t1);
  float seconds = diff / CLOCKS_PER_SEC;

  printf("\nHeapsort actual build/sort/aggregate time: %.10f seconds.\n", seconds);
  return seconds;
}

/* Verbose heapsort function with arrays displayed
  used to display sort times and arrays */
float heapv (int k){
  clock_t t1,t2;
  int a[k];
  int n = sizeof(a)/sizeof(a[0]);

  clear(a, n);
  fill(a, n);
  printf("Original array:\n");
  print(a, n);
  t1=clock();
  heapsortv(a, n);
  t2=clock();
  float diff = (t2-t1);
  float seconds = diff / CLOCKS_PER_SEC;

  printf("\nHeapsorted array:\n");
  print(a, n);
  printf("\nHeapsort actual build/sort/aggregate time: %.10f seconds.\n", seconds);
  return seconds;
}

void script(int s){
  int w = pow(10,3);              //used to initialize 10^3 element arrays
  float rt = 0;                   //sort running time
  float art = 0;                  //sort average running time

  printf("\nStatistics and arrays displayed for array of size N = 50:\n");
  rt += heapv(s);
  art = rt/1;
  printf("\nTotal heapsort running time For %i elements: %.10f seconds.\n", s, art);

  rt = 0;
  art = 0;
  printf("\nStatistics for array of size N = 10^3:");
  heaps(w);


}

void analysis(){
  int w = pow(10,3);              //used to initialize 10^3 element arrays
  int x = pow(10,4);              //used to initialize 10^4 element arrays
  int y = pow(10,5);              //used to initialize 10^5 element arrays
  int z = pow(10,6);              //used to initialize 10^6 element arrays
  float rt = 0;                   //sort running time
  float art = 0;                  //sort average running time

/* Below used for gathering required comparison statistics */
  for (int i=0; i<10; i++){
    printf("\nArray %i:\n", i+1);
    rt += heaps(w);
  }
  art = rt/10;
  printf("\nTotal avg. (of 10) heapsort running time For %i elements: %.10f seconds.\n", w, art);

  rt = 0;
  art = 0;

  for (int i=0; i<10; i++){
    printf("\nArray %i:\n", i+1);
    rt += heaps(x);
  }
  art = rt/10;
  printf("\nTotal avg. (of 10) heapsort running time For %i elements: %.10f seconds.\n", x, art);

  rt = 0;
  art = 0;

  for (int i=0; i<10; i++){
    printf("\nArray %i:\n", i+1);
    rt += heaps(y);
  }
  art = rt/10;
  printf("\nTotal avg. (of 10) heapsort running time For %i elements: %.10f seconds.\n", y, art);

  rt = 0;
  art = 0;

  for (int i=0; i<10; i++){
    printf("\nArray %i:\n", i+1);
    rt += heaps(z);
  }
  art = rt/10;
  printf("\nTotal avg. (of 10) heapsort running time For %i elements: %.10f seconds.\n", z, art);

  rt = 0;
  art = 0;
}

int main(int argc, char* argv[]){
  srand(time(NULL));
  int s = 50;                     //used to initialize 50 element arrays

/* Uncomment lines between here and end script to run script */

  //script(s);

/* End script */

/* Uncomment lines between here and end analysis to run analysis */

  analysis();

/* End Analysis */


  return 0;
}
