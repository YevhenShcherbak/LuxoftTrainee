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
void showList(List<Item> list) {
	for (int i = 0; i < list.GetSize(); i++)
	{
		std::cout << list[i] << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	List<int> list1;
	list1.push_forward(5);
	list1.push_back(10);
	list1.push_back(11);
	list1.push_forward(4);
	showList(list1);
	//std::cout << list1.GetSize() << std::endl;

	list1.pop_back();
	list1.pop_back();
	showList(list1);
	list1.pop_back();
	list1.pop_back();
	list1.pop_back();
	showList(list1);
	//std::cout << list1.GetSize() << std::endl;

	return 0;
}