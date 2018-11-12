//Single Linked link
class LNode
{
public:
	int elment;
	LNode* next;
	LNode(int x, LNode* object = nullptr)
	{
		elment = x;
		next = object;
	}
	LNode(LNode* object = nullptr)
	{
		next = object;
	}
};
class LLink
{
private:
	int length; //当前链表的长度
	LNode* curr; //当前位置
	LNode* head;
	LNode* tail;
public:
	//构造函数
	LLink();
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
//单链表
LLink::LLink()
{
	head = curr = tail = new LNode();
	length = 0;
}
//清空链表
void LLink::clear()
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
void LLink::insert(int x)
{
	curr->next = new LNode(x, curr->next);
	if (tail == curr)
		tail = curr->next;
	length++;
}
//添加到链表尾
void LLink::append(int x)
{
	tail=tail->next = new LNode(x, tail->next);
	length++;
}
//移除元素
int LLink::remove()
{
	if (curr == tail)
		return;
	LNode* temp = curr->next;
	int temp1 = temp->elment;
	if (tail == tail->next)
		tail = curr;
	curr->next = temp->next;
	delete temp;
	length--;
	return temp1;
}
//表指针移动到尾部
void LLink::moveToEnd()
{
	curr = tail;
}
//表指针移动到头部
void LLink::moveToStart()
{
	curr = head;
}
//表指针移前一位
void LLink::prev()
{
	if (curr == head)
		return;
	LNode* temp = head;
	while (temp->next != curr)
	{
		temp = temp->next;
	}
	curr = temp;
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
	for (i = 0; curr!=temp; i++)
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
