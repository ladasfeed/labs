#include <iostream>
using namespace std;

struct node
{
	int index = -1;
	int data;
	node* next;
	node* up;
	node* down;
};
class Linked
{
private:
	node* head;
	node* tail;
	int size;

public:
	Linked();
	~Linked();
	void Add(int data);
	void Print();
	void Index();
	void Inter(int* N, int* Colums);
	void ClearIndex();
	void PrintOut();
	void printUp();
};

Linked::Linked()
{
	head = NULL;
	tail = NULL;
	size = 0;
};
Linked::~Linked()
{};
void Linked::Add(int data)
{
	node* temp = new node;
	temp->down = NULL;
	temp->up = NULL;

	temp->data = data;
	temp->next = NULL;
	if (head != NULL)
	{
		tail->next = temp;
		tail = temp;
	}
	else
	{
		head = temp;
		tail = temp;
	}
}
void Linked::Print()
{
	node* temp = head;
	while (temp != 0)
	{
		cout << temp->data << " " << temp->index << " " << temp->up << " ";
		if (temp->up != NULL) cout << temp->up->data << " ";
		cout << temp->down << " ";
		if (temp->down != NULL) cout << temp->down->data;
		cout << endl;

		temp = temp->next;


	}
}




void Linked::Index() {
	node* temp = head;
	int i = 1;
	while (temp != 0)
	{
		if (temp->down == nullptr) {
			temp->index = i;
			i++;
		}
		temp = temp->next;
	}
}


void Linked::Inter(int* N, int* Colums) {
	//1
	node* temp = head;
	node* tempo = NULL;


	int i = 1;
	int TempCount = 1;
	int TempCountEnd = *N;

	while (temp != 0)
	{
		node* Another = temp;
		if (temp->index != -1) {
			cout << "q" << temp->data << endl;
			if (i > * N / 2) break;
			i++;
			

			
			for (int j = 1; j <= *Colums; j++) {

				cout << temp->up << " " << temp->down << endl;


				tempo = temp->up;
				cout << "a";
				cout << endl << tempo << endl;
				temp->up = temp->down;
				temp->down = tempo;



				cout << temp->up << " " << temp->down << endl;
				if (temp->down != NULL)
					temp = temp->down;



			}

			cout << "w" << temp->data << endl;
			
			node* forChange = head;
			while (forChange != 0) {

				if (forChange->index == TempCountEnd) {
					cout << "find:" << forChange->data << " TCE: " << TempCountEnd << endl;
					while (forChange->up != NULL) {
						forChange = forChange->up;
					}
					cout << "upperIs:" << forChange->data << endl;
					cout << "Change: " << temp->data;



					forChange->up = temp;
					temp->down = forChange;
					TempCountEnd--;
					cout << "TCE" << TempCountEnd << endl;
					break;
				}

				forChange = forChange->next;

			}


		}
		temp = Another;
		temp = temp->next;
	}
	ClearIndex();
	Index();


	*N = *N / 2;
	(*Colums) = (*Colums) * 2;
}

void Linked::ClearIndex() {
	node* temp = head;
	int i = 0;
	while (temp != 0)
	{
		temp->index = -1;
		temp = temp->next;
	}
}

void Linked::PrintOut() {
	node* kek = head;

	while (kek->down != NULL) {
		kek = kek->next;

	}

	int i = 1;
	while (kek != NULL) {
		kek->data = i;
		i++;
		kek = kek->up;
	}





}

void Linked::printUp() {
	node* kek = head;

	while (kek != NULL) {
		cout << kek->data << " ";
		kek = kek->next;
	}
	cout << endl;
	kek = head;


	while (kek->down != NULL) {
		kek = kek->next;


	}
	

	while (kek != NULL) {
		cout << kek->data << " ";
		kek = kek->up;
	
	}
	cout << endl;


}






int main() {
	int Count;
	cin >> Count;
	Linked list;

	for (int i = 1; i <= Count; i++)
		list.Add(i);

	int N = Count;
	int Half = N;
	int Colums = 1;

	list.Index();

	while (N!=1) {
		list.Inter(&N, &Colums);
		list.Print();
	}
	list.PrintOut();
	list.printUp();

	
	

	
	
	


	
	
	
	
	

	
	




	return 0;
}