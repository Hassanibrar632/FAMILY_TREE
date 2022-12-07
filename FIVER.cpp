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
		fstream file;
		string A, B;
		int flag = 1, start = 1;
		cout << "Enter filename: ";
		cin >> A;
		file.open(A.c_str());
		while(file >> A){
			if(start == 1){
				FIRST(A);
				start = 0;
				continue;
			}
			if(flag ==  1){
				flag = 0;
				B = A;
			}else{
				FIND(Tree, B, A);
				flag = 1;
			}
		}
		file.close();
	}
	
	void DISPLAY(Node* Temp){
		cout << Temp->Name << ": ";
		child* temp = Temp->kids;
		while(temp != NULL){
			cout << temp->kid->Name << " ";
			temp = temp->Next;
		}
		cout << endl;
		temp = Temp->kids;
		while(temp != NULL){
			DISPLAY(temp->kid);
			temp = temp->Next;
		}
		
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
	
	bool Node_Get(Node* Temp, string A){
		if(Temp->Name == A){
			DISPLAY(Temp);
			return true;
		}
		if(Temp->kids == NULL)
			return false;
		
		bool flag = false;	
		child* temp = Temp->kids;
		while(temp != NULL && flag == false){
			flag = Node_Get(temp->kid, A);
			temp = temp->Next;
		}
		return flag;
	}
	
	void Bonus_Part_1(){
		cout << "Enter the Name of the Node: ";
		string A;
		cin >> A;
		Node_Get(Tree, A);
	}
	
	void temp_main(){
		cout << ".................................................\n";
		cout << "ENTERING DATA:\n";
		get_input();			//input from files bonus question part 2
		cout << "DONE.\n";
		cout << ".................................................\n";
		system("pause");
		system("cls");
		cout << ".................................................\n";
		cout << "DISPLAYING DATA IN TREE\t(SYNTAX) PARENT: CHILDS\n";
		DISPLAY(Tree);			//display tree
		cout << ".................................................\n";
		system("pause");
		system("cls");
		cout << ".................................................\n";
		cout << "BOUNS PART 2 SEARCHING NODE AND DISPLAYING ITS DECENDENTS:\n";
		Bonus_Part_1();			//Bonus question part 1
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
