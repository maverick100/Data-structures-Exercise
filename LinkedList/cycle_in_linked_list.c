#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
  int data;
  struct node *next;
};


struct node *start=NULL;

void  push(int x ) {
  /* code */
  struct node *t = (struct node *)malloc(sizeof(struct node));
  struct node *curr;
  if(start == NULL){
    start=t;
    start->data=x;
    start->next=NULL;
    return;
  }
  curr=start;
  while(curr->next != NULL)
    curr=curr->next;
  curr->next=t;
  t->data=x;
  t->next=NULL;


}


void traverse(){

  struct node *t;
  t = start;
  while(t->next != NULL){
    printf("%d-->",t->data );
    t=t->next;
  }
  printf("%d",t->data );
}

bool detect_loop(){

  struct node *slow,*fast;

  while(slow && fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast)
      return true;
  }
  return false;
}





void main(){

  int i,data,count;
  scanf("%d\n",&count );
  for(i=0;i<count;i++){
  printf("Enter the data\n" );
  scanf("%d\n",&data );
  push(data);
}
traverse();
detect_loop()? printf("Yes\n") : printf("No\n");

}
