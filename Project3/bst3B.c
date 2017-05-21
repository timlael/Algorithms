/*
  Tim M. Lael
  CS 3010 e01
  Project 3 Part B
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node{
    int key;
    int count;
    struct node *l;
    struct node *r;
} node_t;
node_t *root = NULL, *temp = NULL, *t2, *t1;

int a[100];
int b[500];
int c[1000];
int x = sizeof(a)/sizeof(a[0]);
int y = sizeof(b)/sizeof(b[0]);
int z = sizeof(c)/sizeof(c[0]);

void findPlace(struct node *n);
int treeHeight(struct node *n);
void create(int *array);
int fill(int *array, int size);
int clear(int *array, int size);

int main(){
    srand(time(NULL));
    int d = 0;

   for (int j = 0; j < 5; j++){
      clear(a,x);
      fill(a,x);
      //print(a,x);
      create(a);
      printf("%d\t", treeHeight(root));
      d += treeHeight(root);
    }
    printf("\nAverage Tree height for 5 trees with %i elements is: %d\n\n", x, d/5);

    d = 0;

    for (int j = 0; j < 10; j++){
      clear(a,x);
      fill(a,x);
      //print(a,x);
      create(a);
      printf("%d\t", treeHeight(root));
      d += treeHeight(root);
    }
    printf("\nAverage Tree height for 10 trees with %i elements is: %d\n\n", x, d/10);

    d = 0;

    for (int j = 0; j < 15; j++){
      clear(a,x);
      fill(a,x);
      //print(a,x);
      create(a);
      printf("%d\t", treeHeight(root));
      d += treeHeight(root);
    }
    printf("\nAverage Tree height for 15 trees with %i elements is: %d\n\n", x, d/15);

    d = 0;

    for (int j = 0; j < 5; j++){
      clear(b,y);
      fill(b,y);
      //print(a,x);
      create(b);
      printf("%d\t", treeHeight(root));
      d += treeHeight(root);
    }
    printf("\nAverage Tree height for 5 trees with %i elements is: %d\n\n", y, d/5);

    d = 0;

    for (int j = 0; j < 10; j++){
      clear(b,y);
      fill(b,y);
      //print(a,x);
      create(b);
      printf("%d\t", treeHeight(root));
      d += treeHeight(root);
    }
    printf("\nAverage Tree height for 10 trees with %i elements is: %d\n\n", y, d/10);

    d = 0;

    for (int j = 0; j < 15; j++){
      clear(b,y);
      fill(b,y);
      //print(a,x);
      create(b);
      printf("%d\t", treeHeight(root));
      d += treeHeight(root);
    }
    printf("\nAverage Tree height for 15 trees with %i elements is: %d\n\n", y, d/15);

    d = 0;

    for (int j = 0; j < 5; j++){
      clear(c,z);
      fill(c,z);
      //print(a,x);
      create(c);
      printf("%d\t", treeHeight(root));
      d += treeHeight(root);
    }
    printf("\nAverage Tree height for 5 trees with %i elements is: %d\n\n", z, d/5);

    d = 0;

    for (int j = 0; j < 10; j++){
      clear(c,z);
      fill(c,z);
      //print(a,x);
      create(c);
      printf("%d\t", treeHeight(root));
      d += treeHeight(root);
    }
    printf("\nAverage Tree height for 10 trees with %i elements is: %d\n\n", z, d/10);

    d = 0;

    for (int j = 0; j < 15; j++){
      clear(c,z);
      fill(c,z);
      //print(a,x);
      create(c);
      printf("%d\t", treeHeight(root));
      d += treeHeight(root);
    }
    printf("\nAverage Tree height for 15 trees with %i elements is: %d\n\n", z, d/15);

}

/* Function to find the correct place in the
    BST to insert the new node */
void findPlace(struct node *n){
    /* if key equals current node key, increment counter
        This is duplicate key handler */
    if (temp->key == n->key)
        n->count = n->count + 1;
    /* Branch to right if value is larger than root */
    else if ((temp->key > n->key) && (n->r != NULL))
        findPlace(n->r);
    /* Place value in first appropriate NULL right position */
    else if ((temp->key > n->key) && (n->r == NULL))
        n->r = temp;
    /* Branch to left if value is smaller than root */
    else if ((temp->key < n->key) && (n->l != NULL))
        findPlace(n->l);
    /* Place value in first appropriate NULL left position */
    else if ((temp->key < n->key) && (n->l == NULL))
        n->l = temp;
}

int treeHeight(struct node *n){
    int left = 0;
    int right = 0;

    if(n == NULL){
        return 0;
    }
    else{
        left = treeHeight(n->l);
        right = treeHeight(n->r);
        if( left > right || left == right){
            return (left + 1);
        }
        else{
            return (right + 1);
        }
    }
  }

void create(int *array){

    /* Fill BST with array values given */
    for (int i=0; i < x; i++){
      temp = (struct node *)malloc(1*sizeof(struct node));
      temp->key = array[i];
      temp->l = temp->r = NULL;

      if (root == NULL)
          root = temp;

    /* if key equals root key, increment counter
        This is duplicate root key handler */
      else if(root->key == array[i]){
        root->count = root->count +1;
      }
      else
          findPlace(root);
    }
}

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
