//Doubly Linked link
template<typename E> class DLNode
{
public:
	E elment;
	DLNode* prev_next;
	DLNode(E x, DLNode* obj = nullptr)
	{
		elment = x;
		prev_next = obj;
	}
	DLNode(DLNode* obj = nullptr)
	{
		prev_next = obj;
	}
};

template<typename E> class DLLink
{
private:
	int length; //当前链表的长度
	DLNode<E>* curr; //当前位置
	DLNode<E>* head;
	DLNode<E>* tail;
public:
	//初始化链表
	void init()
	{
		head = curr = tail = new DLNode<E>();
		length = 0;
	}
	DLNode<E>* findPrev(DLNode<E>* obj)
	{
		//找到curr的前驱结点
		DLNode<E>*obj_prev = nullptr;
		if (obj == head)
		{
			obj_prev = nullptr;
		}
		else
		{
			DLNode<E>*temp_curr = head;
			DLNode<E>*temp_next = xorPointer(head->prev_next, nullptr);
			while (temp_next != obj)
			{
				DLNode<E>*temp = temp_next;
				temp_next = xorPointer(temp_curr, temp_next->prev_next);
				temp_curr = temp;
			}
			obj_prev = temp_curr;
		}
		return obj_prev;
	}
	DLLink()
	{
		init();
	}
	DLNode<E>* xorPointer(DLNode<E>* a, DLNode<E>* b)
	{
		unsigned long x, y, z;
		x = (unsigned long)a;
		y = (unsigned long)b;
		z = x^y;
		return (DLNode<E>*) z;
	}
	//清空链表
	void clear()
	{
		DLNode<E>*temp_curr = head;
		DLNode<E>*temp_next = xorPointer(head->prev_next, nullptr);
		while (temp_next != nullptr)
		{
			DLNode<E>*temp_delete = temp_curr;
			DLNode<E>*temp = temp_next;
			temp_next = xorPointer(temp_curr, temp_next->prev_next);
			temp_curr = temp;
			delete temp_delete;
		}
		delete tail;
		init();
	}
	//插入元素
	void insert(E x)
	{
		//若链表内没有元素，相当于在队尾添加元素
		if (length == 0)
		{
			append(x);
			return;
		}
		//找到curr的前驱结点
		DLNode<E>*curr_prev = findPrev(curr);
		//获得curr的后驱结点
		DLNode<E>*curr_next = xorPointer(curr_prev, curr->prev_next);
		//构造当前插入的结点
		DLNode<E>*temp = new DLNode<E>(x, xorPointer(curr, curr_next));
		//重新给curr和curr的后驱结点赋值
		curr_next->prev_next = xorPointer(temp, xorPointer(curr_next->prev_next, curr));
		curr->prev_next = xorPointer(curr_prev, temp);
		//如果curr指向尾结点，需要重新赋值tail
		if (tail == curr)
			tail = temp;
		length++;
	}
	//添加到链表尾
	void append(E x)
	{
		//新添加的结点的前驱结点为此刻的尾结点，后驱结点为空
		DLNode<E>*temp = new DLNode<E>(x, xorPointer(tail, nullptr));
		//尾结点的后驱结点为空
		tail->prev_next = xorPointer(xorPointer(tail->prev_next, nullptr), temp);
		tail = temp;
		length++;
	}
	//移除元素
	int remove()
	{
		if (curr == tail)
			return -1;
		//找到curr的前驱结点
		DLNode<E>*curr_prev = findPrev(curr);
		//获得curr的后驱结点
		DLNode<E>*curr_next = xorPointer(curr_prev, curr->prev_next);
		//获得curr_next的后驱结点
		DLNode<E>*curr_next_next = xorPointer(curr, curr_next->prev_next);
		int temp1 = curr_next->elment;
		if (tail == curr_next)
		{
			tail = curr;
			delete curr_next;
			length--;
			return temp1;
		}
		//重新给curr和curr_next赋值
		curr->prev_next = xorPointer(curr_prev,curr_next_next);
		curr_next_next->prev_next = xorPointer(curr, xorPointer(curr_next, curr_next_next->prev_next));
		delete curr_next;
		length--;
		return temp1;
	}
	//表指针移动到尾部
	void moveToEnd()
	{
		curr = tail;
	}
	//表指针移动到头部
	void moveToStart()
	{
		curr = head;
	}
	//表指针移前一位
	void prev()
	{
		if (curr == head)
			return;
		//找到curr的前驱结点
		curr = findPrev(curr);
	}
	//表指针移后一位
	void next()
	{
		//找到curr的前驱结点
		DLNode<E>*curr_prev = findPrev(curr);
		curr = xorPointer(curr_prev, curr->prev_next);
	}
	//求表长
	int linkLength()
	{
		return length;
	}
	//返回当前位置
	int currPos()
	{
		int i=1;
		if (curr == head && length != 0)
			return i;
		DLNode<E>*temp_curr = head;
		DLNode<E>*temp_next = xorPointer(head->prev_next, nullptr);
		while (temp_next != curr)
		{
			DLNode<E>*temp = temp_next;
			temp_next = xorPointer(temp_curr, temp_next->prev_next);
			temp_curr = temp;
			i++;
		}
		return i+1;
	}
	//移动到第几个元素
	void moveToPos(int position)
	{
		if (position < 0 || position > length)
			return;
		DLNode<E>*temp_curr = head;
		DLNode<E>*temp_next = xorPointer(head->prev_next, nullptr);
		while ((position-1)>0)
		{
			DLNode<E>*temp = temp_next;
			temp_next = xorPointer(temp_curr, temp_next->prev_next);
			temp_curr = temp;
			position--;
		}
		curr = temp_curr;
	}
	//返回当前位置上的元素值
	E getValue()
	{
		//找到curr的前驱结点
		DLNode<E>*curr_prev = findPrev(curr);
		DLNode<E>*temp = xorPointer(curr->prev_next, curr_prev);
		if (temp == nullptr)
			return -1;
		return temp->elment;
	}
	//打印链表内数据
	void print()
	{
		DLNode<E>*temp_curr = head;
		DLNode<E>*temp_next = xorPointer(head->prev_next, nullptr);
		while (temp_next != nullptr)
		{
			DLNode<E>*temp = temp_next;
			cout << temp_next->elment;
			temp_next = xorPointer(temp_curr, temp_next->prev_next);
			temp_curr = temp;
		}
		cout << endl;
	}
};
