#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Node;
void insertAtBeg(Node *, int);
void insertAtEnd(Node *, int);
void deleteElem(Node *, int);
void printList(Node);
int countElems(Node);
void slice(Node *, int, int);
void insertAtPos(Node *, int, int);
struct Node
{
    int data;
    Node next;
};
void insertAtBeg(Node *head, int data)
{

    Node temp = (Node)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insertAtEnd(Node *head, int data)
{
    Node temp = (Node)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    Node p;
    //no element in linked list
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void printList(Node head)
{
    Node p;
    printf("List :  ");
    p = head;
    while (p != NULL)
    {
        printf("%d, ", p->data);
        p = p->next;
    }
}
void deleteElem(Node *head, int data)
{
    Node p = *head;
    if (p == NULL)
        printf("OOPs! List empty");
    else if ((*head)->data == data)
    {
        Node temp = (*head);
        *head = temp->next;
        free(temp);
    }
    else
    {
        while (p != NULL && p->next->data != data)
        {
            p = p->next;
        }
        if (p)
        {
            Node temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else
        {
            printf("OOPS !! Element not found !");
        }
    }
}

int main()
{
    Node l1 = NULL;
    int data, pos;
    int a, b, n;
    int choice;
    while (1)
    {
        printf("**********************************************************");
        printf("\n0. Insert N elements\n1. Insert N elements at any position\n2. Slice from a to b\n3. Delete an element\n4. Print list\n5. Count number of elements\n");
        printf("\nEnter your choice - ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 0:
            printf("How many elements do you want to enter - ");
            scanf("%d", &n);
            while (n != 0)
            {
                printf("Enter the data - ");
                scanf("%d", &data);
                insertAtEnd(&l1, data);
                n--;
            }
            printf("\n\n");
            break;
        case 1:
            printf("Enter the data - ");
            scanf("%d", &data);
            printf("Enter the position - ");
            scanf("%d", &pos);
            //insertAtPos(&l1, data, pos);
            printf("\n\n");
            break;

        case 2:
            printf("Enter a - ");
            scanf("%d", &a);
            printf("Enter b - ");
            scanf("%d", &b);
            //slice(&l1, a, b);
            printf("\n\n");
            break;

        case 3:
            printf("Enter the data - ");
            scanf("%d", &data);
            deleteElem(&l1, data);
            printf("\n\n");
            break;
        case 4:
            printList(l1);
            printf("\n\n");
            break;
        case 5:
            //countElems(l1);
            printf("\n\n");
            break;

        default:
            printf("Wrong Choice !!!!\n\n");
            break;
        }
    }
}