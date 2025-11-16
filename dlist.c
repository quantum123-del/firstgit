#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

DList new_dlist(void)
{
	return NULL;
}

/*----------------------------------------------------------------------------*/

Bool is_empty_dlist(DList li)
{
	if(li == NULL)
		return true;

	return false;

}

/*----------------------------------------------------------------------------*/

int dlist_length(DList li)
{

	if(is_empty_dlist(li))
		return 0;

	return li->length;

}

/*----------------------------------------------------------------------------*/

int dlist_firs(DList li)
{
	if(is_empty_dlist(li))
		exit(1);

	return li->begin->value;

}


int dlist_last(DList li)
{
	if(is_empty_dlist(li))
		exit(1);

	return li->end->value;

}

/*----------------------------------------------------------------------------*/

void print_dlist(DList li)
{
	if (is_empty_dlist(li))
	{
		printf("Rien a affiche, la DList est vide.\n");
		return;
	}

	DListNode *temp = li->begin;

	while(temp != NULL)
	{
		printf("[%d] ", temp->value );
		temp = temp->next;
	}

	printf("\n");
}


/*----------------------------------------------------------------------------*/

DList push_back_dlist(DList li, int x)
{

	 DListNode *element;

	 element = malloc(sizeof(*element)); // DlistNode *element = malloc..........

	 if(element == NULL)
	 {
	 	fprintf(stderr, "Erreur allcation dynamique.\n");
	 	exit(EXIT_FAILURE);
	 }

	 element->value = x;   // element de base sant aucune laison
	 element->next = NULL;
	 element->back = NULL;

	 // si la liste est vide
	 if (is_empty_dlist(li))
	 {
	 	li = malloc(sizeof(*li));

	 	if (li == NULL)
	 	{
	 		fprintf(stderr, "Erreur allcation dynamique.\n");
	 	exit(EXIT_FAILURE);
	 	}

	 	li->length = 0;
	 	li->begin =element;
	 	li->end = element;
	 }
	 else
	 {
	 	li->end->next = element;
	 	element->back = li->end;
	 	li->end = element;
	 }
	 li->length++;


	 return li;
}

/*----------------------------------------------------------------------------*/

DList push_front_dlist(DList li, int x)
{

	 DListNode *element;

	 element = malloc(sizeof(*element));

	 if(element == NULL)
	 {
	 	fprintf(stderr, "Erreur allcation dynamique.\n");
	 	exit(EXIT_FAILURE);
	 }

	 element->value = x;   // element de base sant aucune laison
	 element->next = NULL;
	 element->back = NULL;

	 // si la liste est vide
	 if (is_empty_dlist(li))
	 {
	 	li = malloc(sizeof(*li));

	 	if (li == NULL)
	 	{
	 		fprintf(stderr, "Erreur allcation dynamique.\n");
	 	exit(EXIT_FAILURE);
	 	}

	 	li->length = 0;
	 	li->begin =element;
	 	li->end = element;
	 }
	 else
	 {
	 	li->begin->back = element;
	 	element->next = li->begin;
	 	li->begin = element;
	 }

	 li->length++;

	 return li;

}


/*----------------------------------------------------------------------------*/

// supresssion d'element depuis la fin ie le dernier element insere
DList pop_back_dlist(DList li)
{
	if (is_empty_dlist(li))
	{
		printf(" Rien a supprime, la DListe est deja vide.\n");
		return new_dlist(); // ou li les deux passe sans probleme...
	}

	if(li->begin == li->end) // ici je regarde la dresse des pointeurs s il corresponde
	{
		free(li);
		li = NULL;

		return new_dlist();
	}


	/* on cherche a supprime le dernier ellement 
	de la liste donc on va le save dans temp a
	 parti de la on va pouvoir considere toutes nos modifications */

	DListNode *temp = li->end;

	li->end = li->end->back; // on deplace le pointeur de li->end sa de vient li->end->back
	li->end->next = NULL;
	temp->next = NULL; // on lisole
	temp->back = NULL;

	free(temp);
	temp = NULL;

	li->length--;

	return li;

}

/*----------------------------------------------------------------------------*/

DList pop_front_dlist(DList li)
{

	if (is_empty_dlist(li))
	{
		printf(" Rien a supprime, la DListe est deja vide.\n");
		return new_dlist(); // ou li deux passe sans probleme...
	}

	if(li->begin == li->end) // ici je regarde la dresse des pointeurs s il corresponde
	{
		free(li);
		li = NULL;

		return new_dlist();
	}


	/* on cherche a supprime le premier ellement 
	de la liste donc on va le save dans temp a
	 parti de la on va pouvoir considere toutes nos modifications */

	DListNode *temp = li->begin;

	li->begin = li->begin->next; // on deplace le pointeur de li->end sa de vient li->end->begin
	li->begin->back = NULL;   // le premier element va etre le scond actuel
	temp->next = NULL; // on lisole
	temp->back = NULL;

	free(temp);
	temp = NULL;

	li->length--;

	return li;
}

/*----------------------------------------------------------------------------*/

DList clear_dlist(DList li)
{
	while(!is_empty_dlist(li))
		li = pop_back_dlist(li);

	return NULL;
}