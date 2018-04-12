#pragma once
//������ � ������� ��������� Person

template <typename DataType>
class List
{
private:
	struct ListNode
	{
		DataType* _data;			// ���� ������
		ListNode* next;				// ��������� �� ��������� �������
		ListNode(DataType* data)	// �����������
		{
			_data = data;
			next = NULL;
		}
	} *_head;	//��������� �� ������ ������
	int _count;			//���������� ��������� � ������
public:
	//����������� ������
	List();
	//�������� ���������� ���������
	int GetCount();
	//�������� �������� � ������
	void Add(DataType* data);
	//����� �������� �� ���������� �������
	DataType* Find(int index);
	//������� ������ ��������, ���� �� ���� � ������
	int IndexOf(DataType* data);
	//������� �������� �� ������
	void Remove(DataType* data);
	//������� �������� �� ������ �� �������
	void RemoveAt(int index);
	//�������� ������
	void Clear();
	//����� ��������� ������
	void PrintList();
	//����� ��������� ������ � ���������� �������
	void PrintList(DataType data);
	//����� �������� ���� ��������� ������
	void DescribeList();
};