//linked queue
class LQueue
{
private:
	LNode* front;
	LNode* rear;
	int queueLen;
public:
//构造函数
	LQueue();
  //析构函数
	~LQueue();
  //将元素插入队列
	void eLQueue(int x);
  //从队列中移除元素
	int deLQueue();
  //重新初始化队列
	void clear();
  //得到队首元素值
	int getFrontValue();
  //得到队列长度
	int getLQueueLen();
  //打印队列中元素
	void print();
};
//linked queue
LQueue::LQueue()
{
	front = rear = new LNode();
	queueLen = 0;
}
LQueue::~LQueue()
{
	while (front != nullptr)
	{
		LNode* temp = front;
		front = front->next;
		delete temp;
	}
}
void LQueue::eLQueue(int x)
{
	rear =rear->next= new LNode(x, nullptr);
	queueLen++;
}
int LQueue::deLQueue()
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
void LQueue::clear()
{
	while (front != nullptr)
	{
		LNode* temp = front;
		front = front->next;
		delete temp;
	}
	LQueue();
}
int LQueue::getFrontValue()
{
	if (queueLen == 0)
		return -1;
	return front->next->elment;
}
int LQueue::getLQueueLen()
{
	return queueLen;
}
void LQueue::print()
{
	LNode* temp = front->next;
	while(temp!=nullptr)
	{
		printf("%d\n", temp->elment);
		temp = temp->next;
	}
}
