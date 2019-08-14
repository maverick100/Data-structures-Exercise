#include<stdio.h>
#include<stdlib.h>

struct  node {
  int key;
  struct node *left,*right;
};


struct node *min_value(struct node *x){
  struct node *temp=x;
  if(temp && temp->left !=NULL)
      temp=temp->left;
  return temp;
}


struct node *delete(struct node *temp,int x){
//struct node *temp = temp;
if (temp == NULL)
  return temp;
else if(x < temp->key)
  temp->left=delete(temp->left,x);
else if(x > temp->key)
    temp->right=delete(temp->right,x);

else{

  if(temp->left == NULL){
    struct node *curr=temp->right;
    free(temp);
    return curr;
  }
  else if(temp->right==NULL){
    struct node *curr =temp->left;
    free(temp);
    return curr;
  }
  else{

    struct node *t=min_value(temp->right);
    temp->key=t->key;
    temp->right=delete(temp->right,t->key);
  }
  return temp;
}





}




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

  return t;

}


void inorder_print(struct node *inorder){
  if(inorder != NULL){
    inorder_print(inorder->left);
    printf("%d\n",inorder->key );
    inorder_print(inorder->right);
  }
}


void main(){
  struct node *root =NULL;

  root=insert(root,20);
  root=insert(root,10);
  root=insert(root,30);
  root=insert(root,50);
  root=insert(root,5);
    inorder_print(root);

    delete(root,50);


  inorder_print(root);

}
