//[]->[]->[]->[]->[]
//<------------增长方向
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
//linked stack
class LStack
{
	int length;
	LNode* top;
	void removeAll()
	{
		while (top != nullptr)
		{
			LNode* temp = top;
			top = top->next;
			delete temp;
		}
	}
public:
//构造函数
	LStack();
  //析构函数
	~LStack();
  //入栈
	void push(int x);
  //出栈
	int pop();
  //重新初始化栈
	void clear();
  //得到栈顶元素值
	int getTopValue();
  //得到栈长度
	int getStackLen();

};
//Array based Stack
LStack::LStack()
{
	top = nullptr;
	length = 0;
}
LStack::~LStack()
{
	removeAll();
}
void LStack::push(int x)
{
	top=new LNode(x, top);
	length++;
}
int LStack::pop()
{
	if (top==nullptr)
		return;
	int temp = top->elment;
	LNode* temp1 = top;
	top = top->next;
	delete temp1;
	length--;
	return temp;
}
void LStack::clear()
{
	removeAll();
	LStack();
}
int LStack::getTopValue()
{
	if (top == nullptr)
		return;
	return top->elment;
}
int LStack::getStackLen()
{
	return length;
}
