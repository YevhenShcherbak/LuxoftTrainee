#include <iostream>

template<typename Item>
class List
{
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
	void clear();
	void show();
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
	clear();
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

template<typename Item>
void List<Item>::pop_forward()
{
	if (GetSize() == 0)
	{
		std::cout << "List is empty" << std::endl;
	}
	else 
	{
		Node<Item>* temp = head;
		head = head->pNext;
		delete temp;
		--size;
	}
}

template<typename Item>
void List<Item>::pop_back()
{
	if (GetSize() == 0)
	{
		std::cout << "List is empty" << std::endl;
	}
	else 
	{
		Node<Item>* current = this->head;
		while (current != nullptr)
		{
			current = current->pNext;
		}
		delete current;
		
		--size;
	}
}

template<typename Item>
void List<Item>::removeAt(const int index)
{
	if (index == 0)
	{
		pop_forward();
	}
	else
	{
		Node<Item>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<Item>* toDel = previous->pNext;
		previous->pNext = toDel->pNext;
		delete toDel;
		--size;
	}
}

template<typename Item>
void List<Item>::clear()
{
	while (size) 
	{
		pop_forward();
	}
}

template<typename Item>
void List<Item>::show()
{
	Node<Item>* current = this->head;
	while (current != nullptr)
	{
		std::cout << current->value << ' ';
		current = current->pNext;
	}
	std::cout << std::endl;
}

int main()
{
	std::string temp;
	List<int> list1;
	list1.push_forward(5);
	list1.push_back(10);
	list1.push_back(11);
	list1.push_forward(4);
	list1.show();

	list1.removeAt(3);
	list1.show();

	std::cin >> temp;

	return 0;
}