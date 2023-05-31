#include<iostream>
using namespace std;

int binarysearch(int arr[5][5],int target){
    int row=3;
    int col=4;
    int rowIndex=0;
    int colIndex=col-1;

    
    while(rowIndex <row && colIndex>=0){
        int element=arr[rowIndex][colIndex];
        if (element==target){
            return 1;

        }
        else if (element<target){
            rowIndex++;
        }
        else{
            colIndex--;
        }
   
    }
  return 0;
}
int main(){
    int arr[5][5]={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{25,26,27,28,29}};
    cout<<binarysearch(arr,6);
    
}