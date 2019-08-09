#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



struct Node{
  int data;
  struct Node *next;
};

struct Node *start = NULL;
void insert_beg(int);
void traverse();
void delete_beg();
void delete_end();
void middle();
void reverse();
void delte_node(int);
bool recursive_search(struct Node *t,int x);


bool recursive_search(struct Node *t,int x){

if(t->data == x)
  return true;
else
  return (t->next,x);

}


void  delete_node(int x){
  struct Node *t,*prev;
  t=start;
  while(t->next != NULL){
    if(t->data == x){
      prev->next=t->next;
      free(t);
      return;
    }
    prev=t;
    t=t->next;

  }
}


void  reverse(/* arguments */) {
  /* code */

  struct Node *curr=start;
  struct Node *next,*prev=NULL;

  while (curr != NULL) {
    /* code */
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;

  }
  start=prev;
}


void  middle(){

  struct Node *fast_ptr = start;
  struct Node *slow_ptr = start;

  while(fast_ptr != NULL && fast_ptr->next != NULL){
    fast_ptr=fast_ptr->next->next;
    slow_ptr=slow_ptr->next;
  }

  printf("\n%d\n",slow_ptr->data );
}



void delete_beg(/* arguments */) {
  /* code */
  struct Node *t;
  t=start->next;
  free(start);
  start=t;

}

void delete_end(){
  struct Node *t,*prev;
  t=start;
  while(t->next!= NULL){
    prev=t;
    t=t->next;
  }
  prev->next=NULL;

}

void insert_beg(int x){

  struct Node *t;
  t = (struct Node*)malloc(sizeof(struct Node));

   if(start == NULL){
     start = t;
     start->data = x;
     start->next = NULL;
     return;
   }

   t->data=x;
   t->next=start;
   start = t;
}


void traverse(){

  struct Node *t;
  t = start;
  while(t->next != NULL){
    printf("%d-->",t->data );
    t=t->next;
  }
  printf("%d",t->data );
}





int main(){
int i,data;

  for (i=0;i<5;i++){
    printf("ENter the data\n");
    scanf("%d\n",&data );
    insert_beg(data);

  }

  traverse();

  /* delete_beg();
  printf("\n");
  traverse();
  printf("\n" );
  delete_end();
  printf("\n");
  traverse();  */

  reverse();
  traverse();

  delete_node(3);
  traverse();

  recursive_search(start,4)? printf("Yes") : printf("No\n");

}
