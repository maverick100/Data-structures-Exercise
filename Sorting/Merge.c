#include<stdio.h>
#include<stdlib.h>



int merge(int arr[],int l,int m,int r){

  int n1=m-l+1;
  int n2=r-m;
  int L[n1],R[n2];
  int k,i,j;

  for(i=0;i<n1;i++)
    L[i]=arr[l+i];


  for( j=0;j<n2;j++)
    R[j]=arr[m+1+j];


    i=0;j=0;k=l;

  while( i<n1 && j<n2 ){

    if(L[i]<R[j]){
      arr[k]=L[i];
      i++;
    }
    else{
      arr[k]=R[j];
      j++;
    }
    k++;
  }

  while(i<n1){
    arr[k]=L[i];
    i++;k++;
  }
  while(j<n2){
    arr[k]=R[j];
    k++;j++;
  }




}

void merge_sort(int arr[],int l,int r){
  int m;


  if(l<r){
    m=(r-l)/2;

    merge_sort(arr,l,m);
    merge_sort(arr,m+1,r);

    merge(arr,l,m,r);
  }



}

void main(){
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n=sizeof(arr)/sizeof(arr[0]);
  merge_sort(arr,0,n-1);
  for(int i=0;i<n-1;i++)
    printf("%d\n",arr[i] );

}
