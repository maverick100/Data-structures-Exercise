#include<bits/stdc++.h>
using namespace std;


struct Queue{
  stack<int> s1,s2;

  void enqueue(int x){

    while(!s1.empty()){
      s2.push(s1.top());
      s1.pop();
    }

    s1.push(x);
    while (!s2.empty()) {
      /* code */
      s1.push(s2.top());
      s2.pop();
    }
  }

  void dequeue(){
    printf("poped element :%d\n",s1.top());
    s1.pop();

  }

  void printqueue(){

      printf("top of queue :%d\n",s1.top() );

  }


};
struct Queue q;


int main(){


  q.enqueue(1);
  q.enqueue(2);
  q.printqueue();
  q.dequeue();
  q.printqueue();

}
