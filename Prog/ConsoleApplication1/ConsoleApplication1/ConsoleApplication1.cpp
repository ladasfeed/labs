#include <iostream>
using namespace std;

struct node
{
	int index=-1;
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
		cout << temp->data << " " << temp->index << " " << temp->up << " " << temp->down << endl;
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
		if (temp->index!=-1) {
			if (i > *N/2) break;
			i++;
			
			

			for (int j = 1; j <= *Colums; j++) {

				cout << temp->up << " " << temp->down << endl;


				tempo = temp->up;
				cout << "a";
				cout << endl << tempo << endl;
				temp->up = temp->down;
				temp->down = tempo;
				


				cout << temp->up << " " << temp->down << endl;
				if (temp->down!=NULL)
				temp = temp->down;

				
			
			}
			

			
			node* forChange=head;
			while (forChange!=0) {
				
				if (forChange->index==TempCountEnd) {
					while (forChange->up != NULL) {
						forChange = forChange->up;
					}





					forChange->up = temp;
					temp->down = forChange;
					TempCountEnd--;
					
					break;
				}

				forChange = forChange->next;
				//if (forChange != NULL) cout << 1;
				//else cout << 2;
			}

			temp = temp->next;
		}

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

	list.Inter(&N, &Colums);
	list.Print();
	cout << N;

	list.Inter(&N, &Colums);
	cout << endl;
	list.Print();
	cout << N;

	list.Inter(&N, &Colums);
	cout << endl;
	list.Print();

	
	return 0;
}