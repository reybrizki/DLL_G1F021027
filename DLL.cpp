#include <iostream>
using namespace std;

// deklarasi double linked list
struct node{												// Dibuat oleh Nama : Rey Babul Rizki_NPM : G1F021027
	int data;
	node *prev;
	node *next;
};

node *head, *tail, *cur, *newNode, *del, *afterNode;

// Create Double Linked List
void createDoubleLinkedList(int data){
	head = new node();
	head->data = data;
	head->prev = NULL;
	head->next = NULL;
	tail = head;
}

// count Double Linked List
int countDoubleLinkedList()
{
	if (head == NULL){
		cout << "Double Linked List belum dibuat!";
	}else{
	    cur = head;
	    int jumlah = 0;
	    while( cur != NULL ){
	    	jumlah++;      
	    	//step
	    	cur = cur->next;
	    }
	    return jumlah;
	}
}

// tambahAwal atau Insert First Double Linked list
void addFirst(int data){
	if (head == NULL){
    	cout << "Double Linked List belum dibuat!";
	}else{
		newNode = new node();
	    newNode->data = data;
	    newNode->prev = NULL;
	    newNode->next = head;
	    head->prev = newNode;
		head = newNode;
  }
}

// tambahAkhir atau Insert Last Double Linked List
void addLast(int data){
	if (head == NULL){
		cout << "Double Linked List belum dibuat!";
	}else{
	    newNode = new node();
	    newNode->data = data;
	    newNode->prev = tail;
	    newNode->next = NULL;
	    tail->next = newNode;
	    tail = newNode;
	}
}

// tambahTengah atau Insert Before Double Linked List
void addMiddle( int data, int posisi ){
	if (head == NULL){
    	cout << "Double Linked List belum dibuat!";
	}else{

    if (posisi == 1){
      cout << "Posisi bukan posisi tengah!" << endl;
    }else if (posisi < 1 || posisi > countDoubleLinkedList()){
      cout << "Posisi diluar jangkauan!" << endl;
    }else{
    	newNode = new node();
    	newNode->data = data;

    	// tranversing
    	cur = head;
    	int nomor = 1;
    	while( nomor <  posisi - 1){
    		cur = cur->next;
        	nomor++;
      	}

    	afterNode = cur->next;
    	newNode->prev = cur;
    	newNode->next = afterNode;
    	cur->next = newNode;
    	afterNode->prev = newNode;
    }
  }
}

// Remove First atau Delet First
void removeFirst(){
	if (head == NULL){
    	cout << "Double Linked List belum dibuat!";
	}else{
		del = head;
    	head = head->next;
    	head->prev = NULL;
    	delete del;
	}
}

// Remove Last atau Delete Last
void removeLast(){
	if (head == NULL){
		cout << "Double Linked List belum dibuat!";
	}else{
    	del = tail;
    	tail = tail->prev;
    	tail->next = NULL;
    	delete del;
	}
}

// Remove Middle
void removeMiddle(int posisi){
	if (head == NULL){
		cout << "Double Linked List belum dibuat!";
  }else{
    if (posisi == 1 || posisi == countDoubleLinkedList()){
    	cout << "Posisi bukan posisi tegah!" << endl;
    }else if (posisi < 1 || posisi > countDoubleLinkedList()){
    	cout << "Posisi diluar jangkauan!" << endl;
    }else{
    	int nomor = 1;
    	cur = head;
		while(nomor < posisi - 1){
        	cur = cur->next;
        	nomor++;
    	}
    	del = cur->next;
    	afterNode = del->next;
    	cur->next = afterNode;
    	afterNode->prev = cur;
    	delete del;
    }
  }
}

// Print Double Linked List
void printDoubleLinkedList()
{
	if (head == NULL){
    	cout << "Double Linked List belum dibuat!";
	}else{
    	cout << "Jumlah Data : " << countDoubleLinkedList() << endl;
    	cout << "INFO DATA" << endl;
    	cur = head;
    while (cur != NULL){
    	// print
    	cout << "Data : " << cur->data << endl;
    	//step
    	cur = cur->next;
    }
  }
}

// searching (sequential)
void searchNode(node **head, int id){
    int currentID = 1;
    node *cur = *head;
    while (cur->next != 0 && currentID != id){
        cur = cur->next;
        currentID++;
    }
    cout << cur->data << " ditemukan pada data ke " << currentID;
}

int main(){
	cout << "Membuat Data Double Linked List" << endl;
	int newData = 1;
	createDoubleLinkedList(newData);
	printDoubleLinkedList();
	
	cout << "\nInsert First" << endl;
	int data2 = 9;
	addFirst(data2);
	printDoubleLinkedList();
	
	cout << "\nInsert Last" << endl;
	int data3 = 20;
	addLast(data3);
	printDoubleLinkedList();
	
	cout << "\nDelete First" << endl;
	removeFirst();
	printDoubleLinkedList();
	
	int data4 = 14;
	cout << "\nInsert Last" << endl;
	addLast(data4);
	printDoubleLinkedList();
	
	cout << "\nDelete Last" << endl;
	removeLast();
	printDoubleLinkedList();
	
	cout << "\nInsert Before" << endl;
	int data5 = 27;
	addMiddle(data5, 2);
	printDoubleLinkedList();
	
	cout << "\nDelete Before data ke 3" << endl;
	removeMiddle(2);
	printDoubleLinkedList();
	
	cout << "\nSearching data : 20" << endl;  
	searchNode(&head, 2);
}
