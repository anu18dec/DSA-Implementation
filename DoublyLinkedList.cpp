#include <iostream>
using namespace std;

// Node class
class Node{

	public:
		int data;
		Node * next;
		Node * prev;

};


// Doubly LinkedList class
class DoublyList{

	private:

		Node * head;
		Node * tail;

	public:

		// User defined constructor without parameter
		DoublyList(){

			head = NULL;
			tail = NULL;
		}

		// Parameterized user defined constructor that take size and value
		DoublyList(int size , int value = 0){

			Node * temp;

			if( size > 0 ){

				temp = new Node;
				temp->data = value;
				temp->prev = NULL;
				temp->next = NULL;
				head = temp;
				tail = temp;
				size--;
			}

			while( size > 0 ){
				
				temp = new Node;
				temp->data = value;
				temp->prev = tail;
				temp-> next = NULL;
				tail->next = temp;
				tail = temp;
				size--;
			}
		}

		// Return first element if exist otherwise return -1
		int front(){

			if(head){

				return head->data;
			}
			else{

				return -1;
			}
		}

		// Return last element if exist otherwise return -1
		int back(){

			if(tail){

				return tail->data;
			}
			else{

				return -1;
			}
		}



		// Appending value at front
		void pushFront(int value){

			if(head){

				Node * temp = new Node;
				temp->data = value;
				temp->prev = NULL;
				temp->next = head;
				head->prev = temp;
				head = temp;
			}
			else{

				Node * temp = new Node;
				temp->data = value;
				temp->prev = NULL;
				temp->next = NULL;
				head = tail = temp;
			}

		}

		// Appending node at back
		void pushBack(int value){

			if(head){

				Node * temp = new Node;
				temp->data = value;
				temp->prev = tail;
				temp->next = NULL;
				tail->next = temp;
				tail = temp;
			}
			else{

				Node * temp = new Node;
				temp->data = value;
				temp->prev = NULL;
				temp->next = NULL;
				head = tail = temp;
			}

		}

		// Remove beginning element from Linkedlist
		void popFront(){

			if(head){

				Node * temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
			}
		}

		// Remove last element from Linkedlist
		void popBack(){

			if(tail){

				Node * temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
			}
		}

		// Insert element at position
		void insert(int pos, int value){


			if(pos > 1){

				Node * n = head;
				pos--;

				while(n->next && pos > 0){

					n = n->next;
					pos--;
				}

				if(pos == 0){

					Node * p = n->prev;
					Node * temp = new Node;
					temp->data = value;
					temp->next = n;
					temp->prev = p;
					p->next = temp;
					n->prev = temp;
				}
			}
			else{

				Node * temp = new Node;
				temp->data = value;
				temp->prev = NULL;
				temp->next = head;
				head->prev = temp;
				head = temp;
			}

		}

		int empty(){

			return head != NULL;
		}

		// Printing all elements
		void display()
		{
			Node *p;
			p = head;
			while(p){

				cout<<p->data<<" ";
				p = p->next;
			}
		}

};

int main()
{	

	// Creating main for testing
	DoublyList list(5,0);
	list.pushBack(10);
	list.pushFront(1);
	list.display();
	cout<<endl;
	list.popFront();
	list.popBack();
	list.display();
	cout<<endl;
	list.insert(3,4);
	list.insert(1,5);
	list.display();
	cout<<endl;


	return 0;
}
