// Queue class:
template <class T>
class Queue
{
private:
	T* data;
	int size;
	int head;
	int tail;
public:
	Queue();
	~Queue();

	void push(T value);
	T pop();

	bool empty();
	int getSize();
};


// Queue Methods:

// Initializes values
template <class T>
Queue<T>::Queue()
{
	head = tail = 0;
	size = 2;
	data = new T[size];
}

// Deallocates memory
template <class T>
Queue<T>::~Queue() { delete [] data; }

// Pushes a value into the Queue and allocates more memory if needed
template <class T>
void Queue<T>::push(T value)
{
	if(getSize() == size-1)
	{
		size *= 2;
		T* temp = data;
		data = new T[size];
		for(int i = 0; i < size/2; i++)
		{
			data[i] = temp[head++];
			head %= size;
		}
		head = 0;
		tail = (size/2)-1;
		delete [] temp;
	}
	data[tail++] = value;
	tail %= size;
}

// Returns the oldest value in the Queue
template <class T>
T Queue<T>::pop() 
{ 
	T ret = data[head++];
	head %= size;
	return ret;
}

// Returns whether or not the Queue is empty
template <class T>
bool Queue<T>::empty() { return head == tail; }

// Returns how many objects are in the Queue
template <class T>
int Queue<T>::getSize() { return (tail >= head) ? tail-head : (tail-head)+size; }


