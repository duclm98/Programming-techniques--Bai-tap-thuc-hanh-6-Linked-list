#pragma once
#include <iostream>
using namespace std;

struct node
{
	void* data;
	node* next;
};
typedef struct node NODE;

struct list
{
	NODE* head;
	NODE* tail;
};
typedef struct list LINKEDLIST;

NODE* CreateNode(void* data) {
	NODE* node = new NODE;
	node->data = data;
	node->next = NULL;
	return node;
}
void CreateList(LINKEDLIST& l) {
	l.head = NULL;
	l.tail = NULL;
}
void AddTail(LINKEDLIST& l, NODE* node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	}
	else {
		l.tail->next = node;
		l.tail = node;
	}
}

void PrintList(LINKEDLIST l) {
	if (l.head != NULL) {
		NODE* node = l.head;
		while (node != NULL) {
			cout << node->data << endl;
			node = node->next;
		}
	}
}