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

void printFromLast(int num) {
	int count = 0, index = 0;
	struct Data *curr = head;
	while(curr) {
		curr = curr->next;
		count++;
	}
	
	if(num > count)
		return;
	
	curr = head;
	
	for(int i = 1; i < count - num + 1; i++)
		curr = curr->next;
	
	printf("%d", curr->num);
}

void printAll() {
	struct Data *curr = head;
	while(curr) {
		printf("%d ", curr->num);
		curr = curr->next;
	}
	puts("");
}

void pushHead(int num) {
	struct Data* newNode = createNode(num);
	if(!head)
		head = tail = newNode;
	else {
		struct Data *curr = head;
		while(curr->next)
			curr = curr->next;
		curr->next = newNode;
	}
}

void disposeMemory(){
	Data *newNode;
	while(head){
		newNode = head;
		head = head->next;
		free(newNode);
	}
}

int main(){
	pushHead(10);
	pushHead(20);
	pushHead(30);
	printAll();
	printFromLast(1);
	disposeMemory();
	return 0;
}
