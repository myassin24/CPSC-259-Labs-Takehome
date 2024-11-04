/*
 File:         linkedlist.c
 Purpose:      Implements the linked list functions whose prototypes
               are declared in the linked_list.h header file
 Author:       Munira Yassin Jackson Rockford
 Student #s:   80535743 and 99991564
 CWLs:         ymunira and jrockfor
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

   
    //temp->plane = plane;

    //copying each field of plane properly just the ints

    temp->plane.flight_number = plane.flight_number;
    temp->plane.priority = plane.priority;
    temp->plane.maximum_speed_kph = plane.maximum_speed_kph;
    temp->plane.cruising_altitude = plane.cruising_altitude;
    temp->plane.capacity = plane.capacity;

    // allocate memory and copy plane city o and cityd;

    if (plane.city_origin != NULL) {
        int city_o_length = strlen(plane.city_origin);       //size of malloc for city o
        temp->plane.city_origin = (char*)malloc(city_o_length * sizeof(char)); //allocate
        strcpy(temp->plane.city_origin, plane.city_origin);  //copy contents of city o


    }
    else {
        free(temp->plane.city_origin);
        temp->plane.city_origin = NULL;
        return temp;
    }

    if (plane.city_destination != NULL) {
        int city_d_length = strlen(plane.city_destination);    //size of malloc for city d
        temp->plane.city_destination = (char*)malloc(city_d_length * sizeof(char));  //allocate
        strcpy(temp->plane.city_destination, plane.city_destination); //copy contents of city d


    }
    else {
        free(temp->plane.city_destination);
        temp->plane.city_destination = NULL;
        return temp;
    }

   
    
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
        return list;
    }

   if (list->next == NULL) {
        free(list);
        list = NULL;
        return NULL;
    }
    

    node* ptr;
   
   

    ptr = list;
    //char* city_o = ptr->plane.city_origin;
    //char* city_d = ptr->plane.city_destination;

    list = list->next;

   
    /*ptr->plane.capacity = 0;
    ptr->plane.cruising_altitude = 0;
    ptr->plane.maximum_speed_kph = 0;
    ptr->plane.priority = 0;
    ptr->plane.flight_number = 0;*/
    //free(city_o);
    //free(city_d);
    free(ptr);
   
    ptr = NULL;


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
    //list = list->next;

    while (list != NULL) {
        node* sac_node = list;
        list = list->next;
        free(sac_node);
        sac_node = NULL;
    }
    // replace this line with something appropriate
    return NULL;
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
    printf("flight_number: %d\n", node_to_print->plane.flight_number);
    printf("city_origin: %c\n", node_to_print->plane.city_origin);
    printf("city_desitnation: %c\n", node_to_print->plane.city_destination);
    printf("priority: %d\n", node_to_print->plane.priority);
    printf("maximum_speed_kph: %d\n", node_to_print->plane.maximum_speed_kph);
    printf("cruising_altitude: %d\n", node_to_print->plane.cruising_altitude);
    printf("capacity: %d\n", node_to_print->plane.capacity);
    return;
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
    if (list_to_print == NULL) {
        return;
    }
    node* ptr;
    ptr = list_to_print;
    while (ptr != NULL) {
        print_node(list_to_print);
        ptr = ptr->next;
    }

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
    //NULL check
    if (list == NULL) {
        return list;
    }

    //only one thing in your list




    //only one thing in your list

    if ((strcmp(list->plane.city_destination, destination_city) == 0)) {
        //node* delete_node1 = list;
      
        //list = list->next;
        //free(delete_node1);
        //free(list);
   
        if (list->next == NULL) { free(list); 
            return NULL; }
        else {
            node* ptr_d = (node*)malloc(sizeof(node));
            ptr_d = list;
            list = list->next;
            free(ptr_d);
            ptr_d = NULL;
        }

        
        //delete_node1 = NULL;

        return list;
    }


    node* ptr = (node*)malloc(sizeof(node));
    node* prev;
    node* future;
    //int i = 0;

    //node* d_node;
    ptr = list;
   // i = get_length(list);
    // ptr = list;
    prev = ptr;
    ptr = ptr->next;

    while (ptr != NULL) {
        future = ptr->next;
        if (strcmp(ptr->plane.city_destination, destination_city) == 0) {
            node* delete_node = (node*)malloc(sizeof(node));
            delete_node = ptr;
            prev->next = future;
            ptr = future;
            //delete_node(ptr);
            //ptr = future;
            free(delete_node);
            delete_node = NULL;
            return list;



           // ptr = future;
            //d_node = ptr;
           // prev = ptr;
           // ptr = ptr->next;
            //free(d_node);

        }

        else {
            prev = ptr;
            ptr = future;
        }

    }
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
    if (list == NULL && ordinality != 1) {
        return NULL;
    }
    //ord checks
    if ((ordinality <= 0) || (ordinality > (get_length(list) + 1))) {
        return list;

    }
    if (node_to_insert == NULL) {
        return list;
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
    if (ordinality == get_length(list) + 1) {
        node_to_insert->next = ptr;
        prev->next = node_to_insert;
    }
    return list;
}
