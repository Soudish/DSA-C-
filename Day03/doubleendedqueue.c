#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct queue {
    int *arr;
    int rear;
    int front;
    int size;
};
int isFull(struct queue *q){
    if((q->rear==q->size-1 && q->front==0)||q->front==q->rear+1){
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q){
    if(front==-1){
        return 1;
    }
    return 0;
}
void insertatfront(struct queue *q,int value){
    if(isFull(q)){
        printf("Overflow");
        return;
    }
    if(q->front==-1){
        q->front=0;
        q->rear=0;
    }
    else if(q->front==0){
        q->front=q->size-1;
    }
    else{
        q->front-=1;
    }
    q->arr[q->fornt]=value;
    printf("%d is inserted at front",value);
    return;
}
void insertatlast(struct queue *q,int value){
    if(isFull){
        printf("Overflow");
        return;
    }
    if(q->front==-1){
        q->front=0;
        q->rear=0;
    }
    else{
        q->rear=(q->rear+1)%q->size;
    }
    q->arr[q->rear]=value;
    printf("%d is inserted at rear",value);
    return;
}
void deletefront(struct queue *q){
    if(isEmpty(q)){
        printf("Empty");
        return;
    }
    printf("%d is deleted from front",q->arr[q->front]);
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
    }
    else{
        q->front=(q->front+1)%q->size;
    }
    return;
}
void deleterear(struct queue *q){
    if(isEmpty(q)){
        printf("Empty");
        return;
    }
    printf("%d is deleted from front",q->arr[q->front]);
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
    }
    else if(q->rear ==0){
        q->rear=q->size-1;
    }
    else{
        q->rear-=1;
    }
    return;
}
void display(struct queue *q){
    if(isEmpty(q)){
        printf("EMPTY");
        return;
    }
    int i=q->front;
    while(i!=q->rear){
        printf("%d ",q->arr[i]);
    }
    printf("%d",q->arr[q->rear]);
    return;
}
int main(){
    struct queue q;
    int n;
    printf("Enter the size of dequeue:");
    scanf("%d",&n);
    q->size=n;
    q->front=-1;
    q->rear=-1;
    q->arr=(int*)malloc(n*sizeof(int));
    int choice,value;
    while(1){
        printf("----MENU----\n");
        printf("1.Insert at front\n");
        printf("2.Insert at rear\n");
        printf("3.Delete from front\n");
        printf("4.Delete from rear\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter the choice:");
        printf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value:");
                scanf("%d",&value);
                insertatfront(&q,value);
                break;
            case 2:
                printf("Enter the value:");
                scanf("%d",&value);
                insertatlast(&q,value);
                break;
            case 3:
                deletefront(&q);
                break;
            case 4:
                deleterear(&q);
                break;
            case 5:
                display(&q);
                break;
            case 6:
                printf("Exit");
                return;
        }
    }
    return 0;
}