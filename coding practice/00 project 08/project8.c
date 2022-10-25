/***********************************************************
    Computing II -- COMP.1020 Honor Statement
    The practice of good ethical behavior is essential for maintaining good
   order in the classroom, providing an enriching learning experience for
   students, and as training as a practicing computing professional upon
   graduation.    This practice is manifested in the University's Academic
   Integrity policy.  Students are expected to strictly avoid academic
   dishonesty and adhere to the Academic Integrity policy as outlined in
   the course catalog.  Violations will be dealt with as outlined therein.
    All programming assignments in this class are to be done by the student
   alone.  No outside help is permitted except the instructor and approved
   tutors.
    I certify that the work submitted with this assignment is mine and was
   generated in a manner consistent with this document, the course academic
    policy on the course website on Blackboard, and the UMass Lowell
   academic code.
    Author: Khiel Mantilla
    Date: October 11 2022
    Effort: 50 minutes
    Purpose: setting up an algorithm to reverse a linked list.
***********************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

//declare your function here.
Node* reverse(Node* n);

int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	//call your function to reverse the list (should work for any list given the head node pointer).
	head = reverse(head);

	//print the reversed list.
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	
	// Clean up the list
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}

	return 0;
}

//Define your function here
Node* reverse(Node* n) {
	Node* prev;
	Node* node = n;
	Node* next = node->next;
	do {
		prev = node;
		node = next;
		if (node == NULL) break;
		next = node->next;
		if (node->next == NULL) {
			next = NULL;
		}

		node->next = prev;

		// check beginning
		if (prev->next == node) {
			prev->next = NULL;
		}

	} while (node != NULL);

	return prev;
}