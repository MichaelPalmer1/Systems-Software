#include <iostream>
#include <cassert>
#include "singleList.h"

int main(){
    linkedListType ll;
    ll.insertLast(10);
    ll.insertLast(20);
    ll.insertLast(30);
    ll.insertLast(40);
    ll.insertLast(50);
    ll.insertLast(200);
    ll.insertFirst(60);
    ll.insertLast(500);
    ll.print();
    cout<<"length of list is "<<ll.length()<<endl;
    cout<<ll.search(40)<<endl;
    cout<<ll.search(234)<<endl;
    ll.deleteNode(500);
    ll.print();
    cout<<ll.isEmptyList();

}
