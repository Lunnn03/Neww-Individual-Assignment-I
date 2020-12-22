#include <stdio.h>
#include <stdlib.h>

struct Data {
	int num;
	Data *next;
}*head = NULL, *tail = NULL;

struct DataNew {
	int num;
	DataNew *next;
}*headS = NULL, *tailS = NULL;

struct Data* createNode(int num) {
	struct Data* newNode = (Data*)malloc(sizeof(Data));
	
	newNode->num = num;
	newNode->next = NULL;
	
	return newNode;
};

struct DataNew* createNodes(int num) {
	struct DataNew* newNode = (DataNew*)malloc(sizeof(Data));
	
	newNode->num = num;
	newNode->next = NULL;
	
	return newNode;
};

void pushTailNew(int num) {
	struct DataNew *newNode = createNodes(num);
	if(!headS)
		headS = tailS = newNode;
	else {
		tailS->next = newNode;
		tailS = newNode;
	}
}

void pushHead(int num) {
	struct Data* newNode = createNode(num);
	if(!head)
		head = tail = newNode;
	else {
		newNode->next = head;
		head = newNode;
	}
}

void pushTail(int num) {
	struct Data* newNode = createNode(num);
	
	if(!head)
		head = tail = newNode;
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

void printList() {
	struct Data* curr = head;
	while(curr) {
		printf("%d ", curr->num);
		curr = curr->next;
	}
	puts("");
}

void printLists() {
	struct DataNew *curr = headS;
	while(curr) {
		printf("%d ", curr->num);
		curr = curr->next;
	}
	puts("");
}

void pushMid(int num) {
	struct Data *newNode = createNode(num);
	if(!head)
		head = tail = newNode;
	else if(newNode->num < head->num)
		pushHead(num);
	else if(newNode->num > tail->num)
		pushTail(num);
	else {
		struct Data *curr = head;
		while(curr) {
			if(newNode->num < curr->next->num)
				break;
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}
}

void popHead() {
	if(!headS)
		return;
	else {
		struct DataNew* curr = headS;
		headS = headS->next;
		free(curr);
		curr = NULL;
	}
}

void merge() {
	struct DataNew *curr = headS;
	while(curr) {
		pushMid(curr->num);
		curr = curr->next;
		popHead();
	}
}

int main() {
	pushTailNew(10);
    pushTailNew(20);
    pushTailNew(30);
    printLists();
    pushTail(40);
    pushTail(50);
    pushTail(60);
    printList();
    merge();
    printList();
    
    return 0;
}
