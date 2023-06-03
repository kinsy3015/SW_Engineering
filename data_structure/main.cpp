#include "basic_stack.hpp"


int main(int argc, char** argv){
	int ch,val;
	myStack stack1(101);
	cout<<"1) Push in stack"<<endl;
	cout<<"2) Pop from stack"<<endl;
	cout<<"3) Display stack"<<endl;
	cout<<"4) Exit"<<endl;
	do{
		cout<<"Enter choice: "<<endl;
		cin>>ch;
		switch(ch){
			case 1:{	
				cout<<"Enter value to be pushed:"<<endl;
				cin>>val;
				stack1.push(val);
				break;
			}
			case 2: {
				stack1.pop();
				break;
			}
			case 3:	{
				stack1.display();
				break;
			}
			case 4: {
				cout<<"Exit"<<endl;
				break;
			}
			default:{
				cout<<"Invalid Choice"<<endl;

			}
		}
	}while(ch!=4);
	return 0;
}
