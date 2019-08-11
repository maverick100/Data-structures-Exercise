#include<bits/stdc++.h>

using namespace std;


struct node {
  int key;
  struct node *next;
};
struct node *start=NULL;

void  push(int x ) {
  /* code */
  struct node *t = (struct node *)malloc(sizeof(struct node));
  struct node *curr;
  if(start == NULL){
    start=t;
    start->key=x;
    start->next=NULL;
    return;
  }
  curr=start;
  while(curr->next != NULL)
    curr=curr->next;
  curr->next=t;
  t->key=x;
  t->next=NULL;


}

void traverse(){
  struct node *temp=start;
  while(temp != NULL){
    printf("%d\n",temp->key );
    temp=temp->next;
  }
}

void remove_duplicates(){

  unordered_set<int> seen;
  struct node *curr=start;
  struct node *prev=NULL;

  while(curr != NULL){
    if(seen.find(curr->key)==seen.end()){
      prev->next=curr->next;
      delete(curr);}
    else{
      seen.insert(curr->key);
      prev=curr;
    }
    curr=prev->next;




  }
}


int main(){

  push(10);
  push(20);
  push(40);
  push(10);

  traverse();

  remove_duplicates();

  traverse();






}
