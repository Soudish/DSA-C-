#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node{
    int val;
    struct Node *next;
};
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
struct Node *reverse(struct Node *head){
    struct Node *prev=NULL;
    struct Node *curr=head;
    struct Node *next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void sort(struct Node *head){
    int swapped;
    struct Node *ptr;
    struct Node *last=NULL;
    if(head==NULL) return;
    do{
        swapped=0;
        ptr=head;
        while(ptr->next!=last){
            if(ptr->val>ptr->next->val){
                int temp=ptr->next->val;
                ptr->next->val=ptr->val;
                ptr->val=temp;
                swapped=1;
            }
            ptr=ptr->next;
        }
        last=ptr;
    }while(swapped);
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
    int choice, value;

    while(1){
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Insert at Rear\n");
        printf("2. Sort List\n");
        printf("3. Reverse List\n");
        printf("4. Display List\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertatrear(head, value);
                break;

            case 2:
                sort(head);
                printf("List sorted\n");
                break;

            case 3:
                head = reverse(head);
                printf("List reversed\n");
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
