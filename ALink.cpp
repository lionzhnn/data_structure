//array link
//当线性表空间被耗尽时，将数组长度加倍
class ALink
{
private:
	int length; //当前顺序表的长度
	int maxLen; //顺序表的最大长度
	int* elemnts; //顺序表的首地址
	int curr; //当前位置
public:
	//构造函数
	ALink(int max);
	//析构函数
	~ALink();
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
//线性表
ALink::ALink(int max = 0)
{
	curr = length = 0;
	maxLen = max;
	elemnts = new int[max];
}
ALink::~ALink()
{
	delete[] elemnts;
}
//清空链表
void ALink::clear()
{
	delete[] elemnts;
	curr = length = 0;
	elemnts = new int[maxLen];
}
//插入元素
void ALink::insert(int x)
{
	if (length >= maxLen)
	{
		maxLen = 2 * maxLen;
		int* temp = new int[maxLen];
		memcpy(temp, elemnts, length*sizeof(int));
		delete[] elemnts;
		elemnts = temp;
	}
	for (int i = curr; i < length; i++)
		elemnts[i + 1] = elemnts[i];
	elemnts[curr] = x;
	length++;
}
//添加到链表尾
void ALink::append(int x)
{
	if (length >= maxLen)
	{
		maxLen = 2 * maxLen;
		int* temp = new int[maxLen];
		memcpy(temp, elemnts, length*sizeof(int));
		delete[] elemnts;
		elemnts = temp;
	}
	elemnts[length++] = x;
}
//移除元素
int ALink::remove()
{
	int temp = elemnts[curr];
	if (length <= 0)
		return 0;
	for (int i = curr; i < length - 1; i++)
		elemnts[i] = elemnts[i + 1];
	length--;
	return temp;
}
//表指针移动到尾部
void ALink::moveToEnd()
{
	curr = length;
}
//表指针移动到头部
void ALink::moveToStart()
{
	curr = 0;
}
//表指针移前一位
void ALink::prev()
{
	if (curr <= 0)
		return;
	curr--;
}
//表指针移后一位
void ALink::next()
{
	if (curr >= length - 1)
		return;
	curr++;
}
//求表长
int ALink::linkLength()
{
	return length;
}
//返回当前位置
int ALink::currPos()
{
	return curr;
}
//移动到确定位置
void ALink::moveToPos(int position)
{
	if (position < 0 || position >= length - 1)
		return;
	curr = position;
}
//返回当前位置上的元素值
int ALink::getValue()
{
	return elemnts[curr];
}
