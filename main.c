#include <stdio.h>
#include <stdlib.h>

const int SIZE = 1;

typedef struct Node{
    int item;

    struct Node *left;
    struct Node *right;
} Node;

Node *root;

Node * createNode(int item){
  Node *node = (Node *)malloc(sizeof(Node));
  node->left = NULL;
  node->right = NULL;
  node->item = item;

  return node;
}



Node * insertLeft(int item, Node* node){
  node->left = createNode(item);
  return node->left;
}

Node * insertRight(int item, Node* node){
  node->right = createNode(item);
  return node->right;
}

void inOrderTraversal(Node *root){
    if (!root) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->item);
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root){
    if (root) {
      printf("%d ", root->item);
      preOrderTraversal(root->left);
      preOrderTraversal(root->right);
    }
}

void postOrderTranversal(Node *root){
  if (root){
    postOrderTranversal(root->left);
    postOrderTranversal(root->right);
    printf("%d ", root->item);
  }
}

void clean(Node *root){
  if (!root->right && !root->left){
    free(root);
  }else if (root->left){
    clean(root->left);
  }else if(root->right){
    clean(root->right);
  }
}

int main(){
  root = createNode(5);

  insertLeft(3, root);
  insertRight(4, root);

  printf("\nIn Order Traversal: \n");
  inOrderTraversal(root);

  printf("\nPre Order Traversal:\n");
  preOrderTraversal(root);

  printf("\nPost Order Traversal:\n");
  postOrderTranversal(root);

  clean(root);
  return 0; 
}


