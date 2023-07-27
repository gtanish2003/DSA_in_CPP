#include<iostream>
using namespace std;
class twostack{

    public:
    int *arr;
    int top1;
    int top2;
    int size;


    twostack(int size){
        this->size=size;
        top1=-1;
        top2=size;
        arr=new int [size];
    }


    void push1(int element){

        //atlest one empty space is present
        if (top2-top1>1){
            top1++;
            arr[top1]=element;

        }
        else{
            cout<<"Stack overflow"<<endl;

        }
    }

    void push2(int element){
        if (top2-top1>1){
            top2--;
            arr[top2]=element;
            }
    else{
            cout<<"Stack overflow"<<endl;

        }


}

void pop1(){
    if (top1>0){
        top1--;
    }
    else{
        cout<<"Stack underflow"<<endl;
    }
}

void pop2(){
    if (top2<size){
        top2++;
    }
    else{
        cout<<"Stack underflow"<<endl;
    }

}



};

int main(){
    twostack st(5);
    st.push1(2);
    st.push2(10);
   
   st.pop1();
   st.pop2();
}