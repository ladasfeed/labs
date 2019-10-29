#include <iostream>

using namespace std;

struct node {
	node* next;
	node* last;
	int data;

};


class List {
private:
	node* head;
	node* MainTemp;
	int size;

public:
	List() 
	{
		head = NULL;
		size = 0;
	};

	void Add(node* upper);
	void Add(int I);
	void MainFunc(int M);
	void Final(int N, int M);
	void Print(int N);


};


void List::Add(node* upper) {
	node* temp = new node;
	node* down = upper->last;
	temp->next = upper;
	upper->last = temp;

	down->next = temp;
	temp->last = down;

	temp->data = 0;

	MainTemp = temp;
	
}

void List::Add(int I) {
	node* temp = new node;
	temp->last = temp;
	temp->next = temp;
	temp->data = I;

	MainTemp = temp;
}


void List::MainFunc(int M) {

	for (int i = 1; i < M; i++) {
		MainTemp = MainTemp->last;
	}

	Add(MainTemp);

}

void List::Final(int N, int M) {

	for (int i = 1; i < M; i++) {
		MainTemp = MainTemp->last;
	}

	node* temp = MainTemp;
	int Index = 0;
	while (temp->data == 0) {
		temp = temp->next;
	}
	Index = temp->data;
	temp = temp->next;

	int localTemp = Index-1;
	int Flag = 0;
	while (temp->data != Index) {


		if (localTemp == 0) {
			localTemp = N;
		}
		
			temp->data = localTemp;
			localTemp--;



		temp = temp->next;
		

	}

	cout << MainTemp->data << endl;
	
}

void List::Print(int N) {
	node* temp = MainTemp;
	for (int i = 0; i < N; i++) {
		cout << temp->data;
		temp = temp->next;
	}
	
}


int main()
{
	int M, I, N;
	cin >> I;
	List list;
	list.Add(I);

	

	cin >> N;
	cin >> M;

	cout << "kk";
	

	for (int i = 1; i < N; i++) {
		list.MainFunc(M);
	}
	
	list.Final(N, M);
	list.Print(N);

}

