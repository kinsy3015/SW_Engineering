#include "basic_stack.hpp"



void myStack::push(int val){
	if(top>=n-1)
		cout<<"Stack Overflow"<<endl;
	else{
		top++;
		stack[top]=val;
	}
}



void myStack::pop(){
	if(top<=-1){
		cout<<"Stack Underflow"<<endl;
	}
	else{
		cout<<"The popped element is "<< stack[top] <<endl;
		top--;
	}
}


void myStack::display(){
	if(top>=0){
		cout<<"Stack element are:";
		for(int i=top; i>=0; i--){
			cout<<stack[i]<<" ";
			cout<<endl;
		}
	} else
		cout<<"Stack is empty";
}
