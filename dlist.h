#ifndef __DLIST__H__
#define __DLIST__H__

	/* Definition d un booleen*/
	typedef enum
	{
		false,
		true
	}Bool;

	/* Definition d un maillon de la Dliste*/
	typedef struct DListNode
	{

		int value;
		struct DListNode *back ; //  nouvelle ligne par rapport a la liste chaine
		struct DListNode *next;
		
	}DListNode;
	

	/* Defition d' une Dlist */
	typedef struct DList
	{
		int length;
		struct DListNode *begin;
		struct DListNode *end;

	}*DList;

	/* Prototypes */

	DList new_dlist(void);
	Bool is_empty_dlist(DList li);
	int dlist_length(DList li);
	int dlist_firs(DList li);
	int dlist_last(DList li);
	void print_dlist(DList li);

	// pour la fin
	DList push_back_dlist(DList li, int x);

	// pour le debut
	DList push_front_dlist(DList li, int x);

	//fonction qui permet de retire une valeur a la fin
	DList pop_back_dlist(DList li);

	DList pop_front_dlist(DList li);

	DList clear_dlist(DList li);
	



	


#endif