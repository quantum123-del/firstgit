#include <stdio.h>
#include "dlist.h"



int main(int argc, char const *argv[])
{
	DList mylist = new_dlist();
	print_dlist(mylist);
	printf("Taille de la DList : %d\n", dlist_length(mylist));
	printf("\n----------------------------------------\n");

	// on teste les differentes fontions
	mylist = push_back_dlist(mylist, 14);
	print_dlist(mylist);
	printf("Taille de la DList : %d\n", dlist_length(mylist));
	printf("\n----------------------------------------\n");

	mylist = push_front_dlist(mylist, 6);
	mylist = push_back_dlist(mylist, 23);
	print_dlist(mylist);
	printf("Taille de la DList : %d\n", dlist_length(mylist));
	printf("\n----------------------------------------\n");
	mylist = clear_dlist(mylist);
	
	print_dlist(mylist);
	printf("Taille de la DList : %d\n", dlist_length(mylist));




	/*if(is_empty_dlist(mylist))
		printf("Elle est vide.\n");
	else
		printf(" Elle contient des element. \n");

	mylist = pop_front_dlist(mylist);
	mylist = pop_back_dlist(mylist);
	print_dlist(mylist);
	printf("Taille de la DList : %d\n", dlist_length(mylist));
	printf("\n----------------------------------------\n");

	mylist = pop_front_dlist(mylist);*/

	return 0;
}