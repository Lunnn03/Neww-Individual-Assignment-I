#include <stdio.h>
#include <stdlib.h>

struct Data {
	int num;
	Data *next;
}*head = NULL, *tail = NULL;

struct Data* createNode(int num) {
	struct Data* newNode = (Data*)malloc(sizeof(Data));
	
	newNode->num = num;
	newNode->next = NULL;
	
	return newNode;
};

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

void popHead() {
	if(!head)
		return;
	else {
		struct Data* curr = head;
		head = head->next;
		free(curr);
		curr = NULL;
	}
}

void popTail() {
	if(!head)
		return;
	else if(head == tail) {
		free(head);
		head = tail = NULL;
	}
	else {
		struct Data *curr = head;
		while(curr) {
			if(curr->next = tail)
				break;
			curr = curr->next;
		}
		free(tail);
		tail = curr;
		tail->next = NULL;
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

void sort(int num) {
	struct Data *newNode = createNode(num);
	if(!head)
		head = tail = newNode;
	else if(newNode->num > head->num)
		pushHead(num);
	else if(newNode->num < tail->num)
		pushTail(num);
	else {
		struct Data *curr = head;
		while(curr) {
			if(newNode->num > curr->next->num)
				break;
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}
}

void popMid(int num) {
	if(num == head->num) {
		popHead();
		sort(num);
	}
	else if(num == head->num) {
		popTail();
		sort(num);
	}
	else {
		struct Data *curr = head;
		while(curr) {
			if(curr->next->num == num)
				break;
			curr = curr->next;
		}
		if(!curr->next)
			return;
		
		struct Data *newNode = curr->next;
		curr->next = newNode->next;
		free(newNode);
		newNode = NULL;
		sort(num);
	}
}

int main() {
	for(int i = 10; i <= 50; i+=10)
		pushTail(i);
	for(int i = 10; i <= 50; i+=10)
		popMid(i);
	printList();
	
}

