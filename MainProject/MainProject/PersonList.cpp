#include "stdafx.h"
#include "PersonList.h"
using namespace std;

//ƒобавить запись в конец списка
void Add(Person& person, PersonList *&list)
{
	Insert(person, list->length, list);
}
//¬ывод содержимого списка
void Show(PersonList *&list)
{
	if (list->head == NULL)
	{
		//раскраска вывода в консоль в красный
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(4));
		cout << "List is empty!";
	}
	else
	{
		int count = 0;
		ListNode * index = list->head;
		while (index != NULL)
		{
			cout << endl << "----------------------------------" << count << endl;
			PrintPerson(index->data);
			cout << endl << "----------------------------------" << endl;
			index = index->next;
			count++;
		}
	}
}
//ѕолучение данных узла по его индексу
Person *Get(int index, PersonList *&list)
{
	if (index < 0) 
	{
		return NULL;
	}
	ListNode * nodeIndex = list->head;
	int count = 0;
	while (nodeIndex != NULL)
	{
		if (count == index)
		{
			Person* returning = new Person;
			returning = &nodeIndex->data;
			return returning;
		}
		count++;
		nodeIndex = nodeIndex->next;
	}
	return NULL;
}
//”даление узла по индексу
void Remove(int index, PersonList *&list)
{

	//проверка индекса
	if (index < 0 || index > list->length-1)
	{
		exception indexExeption("The index is not in range.");
		throw indexExeption;
	}		
	//если список пустой
	if (list->head == NULL)
	{
		exception emptyExeption("The list is empty.");
		throw emptyExeption;
	}
	//удаление первого элемента
	if (index == 0)
	{
		if (list->head->next == NULL)
		{
			delete list->head;
			list->head = NULL;
		}
		else
		{
			list->head = list->head->next;
			delete list->head->prev;
			list->head->prev = NULL;
		}
	}
	//удаление последнего элемента
	else
	{
		if (index == list->length - 1)
		{
			list->tail = list->tail->prev;
			delete list->tail->next;
			list->tail->next = NULL;
		}
	}
	//удаление из центра
	if (index > 0 && index < list->length - 1)
	{	
		ListNode * nodeIndex = list->head;
		int count = 0;
		//поиск элемента с нужным индексом
		while (nodeIndex != NULL)
		{
			if (count == index)
			{
				break;
			}
			count++;
			nodeIndex = nodeIndex->next;
		}
		nodeIndex->next->prev = nodeIndex->prev;
		nodeIndex->prev->next = nodeIndex->next;
		delete nodeIndex;
	}
	list->length--;
}
//ƒобавить запись на выбранный индекс
void Insert(Person& person, int index, PersonList *&list)
{
	//проверка индекса
	if (!(index >= 0 || index <= list->length))
	{
		exception indexExeption ("The index is not in range.");
		throw indexExeption;
	}
	//вставка в начало
	if (index == 0)
	{
		//если список пустой
		if (list->head == NULL)
		{
			list->head = list->tail = new ListNode(person);
		}
		//если в списке уже есть элементы
		else
		{
			ListNode * temp = new ListNode(person);
			list->head->prev = temp;
			temp->next = list->head;
			list->head = temp;
		}
	}
	else
	{
		//вставка в конец
		if (index == list->length)
		{
			ListNode * temp = new ListNode(person);
			list->tail->next = temp;
			temp->prev = list->tail;
			list->tail = temp;
		}
		//вставка между элементами
		if (index > 0 && index < list->length)
		{
			ListNode * nodeIndex = list->head;
			int count = 0;

			//поиск элемента с нужным индексом
			while (nodeIndex != NULL)
			{
				if (count == index)
				{
					break;
				}
				count++;
				nodeIndex = nodeIndex->next;
			}

			ListNode * temp = new ListNode(person);
			temp->next = nodeIndex;
			temp->prev = nodeIndex->prev;
			nodeIndex->prev->next = temp;
			nodeIndex->prev = temp;
		}
	}
	list->length++;
}
//ќчистить список
void Clear(PersonList *&list)
{
	while (list->head) //ѕока по адресу на начало списка что-то есть
	{
		list->tail = list->head->next;
		delete list->head;
		list->head = list->tail;
	}
	list->length = 0;
}
//«адать случайные параметры дл€ объекта структуры Person
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
	const int maleMinIndex = 8, maleIndexAmount = 7, femaleMaxIndex = 7, indexAmount = 15;
	randomPerson.Sex = static_cast<Gender>(rand() % 3);
	
	if (randomPerson.Sex == Male)
	{
		int randomNumber = rand() % (maleMinIndex) +maleIndexAmount;
		CopyString(randomPerson.Name, names[randomNumber]);

		randomNumber = rand() % (maleMinIndex) +maleIndexAmount;
		CopyString(randomPerson.Surname, surnames[randomNumber]);

		randomNumber = rand() % (maleMinIndex) +maleIndexAmount;
		CopyString(randomPerson.Patronymic, patronymics[randomNumber]);
	}
	else
	{
		if (randomPerson.Sex == Female)
		{
			int randomNumber = rand() % femaleMaxIndex;
			CopyString(randomPerson.Name, names[randomNumber]);

			randomNumber = rand() % femaleMaxIndex;
			CopyString(randomPerson.Surname, surnames[randomNumber]);

			randomNumber = rand() % femaleMaxIndex;
			CopyString(randomPerson.Patronymic, patronymics[randomNumber]);
		}
		else
		{
			int randomNumber = rand() % indexAmount;
			CopyString(randomPerson.Name, names[randomNumber]);
			
			randomNumber = rand() % indexAmount;
			CopyString(randomPerson.Surname, surnames[randomNumber]);
			
			randomNumber = rand() % indexAmount;
			CopyString(randomPerson.Patronymic, patronymics[randomNumber]);
		}
	}
	
	randomPerson.Age = rand() % 120;

	return randomPerson;
}
//¬озвращает количество элементов списка
int GetCount(PersonList *&list)
{
	return list->length;
}