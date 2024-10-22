/*
 File:         linkedlist.c
 Purpose:      Implements the linked list functions whose prototypes
               are declared in the linked_list.h header file
 Author:       Munira Yassin
 Student #s:   80535743 and 12345678
 CWLs:         ymunira and cwl2
 Date:         Add the date here
 */

#define _CRT_SECURE_NO_WARNINGS

 /* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/******************************************************************
 PLEASE EDIT THIS FILE

 Comments that start with // should be replaced with code
 Comments that are surrounded by * are hints
 ******************************************************************/

 /*
  Returns a pointer to a new, empty linked list of struct node.
  PRE:       NULL (no pre-conditions)
  POST:      NULL (no side-effects)
  RETURN:    A pointer to a new, empty linked list of struct node (NULL)
  */
node* create_linked_list()
{
    // Insert your code here
    node* head = NULL;
    return head;
}

/*
 Returns a dynamically allocated struct node that contains the specified
 struct airplane. Note that the string attributes of the newly created
 node's struct airplane must be specially copied (refer to lab 2).
 The node's next pointer doesn't point to anything
 PARAM:     plane, a struct airplane
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a dynamically allocated struct node a) that contains
            the specified struct airplane, and b) whose next pointer points to NULL
 */
node* create_node(airplane plane)
{
    node* temp;
    temp = (node*)malloc(sizeof(node));
   
    //we need to give the temp node the information from the given plane 
    temp->plane = plane;
    //making temp point to nothing
    temp->next = NULL;

    return temp;
}

/*
 Prepends a struct node passed as a parameter to the list passed as a
 parameter, and returns a pointer to the result.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     new_node is a pointer to a struct node
 PRE:       new_mode is not null
 POST:      The specified struct node is added to the beginning of the list
            and its next pointer points to the node that used to be first
 RETURN:    A pointer to a linked list which contains all of the nodes
            of the list passed as a parameter, plus a prepended node
 */
node* prepend_node(node* list, node* new_node)
{
    // Insert your code here
   

    //NULL check (if list is empty)
    if (list == NULL) {
        new_node->next = NULL;  //new_node points to nothing
        list = new_node;
        return list;
    }
    // what if new_node is NULL 
    
    //list is not empty
    //make new node point to where list is pointing to
    new_node->next = list;
    list = new_node;
    

    // replace this line with something appropriate
    return list;
}

/*
 Deletes the first struct node in the specified list, and returns a pointer to
 the shortened list. Be aware of nested allocations!
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL
 POST:      The list passed as a parameter has one fewer node, and the dynamically
            allocated memory which contained that removed node has been freed
 RETURN:    IF the list is empty
            THEN NULL
            ELSE a pointer to the shortened list
 */
node* delete_node(node* list)
{
    // Insert your code here
    
    //NULL check
    if (list == NULL) {
        return NULL;
    }

    node* ptr = list;

    ptr = list;
    list = list->next;
    //ptr ->next = NULL;
    free(ptr);


    // replace this line with something appropriate
    return list;
}

/*
 Returns the number of nodes in the specified linked list of struct node.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    The length of the specified list, an int
 */
int get_length(node* list)
{
    // Insert your code here
    
    //NULL check
    if (list == NULL) {
        return 0;
    }

    int length = 0;
    node* ptr = list;

    while (ptr != NULL) {
        length++;
        ptr = ptr->next;
    }

    // replace this line with something appropriate
    return length;
}

/*
 Deletes an entire list.  This function iterates along a list and deallocates the
 memory containing each struct node.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The memory containing all of the nodes in the list has been freed
 RETURN:    an empty list (NULL)
 */
node* delete_list(node* list)
{
    // Insert your code here
    //NULL
    if (list == NULL) {
        return list;
    }
    
    int length = get_length(list);
    node* deleted_node = list;
    list = list->next;

    if (length == 1) {
        deleted_node = NULL;
        free(deleted_node);
        return deleted_node;
    }
    
    while (list != NULL) {
        free(deleted_node);
        deleted_node = list;
        list = list->next;
    }

    free(deleted_node);
    // replace this line with something appropriate
    return list;
}

/*
 Prints the data stored in a node.  For the struct airplane in the node,
 prints the fields on separate lines.  For each field, prints the field name
 and the field value.  For the pointer, prints "Link = NULL\n" if the pointer points
 to null, else prints "Link points to address xxx\n", where xxx is the pointer address
 in hexademical.
 If node_to_print is NULL, prints "The node is empty\n".
 PARAM:     node_to_print is a pointer to a (possibly null) struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about node_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_node(node* node_to_print)
{
    // Insert your code here
    if (node_to_print == NULL) {
        return;
    }

    /*typedef struct airplane {
	// Add your member elements here
	int flight_number;
	char* city_origin;
	char* city_destination;
	int	priority;
	int	maximum_speed_kph;
	int	cruising_altitude;
	int	capacity;
} airplane;*/

   /* printf("flight_number: ");
    printf("city_origin: ");
    printf("flight_number: ");
    printf("flight_number: ");
    printf("flight_number: "); */
}

/*
 Prints the data stored in all nodes in the specified list to print.
 For each node, prints the data inside the node the same way that it
 is printed by print_node.  If the list is empty, a suitable message
 is printed to standard output.
 PARAM:     node_to_print is a pointer to a (possibly empty) linked list of
            struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about list_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_list(node* list_to_print)
{
    // Insert your code here

}

/*
 Reverses a list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The order of the nodes in the list passed as a parameter has been
            reversed
 RETURN:    a list of struct node that is the reverse of the list passed as a
            parameter
 */
node* reverse(node* list)
{
    // Insert your code here
    //Null check
    if (list == NULL) {
        return NULL;
    }

    node* ptr;
    node* prev;
    node* next;

    ptr = list;
    prev = NULL;
    next = NULL;
    

    while (ptr != NULL) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }

    list = prev;
    // replace this line with something appropriate
    return list;
}

/*
 Removes every node from the list which contains an airplane destined for
 the city name passed in the second parameter.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     destination_city is a pointer to a null-terminated array of char
 PRE:       NULL (no pre-conditions)
 POST:      Any struct node in the list which contains an airplane struct
            destined for the destination_city is removed from the list, and
            the memory deallocated
 RETURN:    a list of struct node that does not contain any struct node that
            has an airplane destined for the destination_city
 */
node* remove_from_list(node* list, char* destination_city)
{
    // Insert your code here

    //NULL check
    if (list == NULL) {
        return list;
    }

    //only one thing in your list
    if (list->next == NULL) {
        if (strcmp(list->plane.city_destination, destination_city) == 0) {
            list = NULL;
            free(list);
            return NULL;
        }
    }

    node* ptr;
    node* prev;
    node* next;

    ptr = list;
    prev = ptr;
    ptr = ptr->next;

    while (ptr != NULL) {
        next = ptr->next;
        if (strcmp(ptr->plane.city_destination, destination_city) == 0) {
            prev->next = ptr->next;
            free(ptr);
            ptr = next;
            prev = ptr;

        }
        else {
            prev = ptr;
            ptr = next;
        }
       
    }


   
    // replace this line with something appropriate
    return list;
}

/*
 Returns a reference to the nth node (but does not remove it ) in the
 specified list.  If the list is too short, returns NULL.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list
            THEN a pointer to the nth node
            ELSE NULL
 */
node* retrieve_nth(node* list, int ordinality)
{
    // Insert your code here
    // NULL check
    if (list == NULL) {
        return list;
    }
    // ordinality > 0
    if (ordinality <= 0) {
        return NULL;
    }
    // ordinality <= list length
    if (ordinality > get_length(list)) {
        return NULL;
    }
    if (ordinality == 1) {
        return list;
    }

    node* ptr = list;
    int i = 1;

    while (i < ordinality) {
        ptr = ptr->next;
        i++;
    }
    

    // replace this line with something appropriate
    return ptr;
}

/*
 Inserts the specified node into the specified list of nodes at the specified
 ordinality.  For example, if ordinality = 1, this is a simple prepend_node
 operation.  If ordinality = 3, then when this function is finished, the third
 node in the list will be the node_to_insert.  If the ordinality = the length
 of the list + 1, then the node_to_insert is appended to the end of the list.
 If the ordinality > 1 + length of the list, the function returns a pointer
 to the unchanged list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 PRE:       node_to_insert is NEVER a null (it is always a correct node pointer)
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list + 1
            THEN a pointer to the list which contains the node_to_insert in the
      correct location
            ELSE a pointer to the unchanged list
 */
node* insert_nth(node* list, node* node_to_insert, int ordinality)
{
    // Insert your code here
    //null check
    if ((list == NULL)  && (ordinality != 1)) {
        return list;
    }
    //ord checks
    if ((ordinality <= 0) || (ordinality > get_length(list))) {
        return NULL;

    }
    if (node_to_insert == NULL) {
        return NULL;
    }
    if (ordinality == 1) {
        
        node_to_insert->next = list;
        list = node_to_insert;
        return list;
    }

    node* ptr;
    node* prev;

    ptr = list;
    prev = ptr;
    ptr = ptr->next;

    int i = 1;

    while (ptr != NULL) {
        i++;
        if (i == ordinality) {
                node_to_insert->next = ptr;
                prev->next = node_to_insert;
        }

        prev = ptr;
        ptr = ptr->next;
    }



    // replace this line with something appropriate
    return list;
}
