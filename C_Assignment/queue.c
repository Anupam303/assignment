#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define length 256

typedef struct node{
	char input[length];
	struct node *next;
}nt;

void push(nt * head, char * c){
	nt * current = head;
	while(current -> next != NULL){
		current = current -> next;
	}
	current -> next = (nt*) calloc(1, sizeof(nt));
	current = current -> next;
	strcpy(current -> input, c);
	current -> next = NULL;
}

int pop (nt ** head){
	nt * new = NULL;
	if(*head == NULL){
		return -1;
	}
	new = (*head) -> next;
	free(*head);
	*head = new;
	return 0;
}

void remove_last(nt * head){
	if(head -> next == NULL){
		free(head);
	}

	nt * current = head;
	while(current -> next -> next != NULL){
		current = current -> next;
	}
	free(current -> next);
	current -> next = NULL;
}

void remove_all(nt ** head){
	nt * prev = *head;
	int i = 0;
	while(*head){
		*head = (*head) -> next;
		free(prev);
		prev = *head;
		i++;
	}
}

void lastnumlines(FILE * inputfp, unsigned int num)
{
	//char ** tailbuf = calloc(num, sizeof(char *));
	//tailbuf = ll(FILE * inputfp, unsigned int num);
	//return tailbuf;
	nt * head = calloc(1, sizeof(nt));
	if(head == NULL){
		printf("Add Value to Work\n");
	}
	int size = 0;
	while(!feof(inputfp)){
		char ch[length];
		fgets(ch, length, inputfp);
		push(head, ch);

		if(size >= num){
			pop(&head);
		}
		size++;
	}

	remove_last(head);
	size--;
	if(num >= (size + 1)){
		remove_all(&head);
		printf("Input Value greater than the size\n");
		fclose(inputfp);
		exit(0);
	}
	nt * p = head;
	for(int i = 0; i < num; i++)
	{
		head = head -> next;
		printf("%s", p -> input);
		free(p);
		p = head;
	}
}

int main()
{
	FILE * fp = fopen("input.txt", "r");
	int n;
	scanf("%d", &n);
	if(n > 100 || n <= 0){
		printf("Input Value out of range\n");
		fclose(fp);
		return 0;
	}
	// Assume fp is not NULL
	//char ** lastlines = lastnumlines(fp, n);
	if(fp == NULL){
		printf("File is Empty\n");
		fclose(fp);
		return 0;
	}
	else{
		lastnumlines(fp, n);
	}
	fclose(fp);
}
