#include <iostream>
using namespace std;

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        data = value;
    }
};

class CSLL{
    public:
    Node * head;
    CSLL(){
        head = NULL;
    }
//1-Insert
    void insert(int value){
        
        // Create a new node
        Node * temp = new Node(value);
        // Check if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ 
             Node * current = head; // If not empty list. 
            while(current->next != head)
                current = current->next;
            current->next = temp;
        }
	//now make it circular like shift to tail and tail point to head
        temp->next = head;
    }
//2-Display
    void display(){
        Node * current = head;
        if(current == NULL) {
            cout << "No elements in the linked list " << endl;
            return;
        }
	// Stop at head
        while(current->next != head){ 
            cout << current -> data << "->";
            current = current -> next;
        }
        // Printing the last element
        cout << current -> data ;
        cout << endl;
    }
//3-insertAt
    void InsertAt(int value, int pos){
	//make a new node
	Node *temp=new Node(value);
	Node *current=head;
	//reach the position
	int i=1;
	while(i<pos-1){
		current=current->next;
		i++;
	}
	//conditions for inserting at that position
	if(current->next==head){
		temp->next=head;
		current->next=temp;
	}
	else{	
		temp->next=current->next;
		current->next=temp;
    	}
    }
//4-DeleteAt
    void DeleteAt(int pos){
 	//reach position-1
	Node *current=head;
	int i=1;
	while(i<pos-1){
		current=current->next;
		i++;
	}
	//store the addrerss of node
	Node *temp;
	temp=current->next;
	//rearrangement of pointers
	current->next=temp->next;
	temp->next=NULL;
	delete temp;        
    }
//5-Delete
    void Delet(){
        Node *current=head;
	while(current->next->next!=head){
		current=current->next;
	}
   	//store the address of the last one
	Node *temp;
	temp=current->next;//break the connections
	current->next=head;
	temp->next=NULL;
	delete temp;//delete
    }
//6-countitems
    void CountItems(){
        Node *current=head;
	int i=1;
	while(current->next!=head){
	//Store the current in last 
		current=current->next;//move forward
		i++;
	}
	cout<<"Numbers of items in the circular linked list is : "<<i<<endl;
    }

};

int main(){
    CSLL csll1;
    for(int i= 1; i < 11; i++){
       csll1.insert(i);
    }
	csll1.display();
        csll1.CountItems();
        csll1.InsertAt(56,6);
        csll1.display();
	csll1.CountItems();
	csll1.Delet();
	csll1.display();
	csll1.CountItems();
	csll1.DeleteAt(6);
	csll1.display();
	csll1.CountItems();
return 0;
}



