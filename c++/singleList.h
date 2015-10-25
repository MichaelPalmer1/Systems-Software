
// ifndef checks if we already included this section of code, to avoid duplicate errors
  
#include <iostream>
#include <cassert>

using namespace std;

//Definition of the node


struct nodeType
{
	int info;
	nodeType *link;
};

//*****************  class linkedListType   ****************
class linkedListType
{
public:
    void initializeList(); 
      //Initialize the list to an empty state.
      //Postcondition: first = NULL, last = NULL, count = 0;

    bool isEmptyList();
      //Function to determine whether the list is empty. 
      //Postcondition: Returns true if the list is empty,
      //               otherwise it returns false.

    void print();
      //Function to output the data contained in each node.
      //Postcondition: none

    int length();
      //Function to return the number of nodes in the list.
      //Postcondition: The value of count is returned.

    void destroyList();
      //Function to delete all the nodes from the list.
      //Postcondition: first = NULL, last = NULL, count = 0;

    int front(); 
      //Function to return the first element of the list.
      //Precondition: The list must exist and must not be 
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the first 
      //               element of the list is returned.

    int back(); 
      //Function to return the last element of the list.
      //Precondition: The list must exist and must not be 
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the last  
      //               element of the list is returned.

    bool search(int searchItem);
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise the value false is 
      //               returned.

    void insertFirst(int newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the list, 
      //               and count is incremented by 1.

    void insertLast(int newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the end of the list,
      //               last points to the last node in the list,
      //               and count is incremented by 1.

    void deleteNode(int deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated 
      //               list, and count is decremented by 1.

    linkedListType(); 
      //default constructor
      //Initializes the list to an empty state.
      //Postcondition: first = NULL, last = NULL, count = 0; 

    ~linkedListType();   
      //destructor
      //Deletes all the nodes from the list.
      //Postcondition: The list object is destroyed. 

//protected:
    int count;   //variable to store the number of 
                 //elements in the list
    nodeType *first; //pointer to the first node of the list
    nodeType *last;  //pointer to the last node of the list

};
