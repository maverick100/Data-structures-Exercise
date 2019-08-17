#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


struct node{
  int key;
  struct node *left,*right;
};

struct node *insert(struct node *root,int key){

  if(root==NULL){
    root=(struct node*)malloc(sizeof(struct node));
    root->key=key;
    root->left=root->right=NULL;
  }

  else if(root->key < key)
    root->right=insert(root->right,key);
  else if(root->key > key)
    root->left=insert(root->left,key);


return root;
}

bool isbalanced(struct node *root,int *height){

  int lr=0,lf=0;
  int l=0,r=0;

  if(root==NULL){
    *height=0;
    return 1;
  }

  l=isbalanced(root->left, &lf);
  r=isbalanced(root->right,&lr);

  *height=(lf>lr?lf:lr)+1;

  printf("left=%d\t",lf );
  printf("right=%d\n",lr );

  if ((lr - lf >= 2) || (lf - lr >= 2))
        return 0;


  else
  return l && r;



}


int main(){
  int height=0;
  struct node *root=NULL;
  root=insert(root,10);
  root=insert(root,30);
  root=insert(root,8);
  root=insert(root,5);
  root=insert(root,2);

  if(isbalanced(root,&height))
    printf("True" );
}
