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

	printf("//......Array Implementation on linear Queue.......//");
	
	printf("Enter the number of elements on the queue");
	scanf("%d",&n);
	do{
		printf("Choose the Option:");
	
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
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
	if(rear == n-1){
		printf("Queue is full!/Overflow!!");
		
	}else {
		if(front==-1){
			front = 0;
			rear++;
			printf("Enter the vlaue");
			scanf("%d",&value);
			queue[rear]=value;
			printf("Inserted element:%d",queue[i]);
		}
	}
}
