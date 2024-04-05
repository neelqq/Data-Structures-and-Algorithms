#include<iostream>
using namespace std;
void display(int arr[],int count){
    for(int i=0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n,ca=0,count=0,data;
    int stack[100];
    cout<<"enter the size of the stack"<<endl;
    cin>>n;

    if(n>0){
    while (ca!=5)
    {
        cout<<"enter 1 for push"<<endl;
        cout<<"enter 2 for pop"<<endl;
        cout<<"enter 3 for display"<<endl;
        cout<<"enter 4 for pick"<<endl;
        cout<<"enter 5 for exit"<<endl;
        cin>>ca;
        switch (ca)
        {
        case 1:
            if(count<n){
                cout<<"enter the data"<<endl;
                cin>>data;
                stack[count]=data;
                count++;
                }
            else{
                cout<<"stack is overflow"<<endl;
                }
            display(stack,count);
            break;
        case 2:
            if(count<=0){
                cout<<"stack is empty"<<endl;
                }
            else{
                cout<<stack[count-1]<<" is pop"<<endl;
                count--;
            }
            display(stack,count);
            break;
        case 3:
            if(count<=0){cout<<"stack is empty"<<endl;}
            else{
            display(stack,count);
            }
            break;
        case 4:
            if(count>=n){
                cout<<"Stack is overflow"<<endl;
            }
            else if(count<0)
            {
                cout<<"Stack is empty"<<endl;
            }
            else{
                cout<<stack[count]<<endl;
            }
            break;
        default:
            cout<<"error"<<endl;
            break;
        }
    }
    }
    else{
        cout<<"error"<<endl;
    }

    
}