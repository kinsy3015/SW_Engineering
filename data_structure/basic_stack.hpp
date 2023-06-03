#include <iostream>

#define MAX 100
using namespace std;



class myStack{

private:
	int stack[MAX];
//	int n = 100;
	int max;
	int *stack_ptr;
	int n;
	int top = -1;

public:

	myStack(int p_max){
		max = p_max;
		//int stack[p_max];
		//stack_ptr = stack;
	}	

	~myStack(){};


	void push(int val);

	void pop();
	
	void display();

};
