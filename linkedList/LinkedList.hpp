/**
*	@author Hans Brown & John Gibbons
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	//assume m_size is accurate record of size
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	if(m_front == nullptr) //if nothing to begin with, can't find it
		return false;
	else //m_front != nullptr, there is a first element
	{
		Node<T>* temp = m_front; //start at first element
		while(temp != nullptr) //run until we run out of elements in the list
		{
			if(temp.getValue() == value) //check current element against "value"
				return true;
			else
			{
				temp = temp.getNext(); //go to next element in list
			}
		}
		//break the while loop when we run out of elements
	}
	//somehow reaching this point, we can assume we did not find the element
	return false;
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	//if(!isEmpty()) //m_front exists
	//{
		//if(m_front.getNext() != nullptr) //if there are at least 2 elements
		//{
			//secondintoLast = m_front;
			//lastNode = m_front.getNext();
		//}
		//else //if there is 1 element
			//return this.removeFront(); //already implemented method
	//}
	//else //otw, no elements, so we can't remove anything
	//{
		//return false;
	//}

	/** TODO 
		Fix this method
	*/



	//TODO: find position before (secondintoLast) that its next-next points to nullptr,
	//the second's next is the last
	//delete the last, stop second pointing to it,
	//decrease size

	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
