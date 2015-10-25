#include <cstdlib>
#include <iostream>
#include "list.h"
using namespace std;

static list_t *lists;

int main() {
	struct list_s *current;
	struct list_s *lst;

	//lst = malloc( sizeof( list_t ) );
	lst->data = 25;
	lst->next = lists;
	lists = lst;

	for ( current = lists; current ; current = current->next ) {
		if(current->next == NULL) {
			cout << "Found the end" << endl;
			break;
		}
		cout << "Data: " << current->data << endl;
	}
}
