template <class T>
class Stack
{
private:
	T* data;
	int size;
	int head;
public:
	Stack();
	~Stack();

	void push(T value);
	T pop();

	bool empty();
	int getSize();
};

template <class T>
Stack<T>::Stack()
{
	head = 0;
	size = 2;
	data = new T[size];
}

template <class T>
Stack<T>::~Stack() { delete [] data; }

template <class T>
void Stack<T>::push(T value)
{
	data[head++] = value;
	if(head == size)
	{
		size = size*2;
		T* temp = data;
		data = new T[size];
		for(int i = 0; i < size/2; i++)
			data[i] = temp[i];
		delete [] temp;
	}
}

template <class T>
T Stack<T>::pop() { return data[--head]; }

template <class T>
bool Stack<T>::empty() { return head == 0; }

template <class T>
int Stack<T>::getSize() { return head; }