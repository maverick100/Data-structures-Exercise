#include<stdio.h>
#include<stdlib.h>

struct  node {
  int key;
  struct node *left,*right;
};


struct node *new_node(int x){
   struct node *temp=(struct node *)malloc(sizeof(struct node));

   temp->key=x;
   temp->left=temp->right=NULL;
   return temp;


}

struct node *insert(struct node *t,int x){

  if (t==NULL){
    return new_node(x);
  }
  else if(x < t->key)
    t->left=insert(t->left,x);
  else if(x>t->key)
    t->right=insert(t->right,x);

}


void inorder_print(struct node *inorder){
  if(inorder != NULL){
    inorder(inorder->left);
    printf("%d\n",inorder->key );
    inorder(inorder->right);
  }
}


void main(){
  struct node *root =NULL;

  root=insert(root,1);
  insert(root,2);
  insert(root,3);
  printf("%d\n",root->key );
  inorder_print(root)

}
