#include <iostream>
using namespace std;
class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    Node * prev;
    // Constructer that makes the ptr to NULL
    Node(int value){
        next = NULL;
        prev = NULL;
        data = value;
    }
};

class DLL{
    public:
    Node * head,*tail;
    DLL(){
        head = NULL;
	tail = NULL;
    }
    
    
//************1-INSERT************
    void insert(int value){
        // Create a new node
        Node * temp = new Node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ 
        // If not empty list
		tail->next=temp;
		temp->prev=tail;
            }
	tail=temp;
    }
    
    
    
//***********2-DISPLAY***************
    void display(){
        Node *current = head;
        Node *last;
        cout << "Print in order : ";
        while(current!=NULL){
            cout <<current->data<< "->"; 
            // Store the current in last
            last = current;
            // Move Forward
            current = current->next;
        }
        cout << endl;
  
    }
    
    
    
//***********3-INSERTAT***********
    void InsertAt(int value, int pos){
        //make a new node
	Node *temp = new Node(value);
	//reach that position

	int i=1;
	Node *current=head;
	while(i<pos-1){
		current=current->next;
		i++;
	}
	//back connection
	current->next->prev=temp;
	temp->prev=current;
	//front connection
	temp->next=current->next;
	//final dissconnection
	current->next=temp;
    }
    
    
//***********4-DELETAT**************
    void DeleteAt(int pos){
	//reach the pos-1
	int i=1;
	Node *current=head;
	while(i<pos-1){
		current=current->next;
		i++;
	}
	//store the address of node
	Node *temp=current->next;
	//condition for rearrangement of pointers
	current->next=current->next->next;
	current->next->prev=current;
	temp->next=NULL;
	temp->prev=NULL;
	delete temp;	
}



//************5-DELETE**************
    void Del(){
        //reach the last position
	Node *current=head;
	while(current->next->next != NULL){
		current=current->next;
	}
	//store the address of last one
	Node *temp;
	temp = current->next;
	//break the connection
	current->next->prev=NULL;
	current->next=NULL;
	//finally delete
	delete temp; 
    }
    
    
//***********6-COUNTIETMS*************
    void CountItems(){
        Node *current=head;
	int i=1;
	while(current->next!=NULL){
		current=current->next;
		i++;
	}
	cout<<"Numbers of items in the linkedlist is: "<<i<<endl;
    }

};

//MAIN FUNCTION
int main(){
    DLL dll1;
    for(int i= 1; i < 11; i++)
    {
        dll1.insert(i);
    }
        dll1.display();
	dll1.CountItems();
	dll1.InsertAt(100,5);
	dll1.display();
	dll1.CountItems();
	dll1.Del();
	dll1.display();
	dll1.CountItems();
	dll1.DeleteAt(3);
	dll1.display();
return 0;
}