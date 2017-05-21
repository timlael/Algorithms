/*
  Tim M. Lael
  CS 3010 e01
  Project 2
  Part A - Mergesort
*/
#include <iostream>
#include <ctime>
#include <cmath>

/* 	Array fill function */
int fill(int *array, int size){
	for(int i=0; i<size; i++){
		array[i] = (rand()%1000000);
  }
  return *array;
}

/* 	Array zero function */
int clear(int *array, int size){
	for(int i=0; i<size; i++){
		array[i] = 0;
  }
  return *array;
}

/* 	Array print function */
int print(int *array, int n){
	for(int row=0; row<n/10; row++){
		for(int col=0; col<10; col++){
			printf("%i \t", array[(row*10)+col]);
  	}
	printf("\n");
	}
return *array;
}

/* Array append function */
int appendArray(int *sa, int *la, int *oa ,int sasize, int lasize){
	for (int i=0; i<lasize; i++) {
		oa[i] = la[i];
  }
	for (int j = lasize, k=0; j<lasize + sasize; j++, k++){
	  oa[j] = sa[k];
  }
return *oa;
}

/* Merge sorted arrays function */
int mergeTwo(int *sa, int *la, int *oa, int sasize, int lasize){
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < sasize && j < lasize){
  	if (sa[i] < la[j]){
    	oa[k] = sa[i];
      i++;
    }
    else{
      oa[k] = la[j];
      j++;
    }
    k++;
  }
  if (i >= sasize){
  	while (j < lasize){
    	oa[k] = la[j];
      j++;
      k++;
    }
  }
  if (j >= lasize){
  	while (i < sasize){
    	oa[k] = sa[i];
      	i++;
        k++;
    }
  }
return *oa;
}

/* Order and merge function */
void merge(int *arr, int *temp, int left, int mid, int right){
	int i, left_end, num_elements, tmp_pos;
  left_end = mid - 1;
  tmp_pos = left;
  num_elements = right - left + 1;

	while ((left <= left_end) && (mid <= right)){
  	if (arr[left] <= arr[mid]){
    	temp[tmp_pos] = arr[left];
    	tmp_pos = tmp_pos + 1;
    	left = left +1;
		}
    else{
    	temp[tmp_pos] = arr[mid];
      tmp_pos = tmp_pos + 1;
      mid = mid + 1;
		}
	}

	while (left <= left_end){
  	temp[tmp_pos] = arr[left];
    left = left + 1;
    tmp_pos = tmp_pos + 1;
	}

	while (mid <= right){
  	temp[tmp_pos] = arr[mid];
    mid = mid + 1;
    tmp_pos = tmp_pos + 1;
  }

	for (i = 0; i <= num_elements; i++){
  	arr[right] = temp[right];
    right = right - 1;
	}
}

/* Recursively break into smaller chunks and sort */
void m_sort(int *arr, int *temp, int left, int right){
	int mid;

	if (right > left){
  	mid = (right + left) / 2;
    m_sort(arr, temp, left, mid);
    m_sort(arr, temp, mid+1, right);
    merge(arr, temp, left, mid+1, right);
	}
}

/* Main mergesort control function */
void mergeSort(int *arr, int *temp, int array_size){
	m_sort(arr, temp, 0, array_size - 1);
}

/* Method 1 - Append smaller array then re-sort */
void appendSort(int small, int large){
	int narray[small];
  int marray[large];
  int out[large+small];
	int temp[large+small];
	int mtemp[large];

  fill(narray, small);
  fill(marray, large);
	mergeSort(marray,mtemp,large);
  printf("\nSmall array:\n");
  print(narray, small);
  printf("\nLarge array:\n");
  print(marray, large);

  appendArray(narray, marray, out, small, large);
  printf("\nAppended array:\n");
	print(out, small + large);
	mergeSort(out,temp,large+small);
  printf("\nSorted array:\n");
	print(out, small + large);

}

/* Methos 2 - Sort smaller array then
	append two sorted arrays */
void sortMerge(int small, int large){
	int marray[small];
  int narray[large];
  int out[large+small];
	int temp[large+small];
	int mtemp[small];
	int ntemp[large];

	fill(narray, large);
  fill(marray, small);
	mergeSort(narray, ntemp, large);
	printf("\nOriginal sorted large array of %i elements:\n", large);
  print(narray, large);
  printf("\nOriginal unsorted small array of %i elements:\n", small);
  print(marray, small);
	mergeSort(marray, mtemp, small);
	printf("\nSorted small array:\n");
	print(marray, small);
	mergeTwo(marray, narray, out, small, large);
	printf("\nMerged array of %i elements:\n", small+large);
	print(out, small + large);
}

/* Used to run and gather statistics for analysis*/
float analysis(int m, int n){
    clock_t t1,t2;
    int a[n];
		int b[m];
		int o[n+m];
		int temp[n+m];
		int as = sizeof(a)/sizeof(a[0]);
		int bs = sizeof(b)/sizeof(b[0]);

    fill(a, as);
		fill(b, bs);

		t1=clock();
		appendArray(a, b, o, as, bs);
		mergeSort(o,temp,n+m);
    t2=clock();
    float diff = (t2-t1);
    float seconds = diff / CLOCKS_PER_SEC;
    return seconds;
}

/* Used to run functions for script output */
void script(int small, int large){
	int a[small];
	int t[small];

	fill(a, small);
	printf("\nMerge sort operation working on 100 element array:\n");
	printf("\nOriginal 100 element array\n");
	print(a, small);
	mergeSort(a, t, small);
	printf("\nSorted 100 element array\n");
	print(a,small);
	clear(a, small);
	printf("\nSorting a smaller file and merging it with a larger file:\n");
	printf("\n** Note: 100 elements chosen for small file and 500 for large since sizes weren't explicitly specified for this step. **\n");

	sortMerge(small, large);
}

void analysis(){
	int x = pow(10,3);
	int y = pow(10,4);
	int z = pow(10,5);
	int m1 = 25;
	int m2 = 50;
	int m3 = 100;
	float rt;
	float art;

	for (int i=0; i<10; i++){
	  rt += analysis(x, m1);
	}
	art = rt/10;
	printf("\nAvg running time for N = %i and M = %i: %.10f seconds.\n", x, m1, art);
	art = rt = 0;

	for (int i=0; i<10; i++){
	  rt += analysis(x, m2);
	}
	art = rt/10;
	printf("\nAvg running time for N = %i and M = %i: %.10f seconds.\n", x, m2, art);
	art = rt = 0;

	for (int i=0; i<10; i++){
	  rt += analysis(x, m3);
	}
	art = rt/10;
	printf("\nAvg running time for N = %i and M = %i: %.10f seconds.\n", x, m3, art);
	art = rt = 0;

	for (int i=0; i<10; i++){
	  rt += analysis(y, m1);
	}
	art = rt/10;
	printf("\nAvg running time for N = %i and M = %i: %.10f seconds.\n", y, m1, art);
	art = rt = 0;

	for (int i=0; i<10; i++){
	  rt += analysis(y, m2);
	}
	art = rt/10;
	printf("\nAvg running time for N = %i and M = %i: %.10f seconds.\n", y, m2, art);
	art = rt = 0;

	for (int i=0; i<10; i++){
	  rt += analysis(y, m3);
	}
	art = rt/10;
	printf("\nAvg running time for N = %i and M = %i: %.10f seconds.\n", y, m3, art);
	art = rt = 0;
	for (int i=0; i<10; i++){
	  rt += analysis(z, m1);
	}
	art = rt/10;
	printf("\nAvg running time for N = %i and M = %i: %.10f seconds.\n", z, m1, art);
	art = rt = 0;

	for (int i=0; i<10; i++){
	  rt += analysis(z, m2);
	}
	art = rt/10;
	printf("\nAvg running time for N = %i and M = %i: %.10f seconds.\n", z, m2, art);
	art = rt = 0;

	for (int i=0; i<10; i++){
	  rt += analysis(z, m3);
	}
	art = rt/10;
	printf("\nAvg running time for N = %i and M = %i: %.10f seconds.\n", z, m3, art);
	art = rt = 0;
}



int main(int argc, char* argv[]){
	srand(time(NULL));
	int m3 = 100;

/* Uncomment lines between here and end script to run script */

	//script(m3, 500);

/* End Script */

/* Uncomment lines between here and end analysis to run analysis */

	analysis();

/* End Analysis */


  return 0;
}
