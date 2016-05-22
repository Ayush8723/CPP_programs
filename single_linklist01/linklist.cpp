/*****************************************************************************
* File Name: linklist.cpp
* Author: Ayush Gupta
* Description: Link list basics using c++
*****************************************************************************/

/*********************************Include************************************/
#include <iostream>
using namespace std;
#include "linklist.h"


/*******************************Declarations*********************************/

class link_list
{
  private:
    int total_nodes;      /*Total number of nodes in link list*/
    struct node *start;   /*start pointer points to start of link list*/
    struct node *temp;    /*temp pointer used to traverse through link list*/
  public:
    link_list();                   /*Constructor Function*/
    void num_of_nodes();           /*Total nodes to be created*/	
    void create_link_list();       /*Create Link List*/
    void insert_node(int value);   /*Insert new node at the end in link list*/
    void print_link_list();        /*Print link list*/
    
};

/*******************************Definitions**********************************/


/*****************************************************************************
* Function: link_list()
* Scope: class link_list
* Type: Public function member 
* Description: Constructor function for class link_list. Initializes the     
*              private data members of the class link_list                   
*****************************************************************************/

link_list :: link_list()
{
  start = NULL;       /**Initialize start pointer to NULL*/
  temp = NULL;        /**Initialize temp pointer to NULL*/
  total_nodes = 0;    /**Initialize total_nodes to 0*/
}

/*****************************************************************************
* Function: num_of_nodes()
* Scope: class link_list
* Type: Public function member 
* Description: Take input from user to Define the total number of nodes to be
*              created.                    
*****************************************************************************/
   
void link_list :: num_of_nodes()
{
  cout << "Enter the number of nodes to be created"<<endl;
  cin >> total_nodes;      /**Input the total number of nodes to be created*/
}

/*****************************************************************************
* Function: create_link_list()
* Scope: class link_list
* Type: Public function member 
* Description: Create Link list at runtime based on user input of total number
*              of nodes to be created.                    
*****************************************************************************/

void link_list :: create_link_list()
{
  int i;
  int node_data;
  cout << "Enter node data\n";
  for(i=0;i<total_nodes;i++)
  {
    cin >> node_data;          /*User input node data*/
    insert_node(node_data);    /*Insert new node at end of list*/
  }
}

/*****************************************************************************
* Function: insert_node()
* Scope: class link_list
* Type: Public function member 
* Description: Insert a new node at the end of the list.
*****************************************************************************/

void link_list :: insert_node(int value)
{
  if(start == NULL)
  {
    /*Allocate memory to first node of link list*/
    start = new (nothrow) struct node;
    /*Check if memory has been allocated*/ 
    if(start == NULL)
    {
      /*Error*/
    	cout << "Memory not allocated\n";
    	return;
    }
    start->link = NULL;   /*Last node points to NULL*/
    start->data = value;  /*Assign value to first node*/
  }
  else
  {
    temp = start;  /*Assign starting address to temp pointer*/
    /*Traverse to end of list*/
    while(temp->link != NULL)
      temp = temp->link;
    
    /*Allocate memory for new node at end of list*/
    temp->link = new (nothrow) struct node;
    /*Check if memory has been allocated*/ 
    if(temp->link == NULL)
    {
      /*Error*/
    	cout << "Memory not allocated\n";
    	return;
    }
    temp = temp->link;   /*Assign address of new node to temp pointer*/
    temp->data = value;  /*Assign value to new node created*/
    temp->link = NULL;   /*Last node points to NULL*/
  }
}

/*****************************************************************************
* Function: print_link_list()
* Scope: class link_list
* Type: Public function member 
* Description: Print link list upto end of the list.
*****************************************************************************/

void link_list :: print_link_list()
{
  int node_num;
  node_num = 0;
  temp = start;  /*Assign starting address of list to temp pointer*/

  cout << "The data and address of the link list are: "<< endl;
  do
  {
    node_num++;
    cout << "Data of node "<< node_num << " = " << temp->data << "\t" << \
      "Address of next node = "<< temp->link << endl;
    temp = temp->link;  /*Assign address of next node to temp pointer*/
  }while(temp != NULL);  /*Point to next node till end of list is reached*/
}

/*****************************************************************************
* Function: main()
* Description: Main function.
*****************************************************************************/
int main()
{
  link_list list1;            /*Create Object "list1" of class link_list*/
  list1.num_of_nodes();       /*Define total number of nodes for list1*/
  list1.create_link_list();   /*Create link list of object "list1"*/
  list1.print_link_list();    /*Print link list of object "list1"*/
  return 0;
}


/***********************************EOF**************************************/