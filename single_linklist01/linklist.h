/*****************************************************************************
* File Name: linklist.h
* Author: Ayush Gupta
* Description: Header file 
*****************************************************************************/

#ifndef LINK_LIST_H     /*Inclusion Guards to avoid multiple inclusions*/
#define LINK_LIST_H
/*******************************Declarations*********************************/

struct node
{
  int data; 	        /*Data of node*/
  struct node *link;	/*Pointer to next node*/
};

#endif
/***********************************EOF**************************************/