#include<stdio.h>
#include<stdbool.h>

bool get_bit(int num,int i){
  return(num & (i<<2) !=0);
}


void main(){

  printf("%d\n",get_bit(5,0) );
}
