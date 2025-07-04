//Array implemantation of stack

#include<stdio.h>

int stack[100],i,n,choice=0,top=-1;
void push();
void pop();
void display();

int main(){
	
	printf("Enter the number of elements in the stack:");//10
	scanf("%d",&n);
	printf("\n//-----------------------//\n");

	while(choice!=4){
	printf("Enter your choice\n");
	printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit\n");
	scanf("%d",&choice);
	
		switch(choice){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Existing....!!");
				break;
			default :
			printf("Enter the valid choice!!");	
		}
	}
	return 0;
}
void push(){
int value;
	if(top == n-1){//because arry start from 0
		printf("\nOverflow!!");
	}
	else{
		printf("Enter the value:");
		scanf("%d",&value);
		top = top+1;
		stack[top] = value;
	}
}
void pop(){
	if(top==-1){
		printf("Underflow!!!");
	}else{
		printf("Deleted Element:%d\n",stack[i]);
		top = top-1;
	}
}
void display(){
	
	if(top==-1){
		printf("Stack is Empty!!");
		
	}
		for(i = top; i>=0;i++){
			printf("Stack Values:%d",stack[i]);
		}
	}

