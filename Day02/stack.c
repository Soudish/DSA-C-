#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int isEmpty(struct node* top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct node* top){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct node* push(struct node* top,int data){
    if(isFull(top)){
        printf("Stack Overflow");
    }
    else{
        struct node *p=(struct node*)malloc(sizeof(struct node));
        p->data=data;
        p->next=top;
        top=p;
        return top;
    }
    
}
struct node* pop(struct node* top){
    if(isEmpty(top)){
        printf("Stack is Empty");
    }
    else{
        struct node *p=top;
        top=top->next;
        
        free(p);
        return top;
    }
}

void travarsal(struct node *ptr){
    while(ptr!=NULL){
        printf("Elemnet:%d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct node *top=NULL;
    int value,choice;
     while(1){
        printf("-----Menu-----\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                 printf("Enter the value you want to push:");
                 scanf("%d",&value);
                 top=push(top,value);
                 break;
            case 2:
                 top=pop(top);
                 break;
            case 3:
                 travarsal(top);
                 break;
            
            case 4:
                 printf("Exit");
                 
                 return 0;
                 break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}