#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct {
	struct node *next;
	int data;
} node;

node **hashTable;
int hashTableSize;

int hash1(int data) {
	return (data % hashTableSize);
}
node *insertnode(int data) {

	node *p;
	;
	int bucket;
	bucket = hash1(data);
	p = (node*)malloc(sizeof(node));

	node *p0 = hashTable[bucket];
	hashTable[bucket] = p;
	p->next = p0;

	p->data = data;
	return p;
}
void deletenode(int data) {
	node *p0;
	node *p;
	int bucket;
	p0 = 0;
	bucket = hash1(data);
	p = hashTable[bucket];
	while (p && (p->data != data)) {
		p0 = p;
		p = p->next;
	}
	if (!p) return;
	if (p0) p0->next = p->next;
	else hashTable[bucket] = p->next;
	free(p);
}
node *findnode(int data) {
	node *p;
	p = hashTable[hash1(data)];
	while (p && (p->data != data)) p = p->next;
	return p;
}
int main() {
	hashTableSize = 20001;
	hashTable = (node**)malloc(hashTableSize * sizeof(node*));

	system("pause");
	return 0;
}

