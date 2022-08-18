#include<iostream>
#include<vector>
#include "segmentTree.h"
using namespace std ;


int main(){
  int size, ch, n=4, qs, qe ;
  int data[] = {10,20,30,40} ;
  int tree[16] ;
  segmentTree<int> obj ;
  cout<<"\n~~~~~ CHOICES ~~~~~" ;
  cout<<"\n1. Construct and display segment tree" ;
  cout<<"\n2. Range query on segment tree" ;
  cout<<"\n3. Update query on segment tree" ;
  while(ch < 4){
    cout<<"\nEnter number of choice : " ;
    cin>>ch ;
    switch(ch){
      case 1:
      obj.buildTree(0,n-1,0,data,tree);
      for(int i=0; i<16; i++){
        cout<<tree[i]<<" " ;
      }
      break ;

      case 2:
      cout<<"\nEnter the range you want to set the query : " ;
      cin>>qs>>qe ;
      cout<<obj.getSum(qs,qe,0,n-1,0,tree);
      break ;

      case 3:
      int i , new_val;
      cout<<"\nEnter the index to which you want to update" ;
      cin>>i ;
      cout<<"\nEnter the new value : " ;
      cin>>new_val ;
      int diff = new_val - data[i] ;
      obj.update(0,n-1,i,0,diff,tree);
      for(int i=0; i<4*n; i++){
        cout<<tree[i]<<" " ;
      }
      break ;

    }
  }
  return 0 ;
}

