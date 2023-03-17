#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
typedef struct node
{
	int data;
	struct node* next;
}node;
void createhead(node* head, int size)
{
	node* rear = head;
	int i;
	for (i = 0; i < size; i++)
	{
		node* newnode = (node*)malloc(sizeof(node));
		newnode->next = NULL;
		scanf_s("%d", &newnode->data);
		rear->next = newnode;
		rear = newnode;
	}
}
void getdata(node* head)
{
	node* p = head->next;
	while (p != NULL)
	{
		printf("%d	", p->data);
		p = p->next;
	}
}
int insertdata(node* head, int i, int a)
{
	node* p = head;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = a;
	newnode->next = p->next;
	p->next = newnode;
	return OK;
}
void deletedata(node* head, int i, int* e)//删除第i位的结点，并将data赋给*e
{
	int j = 1;
	node* p = head;
	while (p->next && j < i)//找到第i位的结点
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		printf("error\n");
	}
	node* q = p->next;               //删除流程
	p->next = q->next;
	*e = q->data;
	free(q);
}
void headinsert(node* head, int i)
{
	node* p = head;
	int j;
	for (j = 1; j < i; j++)
	{
		node* newnode = (node*)malloc(sizeof(node));
		scanf_s("&d", &newnode->data);
		newnode->next = p->next;
		head->next = newnode;
	}
}
void putdata(node* head, int i)
{
	node* p = head->next;
	int j;
	for (j = 1; j < i; j++)
	{
		scanf_s("%d", &p->data);
		p = p->next;
	}
}
void endinsert(node* head, int i)
{
	node* p = head;
	int j;
	while (p->next)
	{
		p = p->next;
	}
	for (j = 1; j < i; j++)
	{
		node* newnode = (node*)malloc(sizeof(node));
		scanf_s("%d", &newnode->data);
		newnode->next = NULL;
		p->next = newnode;
		p = newnode;
	}
}
void overturn(node* head)
{

}
int main()
{
	int m = 9;
	int* p = &m;
	node* head = (node*)malloc(sizeof(node));
	createhead(head, 10);
	getdata(head);
	printf("\n");
	insertdata(head, 5, 8);
	getdata(head);
	printf("\n");
	deletedata(head, 5, p);
	getdata(head);
	printf("\n");
	headinsert(head, 3);//scanf函数没有运作，为什么？结点插入的没有问题。
	putdata(head, 3);
	getdata(head);
	printf("\n");
	endinsert(head, 3);
	getdata(head);
	return 0;
}