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

		// Return Node type first element pointer
		Node * begin(){

			return head;
		}

		// Return Node type last element pointer
		Node * end(){

			return tail;
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
	DoublyList list(20,0);
	list.pushBack(10);
	list.display();
	cout<<endl;
	list.pushFront(1);
	list.display();
	cout<<endl;
	// cout<<list.front()<<endl;
	// cout<<list.back()<<endl;
	list.popFront();
	list.popBack();
	list.display();
	cout<<endl;


	return 0;
}
