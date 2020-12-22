#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int index = 0;

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

void pushTail(int num) {
	struct Data* newNode = createNode(num);
	
	if(!head)
		head = tail = newNode;
	else {
		tail->next = newNode;
		tail = newNode;
	}
	index++;
}

void printMid() {
	int mid = ceil(index/2);
	struct Data *curr = head;
	while(mid--)
		curr = curr->next;
	printf("%d\n", curr->num);
}

void print() {
	struct Data *curr = head;
	while(curr) {
		printf("%d ", curr->num);
		curr = curr->next;
	}
	puts("");
}

int main() {
	pushTail(10);
	pushTail(20);
	pushTail(30);
	pushTail(40);
	pushTail(50);
	print();
	printMid();
	
	return 0;
}
