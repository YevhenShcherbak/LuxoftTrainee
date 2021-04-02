#include <iostream>

template<typename Item>
class List
{
public:
	List();
	~List();
	const int GetSize() { return size; }
	Item& operator[](const int index);
	void push_back(Item value);
	void push_forward(Item value);
	void pop_forward();
	void pop_back();
	void removeAt(const int index);
private:
	template<typename Item>
	class Node
	{
	public:
		Node<Item>* pNext;
		Item value;
		
		Node(Item value = Item(), Node<Item>* pNext = nullptr)
		{
			this->value = value;
			this->pNext = pNext;
		}
	};
	Node<Item>* head;
	int size;

};

template<typename Item>
List<Item>::List()
{
	size = 0;
	head = nullptr;
}

template<typename Item>
List<Item>::~List()
{
}

template<typename Item>
Item& List<Item>::operator[](const int index)
{
	Node<Item>* current = this->head;
	int counter = 0;
	
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->value;
		}
		current = current->pNext;
		++counter;
	}
}

template<typename Item>
void List<Item>::push_back(Item value)
{
	if (head == nullptr)
	{
		head = new Node<Item>(value);
	}
	else
	{
		Node<Item>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<Item>(value);
	}
	++size;
}

template<typename Item>
void List<Item>::push_forward(Item value)
{
	head = new Node<Item>(value, head);
	++size;
}

int main()
{
	List<int> list1;
	list1.push_forward(5);
	list1.push_back(10);
	list1.push_back(11);
	list1.push_forward(4);
	
	for (int i = 0; i < list1.GetSize(); i++)
	{
		std::cout << list1[i] << std::endl;
	}
	

	return 0;
}