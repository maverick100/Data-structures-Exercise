#include<stdio.h>
#include<stdlib.h>

struct node{
  int key;
  struct node *left,*right;

};



struct node *insert(struct node *t,int x){
  if(t==NULL){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->key=x;
    temp->right=temp->left=NULL;
    return temp;
  }
  if(x<t->key)
    t->left=insert(t->left,x);
  else if(x>t->key)
    t->right=insert(t->right,x);

  return t;
}

void inorder(struct node *t){

  if(t==NULL)
    return;


    inorder(t->left);
    printf("%d\n",t->key );
    inorder(t->right);

  }


void preorder(struct node *t)
{

  if(t==NULL)
    return;

      printf("%d\n",t->key );
      inorder(t->left);
      inorder(t->right);
    }


void postorder(struct node *t)
    {
      if(t==NULL)
        return;

          inorder(t->left);
          inorder(t->right);
          printf("%d\n",t->key );
        }





void main(){
  struct node *root=NULL;

  root=insert(root,10);
  //printf("%d\n",root->key );
  //inorder(root);
  insert(root,20);
  insert(root,5);
  printf("INORDER\n");
  inorder(root);
  printf("preorder\n" );
  preorder(root);
  printf("postorder\n" );
  postorder(root);

}
