#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct queue{
    int *arr;
    int front;
    int rear;
    int size;
};
int isFull(struct queue *q){
    if(q->front==q->rear+1||(q->front=0 && q->rear=n-1)){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q,int value){
    if(isFull(q)){
        printf("Overflow");
        return;
    }
    if(q->front==-1){
        q->front=0;
        q->rear=0;
    }
    else{
        q->rear=(q->rear+1)%(q->size);
    }
    q->arr[q->rear]=value;
    printf("%d is inserted",value);
    return;
}
void dequeue(struct queue *q){
    if(q->front==-1){
        printf("Empty");
        return;
    }
    printf("%d is deleted",q->arr[q->front]);
    if(q->rear==q->front){
        q->rear=-1;
        q->front=-1;
    }
    else{
        q->front=(q->front+1)%q->size;
    }
    return;
}
void display(struct queue *q){
    if(q->front==-1){
        printf("Empty");
        return;
    }
    int i=q->front;
    while(i!=q->rear){
        printf("%d ",q->arr[i]);
        i=(i+1)%q->size;
    }
    printf("%d",q->arr[q->rear]);
    return;
}
int main(){
    struct queue q;
    int n;
    printf("Enter the size of queue:");
    scanf("%d",&n);
    q.size=n;
    q.front=-1;
    q.rear=-1;
    q.arr=(int*)malloc(n*sizeof(int));
    int choice,value;
    while(1){
        printf("----MENU----\n");
        printf("1.Enqueue");
        printf("2.Dequeue");
        printf("3.Display");
        printf("4.Exit");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter value to enter:");
                scanf("%d",&value);
                enqueue(&q,value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exit");
                return 0;
            default:
                printf("Invalid Choice");
                break;
        }
    }
    return 0;
}