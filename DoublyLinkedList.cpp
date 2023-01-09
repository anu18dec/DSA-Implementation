#include <iostream>
using namespace std;

class Node{

	public:
		int data;
		Node * next;
		Node * prev;

};

class DoublyList{

	private:
		Node * head;
		Node * tail;

	public:
		DoublyList(){

			head = NULL;
			tail = NULL;
		}

		DoublyList(int size, int value = 0){

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

		void display()
		{
			Node *p;
			p = head;
			while(p)
			{
				cout<<p->data<<"\n";
				p = p->next;
			}
		}


};

int main()
{	

	// Creating main for testing

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif


	DoublyList list(20,0);
	list.display();

	return 0;
}
