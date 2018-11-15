//Doubly Linked link
class DLNode
{
public:
	int elment;
	DLNode* prev;
	DLNode* next;
	DLNode(int x, DLNode* objPrev = nullptr,DLNode* objNext=nullptr)
	{
		elment = x;
		next = objNext;
		prev = objPrev;
	}
	DLNode(DLNode* objPrev = nullptr,DLNode* objNext=nullptr)
	{
		next = objNext;
		prev = objPrev;
	}
};
class DLLink
{
private:
	int length; //当前链表的长度
	DLNode* curr; //当前位置
	DLNode* head;
	DLNode* tail;
public:
	//构造函数
	DLLink();
	//清空链表
	void clear();
	//插入元素
	void insert(int x);
	//添加到链表尾
	void append(int x);
	//移除元素
	int remove();
	//表指针移动到尾部
	void moveToEnd();
	//表指针移动到头部
	void moveToStart();
	//表指针移前一位
	void prev();
	//表指针移后一位
	void next();
	//求表长
	int linkLength();
	//返回当前位置
	int currPos();
	//移动到确定位置
	void moveToPos(int position);
	//返回当前位置上的元素值
	int getValue();
};
//双链表
DLLink::DLLink()
{
	head = curr = tail = new DLNode();
	length = 0;
}
//清空链表
void DLLink::clear()
{
	while (head != nullptr)
	{
		curr = head;
		head = head->next;
		delete curr;
	}
	LLink();
}
//插入元素
void DLLink::insert(int x)
{
	curr->next = curr->next->prev=new DLNode(x, curr,curr->next);
	if (tail == curr)
		tail = curr->next;
	length++;
}
//添加到链表尾
void DLLink::append(int x)
{
	tail =tail->next=new DLNode(x, tail,nullptr);
	length++;
}
//移除元素
int DLLink::remove()
{
	if (curr == tail)
		return;
	DLNode* temp = curr->next;
	int temp1 = temp->elment;
	if (tail == tail->next)
		tail = curr;
	curr->next = temp->next;
	temp->next->prev = curr;
	delete temp;
	length--;
	return temp1;
}
//表指针移动到尾部
void DLLink::moveToEnd()
{
	curr = tail;
}
//表指针移动到头部
void DLLink::moveToStart()
{
	curr = head;
}
//表指针移前一位
void DLLink::prev()
{
	if (curr == head)
		return;
	curr = curr->prev;
}
//表指针移后一位
void LLink::next()
{
	if (curr == tail)
		return;
	curr = curr->next;
}
//求表长
int LLink::linkLength()
{
	return length;
}
//返回当前位置
int LLink::currPos()
{
	int i;
	LNode* temp = head;
	for (i = 0; curr != temp; i++)
	{
		temp = temp->next;
	}
	return i;
}
//移动到确定位置
void LLink::moveToPos(int position)
{
	if (position < 0 || position >= length - 1)
		return;
	curr = head;
	for (int i = 0; i < position; i++)
		curr = curr->next;
}
//返回当前位置上的元素值
int LLink::getValue()
{
	if (curr->next == nullptr)
		return;
	return curr->next->elment;
}
