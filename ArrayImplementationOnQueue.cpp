#include<stdio.h>
#define SIZE 5

int queue[SIZE];
	int front = -1;
	int rear = -1;
	int n,choice,i;
void enqueue();
void dequeue();
void display();

int main(){

	printf("\n//......Array Implementation on linear Queue.......//\n");
	
	printf("Enter the number of elements on the Queue:\n");
	scanf("%d",&n);
	do{
		printf("Choose the Option:\n");
	
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
			 enqueue();
				break;
				case 2:
					dequeue();
					break;
					case 3:
						display();
						break;
						case 4:
							printf("Exit!!\n");
							break;
							default:
								printf("Enter the valid number from the given options\n");
		}
		
	}while(choice!=4);
}
void enqueue(){
	int value;
	if(rear == queue[SIZE]-1){
		printf("Queue is full!/Overflow!!");
		
	}else {
		if(front==-1){
			front = 0;
					}
			rear++;
			printf("Enter the vlaue:");
			scanf("%d",&value);
			queue[rear]=value;
			printf("Inserted element:%d\n",value);
		
	}
}
void dequeue(){
	if(front == -1||front>rear){
		printf("Queue is empty!\n");
		
	}else{
		printf("Deleted element %d\n",queue[front]);
		front++;
	}
}
void display(){
	if(front == -1||front> rear){
		printf("Queue is empty!\n");
		
	}else
	for(i = front;i<= rear;i++){
		printf("Displayed element:%d\n",queue[i]);
	}
}
