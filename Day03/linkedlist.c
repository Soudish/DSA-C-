#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node{
    int val;
    struct Node *next;
};
struct Node *insertatfront(struct Node *head,int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=value;
    newNode->next=head;
    return newNode;
}
struct Node *insertatany(struct Node *head,int value,int pos){
    if(pos<0){
        printf("Invalid position");
        return head;
    }
    if(pos==0){
        return insertatfront(head,value);
    }
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node *ptr=head;
    if(ptr==NULL){
        printf("position is out of range");
        return head;
    }
    for(int i=0;i<(pos-1);i++){
        if(ptr->next==NULL){
            printf("position is out of range");
            return head;
        }
        ptr=ptr->next;
    }
    newNode->val=value;
    newNode->next=ptr->next;
    ptr->next=newNode;
    return head;
}
struct Node *insertatrear(struct Node *head,int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=value;
    newNode->next=NULL;
    if(head==NULL){
        return newNode;
    }
    struct Node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newNode;
    return head;
}
struct Node *deleteatfront(struct Node *head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    struct Node *ptr=head->next;
    free(head);
    return ptr;
}
struct Node *deleteatany(struct Node *head,int pos){
    if(head==NULL){
        return NULL;
    }
    if(pos == 0){
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node *ptr=head;
    struct Node *temp=NULL;
    for(int i=0;i<pos-1;i++){
        if(ptr->next==NULL){
            printf("Position out of range");
            return head;
        }
        ptr=ptr->next;
    }
    if(ptr->next == NULL){
        printf("Position out of range\n");
        return head;
    }
    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
    return head;
}
struct Node *deleteatrear(struct Node *head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    struct Node *ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    free(ptr->next);
    ptr->next=NULL;
    return head;
}
void display(struct Node *head){
    struct Node *ptr=head;
    while(ptr!=NULL){
        printf("%d->",ptr->val);
        ptr=ptr->next;
    }
    printf("NULL\n");
    return;
}
int main(){
    struct Node *head = NULL;
    int choice, value, pos;

    while(1){
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Any Position\n");
        printf("3. Insert at Rear\n");
        printf("4. Delete at Front\n");
        printf("5. Delete at Any Position\n");
        printf("6. Delete at Rear\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertatfront(head, value);
                break;

            case 2:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                head = insertatany(head, value, pos);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertatrear(head, value);
                break;

            case 4:
                head = deleteatfront(head);
                break;

            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deleteatany(head, pos);
                break;

            case 6:
                head = deleteatrear(head);
                break;

            case 7:
                display(head);
                break;

            case 8:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

