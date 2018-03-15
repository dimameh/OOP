#include "stdafx.h"
#include "Lab4Functions.h"
using namespace std;


//Добавить запись в конец списка
void Add(Person& person, Node *&head, Node *&tail)
{
	if (head == NULL)
	{
		tail = head = new Node(person);
	}
	else
	{
		Node* newNode = new Node(person);
		tail->next = newNode;
		newNode->prev = tail;
		head->prev = newNode;
		newNode->next = NULL;
		tail = newNode;
	}
}
//Вывод содержимого списка
void Show(Node *head)
{
	if (head == NULL)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(4));
		cout << "List is empty!";
	}
	else
	{
		int count = 0;
		Node * pick = head;
		while (pick != NULL)
		{
			cout << endl << "----------------------------------" << count << endl;
			PrintPerson(pick->data);
			cout << endl << "----------------------------------" << endl;
			pick = pick->next;
			count++;
		}
	}
}
//Получение данных узла по его индексу
Person *Get(int index, Node *&head, Node *&tail)
{
	if (index < 0) 
	{
		cout << "There is no element with this index";
		return NULL;
	}
	Node * pick = head;
	int count = 0;
	while (pick != NULL)
	{
		if (count == index)
		{
			Person* returning = new Person;
			returning = &pick->data;
			return returning;
		}
		count++;
		pick = pick->next;
	}
	cout << "There is no such element";
	return NULL;
}
//Удаление узла по индексу
void Remove(int index, Node *&head, Node *&tail)
{
	if (index == 0)
	{
		if (head != NULL)
		{
			Node * temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;
		}
	}
	else
	{
		Node * pick = head;
		int count = 0;
		while (pick != NULL)
		{
			if (count == index)
			{
				if (pick == tail)
				{
					if (head != NULL)
					{
						Node * temp = tail;
						tail = tail->prev;
						tail->next = NULL;
						delete temp;
						break;
					}
				}
				else {
					Node * temp = pick;
					pick->prev->next = pick->next;
					pick->next->prev = pick->prev;
					delete temp;
					break;
				}
			}
			else
			{
				count++;
				pick = pick->next;
			}
		}
	}
}
//Добавить запись на выбранный индекс
void Insert(Person& person, int index, Node *&head, Node *&tail)
{
	if (index == 0)
	{
		if (head == NULL)
		{
			head = tail = new Node(person);
		}
		else
		{
			Node * temp = new Node(person);
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
	}
	else
	{
		Node * pick = head;
		int count = 0;
		while (pick != NULL)
		{
			if (count == index - 1)
			{
				if (pick->next == NULL)
				{
					if (head == NULL)
					{
						head = tail = new Node(person);
					}
					else
					{
						Node * temp = new Node(person);
						tail->next = temp;
						temp->prev = tail;
						tail = temp;
						tail->prev = temp->prev;
					}
				}
				else
				{
					Node * temp = new Node(person);
					temp->next = pick->next;
					temp->prev = pick;
					pick->next = temp;
					temp->next->prev = temp;
					break;
				}
			}
			count++;
			pick = pick->next;
		}
	}
}
//Очистить список
void Clear(Node *&head, Node *&tail)
{
	while (head) //Пока по адресу на начало списка что-то есть
	{
		tail = head->next;
		delete head;
		head = tail;
	}
}
//Задать случайные параметры для объекта структуры Person
Person& MakeRandomPerson()
{
	Person randomPerson;
	char names[15][20] = 
	{
		"Sophia",
		"Alvina" ,
		"Arina" ,
		"Amira" ,
		"Alice" ,
		"Safine" ,
		"Liza" ,
		"Leonard" ,
		"Condratiy" ,
		"Felix" ,
		"Victor" ,
		"Rodion" ,
		"Daniil" ,
		"August" ,
		"Antuan" 
	};
	char surnames[15][40] =
	{
		"Cvetkova",
		"Cononova" ,
		"Belousva" ,
		"Voronova" ,
		"Emelyanova" ,
		"Bespalova" ,
		"Novikova" ,
		"Tretyakov" ,
		"Miheev" ,
		"Terentyev" ,
		"Pavlov" ,
		"Maslov" ,
		"Solovyov" ,
		"Bobylyov" ,
		"Grobovozov"
	};
	char patronymics[15][25] =
	{
		"Ivanovna",
		"Antoninovna" ,
		"Serpantinovna" ,
		"Petrovna" ,
		"Maximovna" ,
		"Evseevna" ,
		"Artemovna" ,
		"Agafonovich" ,
		"Mihailovich" ,
		"Germanovich" ,
		"Vladimirovich" ,
		"Aristarkhovich" ,
		"Glebovich" ,
		"Melsovich" ,
		"Borisovich"
	};

	

	randomPerson.Sex = static_cast<Gender>(rand() % 3);
	
	if (randomPerson.Sex == Male)
	{
		int randomNumber = rand() % (14 - 7 + 1) + 7;
		CopyString(randomPerson.Name, names[randomNumber]);

		randomNumber = rand() % (14 - 7 + 1) + 7;
		CopyString(randomPerson.Surname, surnames[randomNumber]);

		randomNumber = rand() % (14 - 7 + 1) + 7;
		CopyString(randomPerson.Patronymic, patronymics[randomNumber]);
	}
	else
	{
		if (randomPerson.Sex == Female)
		{
			int randomNumber = rand() % 7;
			CopyString(randomPerson.Name, names[randomNumber]);

			randomNumber = rand() % 7;
			CopyString(randomPerson.Surname, surnames[randomNumber]);

			randomNumber = rand() % 7;
			CopyString(randomPerson.Patronymic, patronymics[randomNumber]);
		}
		else
		{
			int randomNumber = rand() % 15;
			CopyString(randomPerson.Name, names[randomNumber]);
			
			randomNumber = rand() % 15;
			CopyString(randomPerson.Surname, surnames[randomNumber]);
			
			randomNumber = rand() % 15;
			CopyString(randomPerson.Patronymic, patronymics[randomNumber]);
		}
	}
	
	randomPerson.Age = rand() % 120;

	return randomPerson;
}