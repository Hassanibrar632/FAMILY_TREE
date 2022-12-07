#include <iostream>
#include <fstream>

using namespace std;

struct Node;
struct child{
	Node* kid;
	child* Next;
	
	
	child(){
		kid = NULL;
		Next = NULL;
	}
};

struct Node{
	string Name;
	child *kids;
	
	Node(){
		kids = NULL;
	}
	
	void Add_Child(string Name){
		if(kids == NULL){
			kids = new child;
			this->kids->kid = new Node;
			this->kids->kid->Name = Name;
			return;
		}else{
			child *Temp = this->kids;
			while(Temp->Next != NULL){
				Temp = Temp->Next;
			}
			Temp->Next = new child;
			Temp->Next->kid = new Node;
			Temp->Next->kid->Name = Name;
		}
	}
};

Node *Tree = NULL;
	
	void FIRST(string A){
		Tree = new Node;
		Tree->Name = A;
	}
	
	bool FIND(Node *Temp, string A, string B){
		if(Temp->Name == A){
			Temp->Add_Child(B);
			Temp->Name = A;
			return true;
		}
		if(Temp->kids == NULL)
			return false;
		
		bool flag = false;	
		child* temp = Temp->kids;
		while(temp != NULL && flag == false){
			flag = FIND(temp->kid, A, B);
			temp = temp->Next;
		}
		return flag;
	}
	
	void get_input(){
		string A, B;
		cout << "Enter Head name: ";
		cin >> A;
		FIRST(A);
		cout << "TO exit enter q or Q\n";
		system("pause");
		system("cls");
		do{
			cout << "Enter Parent Name: ";
			cin >> A;
			if(A == "q" || A == "Q")
				break;
			cout << "Enter Child Name: ";
			cin >> B;
			if(B == "q" || B == "Q")
				break;
			FIND(Tree, A, B);
		}while(true);
	}
	
	void PRE_ORDER(Node* Temp){
		cout << Temp->Name << " ";
		child* temp = Temp->kids;
		while(temp != NULL){
			PRE_ORDER(temp->kid);
			temp = temp->Next;
		}
	}

	void POST_ORDER(Node* Temp){
		child* temp = Temp->kids;
		while(temp != NULL){
			PRE_ORDER(temp->kid);
			temp = temp->Next;
		}
		cout << Temp->Name << " ";
	}
	
	void temp_main(){
		cout << ".................................................\n";
		cout << "ENTERING DATA:\n";
		get_input();			//input from USER
		cout << "DONE.\n";
		cout << ".................................................\n";
		system("pause");
		system("cls");
		cout << ".................................................\n";
		cout << "PRE_ORDER: ";
		PRE_ORDER(Tree);
		cout << "\n\n\nPOST_ORDER: ";
		POST_ORDER(Tree);
		cout << "\n.................................................\n";
	}

int main(){
	temp_main();
}
