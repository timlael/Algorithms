/*
  Tim M. Lael
  CS 3010 e01
  Project 3 Part A
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *l;
    struct node *r;
}*root = NULL, *temp = NULL, *t2, *t1;

int arr[] = {30, 10, 45, 38, 20, 50, 25, 33, 8, 12};

void insert();
void fillNode();
void findPlace(struct node *n);
void findDelete();
void delSearch(struct node *n, int data);
void delete();
void IOTW(struct node *n);
void PRTW(struct node *n);
void PSTW(struct node *n);
int minVal(struct node *n);
int maxVal(struct node *n);
void treeSearch(struct node *n, int data);
int treeHeight(struct node *n);
void create(int *array);

int main(){
    int choice;
    int data;

    create(arr);

    printf("\n************ Select An Option ************\n");
    printf("1 -> \tInsert A Node Into Tree\n");
    printf("2 -> \tDelete A Node From Tree\n");
    printf("3 -> \tIn-Order Traversal Walk\n");
    printf("4 -> \tPre-Order Traversal Walk\n");
    printf("5 -> \tPost-Order Traversal Walk\n");
    printf("6 -> \tSearch For Value In Tree\n");
    printf("7 -> \tCalculate And Display Tree Height\n");
    printf("8 -> \tExit");
    printf("\n******************************************\n");

    /* Selection Menu */
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice){
          case 1:
            insert();
            break;
          case 2:
            findDelete();
            break;
          case 3:
            printf("\nIn Order Traversal:\n");
            IOTW(root);
            break;
          case 4:
            printf("\nPre-Order Traversal:\n");
            PRTW(root);
            break;
          case 5:
            printf("\nPost-Order Traversal:\n");
            PSTW(root);
            break;
          case 6:
            printf("\nEnter search value: ");
            scanf("%d", &data);
            treeSearch(root, data);
            break;
          case 7:
            printf("\nTree height is: %d\n", treeHeight(root));
            break;
          case 8:
            exit(0);
          default:
            printf("\nWrong choice, Please enter correct choice:\n");
            break;
        }
    }
}

/* Function to Insert node into BST */
void insert(){
    fillNode();
    if (root == NULL)
        root = temp;
    else
        findPlace(root);
}

/* Function to allocate/fill values in a new node
    to be placed into a BST */
void fillNode(){
    int data;

    printf("\nEnter data of node to be inserted: ");
    scanf("%d", &data);
    temp = (struct node *)malloc(1*sizeof(struct node));
    temp->key = data;
    temp->l = temp->r = NULL;
}

/* Function to find the correct place in the
    BST to insert the new node */
void findPlace(struct node *n){
    /* Branch to right if value is larger than root */
    if ((temp->key > n->key) && (n->r != NULL))
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

/* Beginning of node deletion function
    Check for empty tree then grab value to be deleted */
void findDelete(){
    int data;

    if (root == NULL){
        printf("\nNo elements in a tree to delete\n");
        return;
    }
    printf("\nEnter the data to be deleted: ");
    scanf("%d", &data);
    t1 = root;
    t2 = root;
    delSearch(root, data);
}

/* Find value to be deleted and pass to delete function
    If node is not found, user will get feedback */
void delSearch(struct node *n, int data){
    if (data > n->key){
        t1 = n;
        if(n->r == NULL){
          printf("\nNo such element in tree to delete\n");
          return;
        }
        else
        delSearch(n->r, data);
    }
    else if (data < n->key){
        t1 = n;
        if(n->l == NULL){
          printf("\nNo such element in tree to delete\n");
          return;
        }
        else
        delSearch(n->l, data);
    }
    else if (data == n->key){
        delete(n);
    }
}

/* Node deletion and child placement */
void delete(struct node *n){
    int k;

    /* Deleting Leaf Level node (no children) */
    if ((n->l == NULL) && (n->r == NULL)){
        if (t1->l == n){
            t1->l = NULL;
        }
        else if (t1->r == n){
            t1->r = NULL;
        }
        n = NULL;
        free(n);
        return;
    }

    /* Delete a node with a left hand child */
    else if (n->r == NULL){
        if (t1 == n){
            root = n->l;
            t1 = root;
        }
        else if (t1->l == n){
            t1->l = n->l;

        }
        else{
            t1->r = n->l;
        }
        n = NULL;
        free(n);
        return;
    }

    /* Delete a node with a right hand child */
    else if (n->l == NULL){
        if (t1 == n){
            root = n->r;
            t1 = root;
        }
        else if (t1->r == n)
            t1->r = n->r;
        else
            t1->l = n->r;
        n = NULL;
        free(n);
        return;
    }

    /* Deleting a node with two children */
    else if ((n->l != NULL) && (n->r != NULL)){
        t2 = root;
        if (n->r != NULL){
            k = minVal(n->r);
        }
        else{
            k = maxVal(n->l);
        }
        delSearch(root, k);
        n->key = k;
    }
}

/* In-order traversal Walk */
void IOTW(struct node *n){
    if (root == NULL){
        printf("\nNo elements in a tree to display\n");
        return;
    }
    if (n->l != NULL)
        IOTW(n->l);
    printf("%d\t", n->key);
    if (n->r != NULL)
        IOTW(n->r);
}

/* Pre-Order Traversal Walk */
void PRTW(struct node *n){
    if (root == NULL){
        printf("\nNo elements in a tree to display\n");
        return;
    }
    printf("%d\t", n->key);
    if (n->l != NULL)
        PRTW(n->l);
    if (n->r != NULL)
        PRTW(n->r);
}

/* Post-Order Traversal Walk */
void PSTW(struct node *n){
    if (root == NULL){
        printf("\nNo elements in a tree to display\n");
        return;
    }
    if (n->l != NULL)
        PSTW(n->l);
    if (n->r != NULL)
        PSTW(n->r);
    printf("%d\t", n->key);
}

/* To find the smallest element in the right sub tree */
int minVal(struct node *n){
    t2 = n;
    if (n->l != NULL){
        t2 = n;
        return(minVal(n->l));
    }
    else
        return (n->key);
}

/* To find the largest element in the left sub tree */
int maxVal(struct node *n){
    if (n->r != NULL){
        t2 = n;
        return(maxVal(n->r));
    }
    else
        return(n->key);
}

void treeSearch(struct node *n, int data){
    if (data > n->key){
        t1 = n;
        if(n->r == NULL)
        printf("\n%i not in tree.\n", data);
        else
        treeSearch(n->r, data);
    }
    else if (data < n->key){
        t1 = n;
        if(n->l == NULL)
        printf("\n%i not in tree.\n", data);
        else
        treeSearch(n->l, data);
    }
    else if (data == n->key){
      printf("\nFound %i at: %p.\n", data, n);
    }
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
    for (int i=0; i < sizeof(arr)/sizeof(arr[0]); i++){
      temp = (struct node *)malloc(1*sizeof(struct node));
      temp->key = arr[i];
      temp->l = temp->r = NULL;

      if (root == NULL)
          root = temp;
      else
          findPlace(root);
    }
}
