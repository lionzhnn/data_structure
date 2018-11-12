//array based stack
class AStack
{
private:
//表示第一个空闲的位置
	int top;
	int* elments;
  //表示栈最大的长度
	int maxLen;
public:
//构造函数
	AStack(int max = 0);
  //析构函数
	~AStack();
  //入栈
	void push(int x);
  //出栈
	int pop();
  //重新初始化栈
	void clear();
  //得到栈顶元素值
	int getTopValue();
  //得到栈内元素个数
	int getStackLen();
};
//Array based Stack
AStack::AStack(int max)
{
	maxLen = max;
	top = 0;
	elments = new int[max];
}
AStack::~AStack()
{
	top  = 0;
	delete[] elments;
}
void AStack::push(int x)
{
	if (top >= maxLen)
		return;
	elments[top++] = x;
}
int AStack::pop()
{
	if (top <=0)
		return;
	int temp = elments[--top];
}
void AStack::clear()
{
	delete[] elments;
	AStack(maxLen);
}
int AStack::getTopValue()
{
	return elments[top - 1];
}
int AStack::getStackLen()
{
	return top;
}
