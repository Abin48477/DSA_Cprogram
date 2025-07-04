#include <stdio.h>
#define SIZE 20

struct queue {
    int item[SIZE];
    int front;
    int rear;
};

typedef struct queue qu;

// Function to insert an element into the queue
void insert(qu *q) {
    int val;
    if (q->rear == SIZE - 1) {
        printf("Queue is full (Overflow)\n");
    } else {
        printf("Enter value to insert: ");
        scanf("%d", &val);
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->item[q->rear] = val;
        printf("Inserted %d\n", val);
    }
}

// Function to delete an element from the queue
void deleteItem(qu *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty (Underflow)\n");
    } else {
        printf("Deleted %d\n", q->item[q->front]);
        if (q->front == q->rear) {
            // Queue becomes empty after deletion
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }
}

// Function to display the queue elements
void display(qu *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->item[i]);
        }
        printf("\n");
    }
}

// Main function with menu
int main() {
    int ch;
    qu q;
    q.front = -1;
    q.rear = -1;

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert(&q);
                break;
            case 2:
                deleteItem(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (ch != 4);

    return 0;
}
