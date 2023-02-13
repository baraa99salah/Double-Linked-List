#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

node *addFront(node *head, int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->next = head;
    temp->prev = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        head->prev = temp;
        head = temp;
    }
    temp = NULL;
    free(temp);
    return head;
}
void printList(node *head)
{
    if (head == NULL)
        printf("the list is empty!!\n");
    else
    {
        while (head != NULL)
        {
            printf("%d\t", head->data);
            head = head->next;
        }
    }
}

node* delfirst(node* head)
{
	if (head == NULL) {
		printf("List is Empty");
		return NULL;
	}
	node* temp = head;
	head = head->next;

	if (head != NULL)
		head->prev = NULL;
	free(temp);
	return head;
}
node *deleteNode(node *head, int x)
{
    if (head != NULL)
    {
        node *temp = head;
        if (temp->data == x)
        {
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
        else
        {
            while (temp != NULL && temp->data != x)
                temp = temp->next;
            if (temp == NULL)
                return head;
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp);
        }
    }
    return head;
}
int main()
{
	node* head = NULL;
	head = addFront(head, 3);
	head = addFront(head, 9);
	head = addFront(head, 1);
	head = addFront(head, 10);
	printList(head);
	head = deleteNode(head,3);
	printf("\n");
	printList(head);
	return 0;
}

