#include <stdio.h>
#include "queue.h"

/*
	Shane West
	
	
	This program provides the user with a menu that deals
	with priority queues. The menu contains four options: Add, Delete,
	List and Quit. 
*/

int menu(void);

int main(void) {
	int selection, data_to_add, data_removed, priority;
	queue top;
	init_queue(&top);
  	selection = menu();
  	while (selection != 4) {
   	  switch (selection) {
	
/*
	Case 1: Add
	
	If the user chooses "Add" the program well check to see 
	if the queue is full. If the queue is not full the program
	will receive a number and a priority from the user and add it to the queue.
	If the queue is full the user will be prompted with an error message.

*/
        case 1: if (!is_full()) {
						printf("Enter a number: ");
						scanf("%d", &data_to_add);
						printf("Enter a priority: ");
						scanf("%d", &priority);
						add(&top, data_to_add, priority);
					} else
						printf("Queue is full!\n");
                break;

/*
	Case 2: Delete
	
	If the user chooses "Delete" the program well check to see 
	if the queue is empty. If the queue is not empty the program
	will remove the first number that was added to the queue and display
	a message telling the user what was removed. If the queue is empty the
	user will be prompted with an error message.

*/

        case 2: if (!is_empty(top)) {
						data_removed = fetch(&top);
						printf("%d was removed.\n", data_removed);
					} else
						printf("Queue is empty!\n");
					break;
					
/*
	Case 3: List
	
	If the user chooses "List" the program well check to see 
	if the queue is empty. If the queue is not empty the program
	will print out the queue. If the queue is empty the user will
	be prompted with an error message.

*/

		  case 3: if (!is_empty(top)) {
						print_queue(top);
					} else
						printf("Queue is empty!\n");
					break;
/*
	Default:
	
	If the user does not enter a selection between 1-4 the program
	will prompt the user with an error message.
*/
					
	   default: printf("%d is not a valid selection\n", selection);
     }
     selection = menu();
  }

/*
	If the user enters 4(Quit) the program will end.
*/
  printf("Bye!\n");
}

/*
	Menu Subprogram
	
	This prints out the options for the menu, gets a selection
	from the user, and returns that selection.
*/
	
int menu(void) {
    int choice;
    printf("1: Add\n");
    printf("2: Delete\n");
    printf("3: List\n");
    printf("4: Quit\n");
    printf("Enter a Selection: ");
    scanf("%d", &choice);
    return choice;
}