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

void pushTail(int num) {
	struct Data* newNode = createNode(num);
	
	if(!head)
		head = tail = newNode;
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

int findCycle() {
	struct Data *first = head, *last = head;
	while(first && last && last->next) {
		first = first->next;
		last = last->next->next;
		
		if(first == last)
			return 1;
	}
	
	return 0;
}

int main() {
	pushTail(10);
    pushTail(20);
    pushTail(30);
    pushTail(40);
    pushTail(50);
    head->next->next->next->next->next=head;
    findCycle();

    if(findCycle())
        puts("Cycle found");
    else
        puts("Cycle not found");
    return 0;
}
