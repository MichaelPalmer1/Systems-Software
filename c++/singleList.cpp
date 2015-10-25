#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>
#include "singleList.h"

#endif

using namespace std;

//*****************  class linkedListType   ****************


bool linkedListType::isEmptyList()
{
    return(first == NULL);
}


linkedListType::linkedListType() //default constructor
{
    first = NULL;
    last = NULL;
    count = 0;
}


void linkedListType::destroyList()
{
    nodeType *temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (first != NULL)   //while there are nodes in the list
    {
        temp = first;        //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;   //deallocate the memory occupied by temp
    }
    last = NULL; //initialize last to NULL; first has already
                 //been set to NULL by the while loop
    count = 0;
}


void linkedListType::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}


void linkedListType::print()
{ 
    nodeType *current; //pointer to traverse the list

    current = first;    //set current so that it points to 
                        //the first node
assert(first != NULL);
    while (current != NULL) //while more data to print
    {
        cout << current->info << " ";
        current = current->link;
    }
}//end print


int linkedListType::length()
{
    return count;
}  //end length


int linkedListType::front()
{
    assert(first != NULL);

    return first->info; //return the info of the first node
}//end front


int linkedListType::back()
{
    assert(last != NULL);

    return last->info; //return the info of the last node
}//end back

void linkedListType::insertFirst(int newItem)
{
    nodeType *newNode; //pointer for new node
    newNode = new nodeType; // create new node instance
    newNode->info = newItem; // copy value into info
    newNode->link = first; // point newNode's link to first
    first = newNode; // make newNode the first element
    if (last == NULL) // check if this is the very first node in the list, then last must also be first 
       last = newNode;
    count++; //increase the number of elements in our list by 1
}//end insertFirst

void linkedListType::insertLast(int newItem)
{
    nodeType *newNode;
    newNode = new nodeType;
    newNode->info = newItem;
    newNode->link = NULL;
    if (first == NULL) {
        first = newNode;
        last = newNode;
    } else {
        last->link = newNode;
        last = newNode;
    }
    count++;
}//end insertLast

bool linkedListType::search(int searchItem)
{
    nodeType *current; //pointer to traverse the list
    current = first;    //set current so that it points to
                        //the first node
assert(first != NULL);
    while (current != NULL) //while more nodes to search
    {
        if(current->info == searchItem)
          return true; // we found it in the list
        current = current->link;
    }
    return false;// if no more nodes to search, not in list
}//end search

void linkedListType::deleteNode(int deleteItem)
{
    nodeType *current; //pointer to traverse the list
    nodeType *trailCurrent; //pointer just before current
    bool found;

    if(first == NULL) // Case where list is empty, nothing to delete
         cout<<"Cannot delete from an empty list"<<endl;
    else
    {
         current = first;    //set current so that it points to the first node

         while (current != NULL && !found) //while more nodes to search
         {
             if(current->info == deleteItem)
             {
                  if(first == current) // what we want to delete is at the front of the list
                  {
                       first = first->link; // adjsut the head pointer of the list
                       delete current;  // delete the node
                  }
                  else // if not the first then there is at least one node ahead of this node
                  {
                      trailCurrent->link = current->link; // make trailCurrent's link point to what current was had as next
                      delete current;
                  }
                  found = true;  // we found it in the list
                  count--; //reduce out list by 1
             }
             else
             {
                  trailCurrent = current;
                  current = current->link;
             }
       }
    }
    if (!found) cout<<"Item to be deleted not in this list"<<endl;// if no more nodes to search, not in list
}//end deleteNode

linkedListType::~linkedListType() //destructor
{
   destroyList();
}//end destructor




