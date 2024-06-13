/*
Nick Newman
6/6/24
5295926
Computer Science 1 - Programming assignment 2
Dr. Tanvir Ahmed Summer 2024
latest save on github is 08865624d4ced78dd60375b20310e7cb47a492ee
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE  12
#define EMPTY -1

/*------------STRUCTURE DEFINES--------------*/
typedef struct queue {
	struct node* p_front;
	struct node* p_back;
}queue;

typedef struct customers {
	char* p_name;
	int numOfSmootihes;
	int lineNumber;
	int enterLineTime;
}customers;

typedef struct node {
	customers* p_customer;
	struct node* p_next;
}node;

/*------------FUNCTION SIGNATURES------------*/
void init(queue* qPtr);
int enqueue(queue* qPtr, customers* cPtr);
int dequeue(queue* qPtr);
int empty(queue* qPtr);
int peak(queue* qPtr);
int front(queue* qPtr);
void displayQueue(queue* myQ);
customers* createCustomers(customers*);

/*------------QUEUE FUNCTIONS----------------*/
void init(queue* qPtr) {
	qPtr->p_front = NULL;
	qPtr->p_back = NULL;
}

int enqueue(queue* qPtr, customers* cPtr) {

	struct node* p_temp = malloc(sizeof(struct node));

	if (p_temp == NULL) {
		return 0;
	}

		//init(qPtr);

	p_temp->p_customer = cPtr; // data became p_customer // second note... p_customer needs to equal what? I think when i enqueue I need to store customer[i] data? I have put line number to satisfy equaling x.// I have updated this to p_temp->p_customer = cPtr; I believe this is putting customer[i] data into p_customer in p_temp wich is a node. 
	p_temp->p_next = NULL;

	if (qPtr->p_back == NULL) { // I need to do something about qPtr->p_back for a 2nd or more entry
		qPtr->p_front = p_temp;
		qPtr->p_back = p_temp;

		return 1;
	}

	qPtr->p_back->p_next = p_temp;
	qPtr->p_back = p_temp;

	return 1;

}

int dequeue(queue* qPtr) {

	if (empty(qPtr)) {
		return EMPTY;
	}

	struct node* p_temp = qPtr->p_front;
	qPtr->p_front = qPtr->p_front->p_next;
	int retval = p_temp->p_customer->lineNumber; // data became p_customer->lineNumber to satify the retVal
	free(p_temp);

	/*This is written because of the above 5 lines*/
	if (empty(qPtr))
		qPtr->p_back = NULL;
	return retval;
}

int empty(queue* qPtr) {
	if (!qPtr) {
		return EMPTY;
	}
}

int peek(queue* qPtr) {
	if (!qPtr) {
		return EMPTY;
	}
	return qPtr->p_front->p_customer->lineNumber;
}

void displayQueue(queue* myQ) {
	struct node *t = myQ->p_front;
	while (t)
	{
		printf("%s ", t->p_customer->p_name);
		t = t->p_next;
	}
}


/*------------CUSTOMER FUCTIONS---------------*/
node* createCustomerNode(node* p_front) {

	node* p_newNode = (node*)malloc(sizeof(node));
	p_newNode->p_next = NULL;

	return p_newNode;
}

customers* createCustomers(customers* p_customer) {

	int m;
	scanf("%d", &m);

	p_customer = (customers*)malloc(sizeof(customers)*m);

	for (int j = 0; j < m; j++) {
		scanf("%d", &p_customer[j].enterLineTime);
		scanf("%d", &p_customer[j].lineNumber);
		p_customer[j].p_name = (char*)malloc(sizeof(char) * 15);
		scanf("%s", p_customer[j].p_name);
		/* if(strlen(p_customer[j].p_name) > 15)
		//   printf("Name is larger than 15 characters");

		// int l = 0;
		// while (p_customer[j].p_name[l] != '\n') {
		//     char ch = p_customer[i].p_name[l];
		//     putchar(toupper(ch));
		//     j++;
		 }*/
		scanf("%d", &p_customer[j].numOfSmootihes);
	}

	return p_customer;
}


/*------------MAIN FUNCTION------------------*/
int main(void) {

	customers* customers;
	customers = NULL;
	int c; // number of test cases 
	scanf("%d", &c);

	/*Test case for loop*/
	for (int i = 0; i < c; i++) {

		// create queues
		// queue q[] was moved here because after each test case I need a new set of queues
		// no malloc takes place here
		queue q[MAX_SIZE];// creating 12 queues
		for (int i = 0; i < MAX_SIZE; i++) {
			init(&q[i]); // Setting q[i].p_front and q[i].p_back to NULL
		}

		// create customers
		customers = createCustomers(customers);/*m input is recieved in this function. 
												 MALLOC for customers is in this function
												 Each customers data is input in this function.
												 For test case i. Returns customers* */


		/*Putting customers in to proper queue line*/
		for (int j = 0; j < sizeof(customers)+1; j++) {
			enqueue(&q[(customers[j].lineNumber) - 1], &customers[j]);

		/*------------Cust info DEBUGGING START----------------*/
			/* confirming customers are returning to main
			 printf("\nCustomer [%d] entered line at time %d\n", i, customers[i].enterLineTime);
			 printf("Customer [%d] entered line number %d\n", i, customers[i].lineNumber);
			 printf("Customer [%d] Name is %s\n", i, customers[i].p_name);
			 printf("Customer [%d] ordered %d number of smoothies\n\n", i, customers[i].numOfSmootihes);*/
		}// finish loading queues
	/*------------Cust info DEBUGGING END------------------*/


	/*------------Display queues DEBUGGING START----------------*/
		//*
		for (int k = 0; k < MAX_SIZE; k++) {
			printf("Queue line %d: ", k + 1);
			if (q[k].p_front == NULL) {
				printf("EMPTY");
			}
			displayQueue(&q[k]);
			printf("\n");
		}//Display queues DEBUG END*/
	/*------------Display queues DEBUGGING END----------------*/

		// Begin serving customers
		// How do I choose fist customer? 
		// - Find largets "enterLineTime" and make that my currentTIme











	}// End test case for loop

	return 0;
}