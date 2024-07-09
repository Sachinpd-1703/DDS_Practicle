/*Implement Stack and its operations like (creation push pop traverse peek search)
  using linear data structure*/
#include <stdio.h>
int MAXSIZE = 5;
int stack[5];
int top=-1;
//Check if the stack is full or not
int isfull(){
     if(top==MAXSIZE){
         return 1;
     }else{
         return 0;
     }
 }
//Check if the stack is empty
int isempty(){
     if(top==-1){
         return 1;
     }else{
         return 0;
     }
}
//Function to return the topmost element in the stack
int peek(){
     return stack[top];
}

//Function to insert element into the stack
int push(int data){
     if(!isfull()){
         top = top + 1;
         stack[top] = data;
     }else{
         printf("Stack is Full.\n");
     }
}

// Function to delete element from the stack
int pop(){
     if(!isempty()){
         int data = stack[top];
         top = top - 1;
         return data;
     }else{
         printf("Stack is already empty");
     }
 }
int main() {
    push(44);
    push(10);
    push(62);
    push(13);
    push(15);
    //Displaying stack elements
    printf("\nStack Elements : ");
    for(int i=0;i<MAXSIZE;i++){
        printf("%d ",stack[i]);
    }
    //using pop to delete top element
    printf("\nTop Element is poped : %d",pop());
    //using peek to display top element
    printf("\nElement at the top : %d",peek());
   
    
    //Displaying poped element
    printf("\nElement popped : ");
    while(!isempty()){
        int data= pop();
        printf("%d ",data);
    }

    return 0;
}