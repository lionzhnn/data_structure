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
class LDQueue
{
private:
	LNode* front;
	LNode* rear;
	int queueLen;
public:
	//构造函数
	LDQueue();
	//析构函数
	~LDQueue();
	//从队尾插入元素
	void push(int x);
	//从队首插入元素
	void inject(int x);
	//删除队尾元素，并返回它的值
	int pop();
	//删除队首元素，并返回它的值
	int eject();
	//重新初始化队列
	void clear();
	//得到队首元素
	int getFrontValue();
	//得到队尾元素
	int getBackValue();
	//得到队列长度
	int getLQueueLen();
	//打印队列内元素
	void print();
};
LDQueue::LDQueue()
{
	front = rear = new LNode();
	queueLen = 0;
}
LDQueue::~LDQueue()
{
	clear();
	delete front;
}
void LDQueue::push(int x)
{
	rear = rear->next = new LNode(x, nullptr);
	queueLen++;
}
void LDQueue::inject(int x)
{
	front->next = new LNode(x, front->next);
	queueLen++;
}
int LDQueue::pop()
{
	if (queueLen == 0)
		return -1;
	int temp = rear->elment;
	LNode* temp1 = front;
	while (temp1->next != rear)
	{
		temp1 = temp1->next;
	}
	LNode* temp2 = rear;
	rear = temp1;
	rear->next = nullptr;
	delete temp2;
	return temp;
}
int LDQueue::eject()
{
	if (queueLen == 0)
		return -1;
	int temp = front->next->elment;
	LNode* temp1 = front->next;
	front->next = front->next->next;
	if (rear == temp1)
		rear = front;
	delete temp1;
	queueLen--;
	return temp;
}
void LDQueue::clear()
{
	while (front != nullptr)
	{
		LNode* temp = front;
		front = front->next;
		delete temp;
	}
	front = rear = new LNode();
	queueLen = 0;
}
int LDQueue::getFrontValue()
{
	return front->next->elment;
}
int LDQueue::getBackValue()
{
	return rear->elment;
}
int LDQueue::getLQueueLen()
{
	return queueLen;
}
void LDQueue::print()
{
	LNode* temp = front->next;
	while (temp!=nullptr)
	{
		printf("%d\n", temp->elment);
		temp = temp->next;
	}
}
