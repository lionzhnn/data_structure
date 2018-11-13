//需要区分在队伍中有0个、1个......maxLen个元素，有maxLen+1种情况，使用maxLen+1长数组来区分
//array based queue
class AQueue
{
private:
	int front,rear;
	int* elments;
	int maxLen;
public:
	AQueue(int max = 0);
	~AQueue();
	void eQueue(int x);
	int deQueue();
	void clear();
	int getFrontValue();
	int getQueueLen();
	void print();
};
//array based queue
AQueue::AQueue(int max = 0)
{
	rear = 0;
	front = 1;
	maxLen = max+1;
	elments = new int[maxLen]; //
}
AQueue::~AQueue()
{
	delete[] elments;
	maxLen = 0;
}
void AQueue::eQueue(int x)
{
	if (getQueueLen()==(maxLen-1))
		return;
	rear = (rear+1) % maxLen;
	elments[rear] = x;
}
int AQueue::deQueue()
{
	if (getQueueLen() == 0)
		return -1;
	int temp = elments[front];
	front = (front + 1) % maxLen;
	return temp;
}
void AQueue::clear()
{
	rear = 0;
	front = 1;
}
int AQueue::getFrontValue()
{
	if (getQueueLen() == 0)
		return -1;
	return elments[front];
}
int AQueue::getQueueLen()
{
	return ((rear+maxLen) - front +1)%maxLen;
}
void AQueue::print()
{
	for (int i = 0; i < getQueueLen(); i++)
	{
		printf("%d\n", deQueue());
	}
}
