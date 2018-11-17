#include<iostream>
#include <math.h>
#define MAXSIZE 100
using namespace std;

//Doubly Linked link
template<typename E> class DLNode
{
public:
	E elment;
	DLNode* prev;
	DLNode* next;
	DLNode(E x, DLNode* objPrev = nullptr, DLNode* objNext = nullptr)
	{
		elment = x;
		next = objNext;
		prev = objPrev;
	}
	DLNode(DLNode* objPrev = nullptr, DLNode* objNext = nullptr)
	{
		next = objNext;
		prev = objPrev;
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
	DLLink()
	{
		head = curr = tail = new DLNode<E> ();
		length = 0;
	}
	//清空链表
	void clear()
	{
		while (head != nullptr)
		{
			curr = head;
			head = head->next;
			delete curr;
		}
		LLink();
	}
	int addElments(E x)
	{
		if (curr->next==nullptr)
		{
			append(x);
			return 0;
		}
		int temp = curr->next->elment + x - 2 * 48;
		curr->next->elment = temp%10 + '0';
		return temp / 10;
	}
	//插入元素
	void insert(E x)
	{
		//若链表内没有元素，相当于在队尾添加元素
		if (length==0)
		{
			append(x);
			return;
		}
		curr->next = curr->next->prev = new DLNode<E>(x, curr, curr->next);
		if (tail == curr)
			tail = curr->next;
		length++;
	}
	//添加到链表尾
	void append(E x)
	{
		tail = tail->next  = new DLNode<E>(x, tail, nullptr);
		length++;
	}
	//移除元素
	int remove()
	{
		if (curr == tail)
			return -1;
		DLNode<E>* temp = curr->next;
		int temp1 = temp->elment;
		if (tail == curr->next)
		{
			tail = curr;
			delete temp;
			length--;
			return temp1;
		}
		curr->next = temp->next;
		temp->next->prev = curr;
		delete temp;
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
		curr = curr->prev;
	}
	//表指针移后一位
	void next()
	{
		if (curr == tail)
			return;
		curr = curr->next;
	}
	//求表长
	int linkLength()
	{
		return length;
	}
	//返回当前位置
	int currPos()
	{
		int i;
		DLNode* temp = head;
		for (i = 0; curr != temp; i++)
		{
			temp = temp->next;
		}
		return i;
	}
	//移动到确定位置
	void moveToPos(int position)
	{
		if (position < 0 || position >= length - 1)
			return;
		curr = head;
		for (int i = 0; i < position; i++)
			curr = curr->next;
	}
	//返回当前位置上的元素值
	E getValue()
	{
		if (curr->next == nullptr)
			return -1;
		return curr->next->elment;
	}
	void print()
	{
		DLNode<E>*temp = head;
		while (temp->next != nullptr)
		{
			cout << temp->next->elment;
			temp = temp->next;
		}
		cout << endl;
	}
	void reverse()
	{
		curr = tail;
		while (curr!=nullptr)
		{
			DLNode<E>*temp = curr->next;
			curr->next = curr->prev;
			curr->prev = temp;
			curr = curr->next;
		}
		DLNode<E>*temp = head->prev;
		//添加一个没有值的头节点
		head = new DLNode<E>(nullptr,tail);
		//删除原来的头节点，将tail前移一位
		tail = temp;
		temp = tail->next;
		tail->next = nullptr;
		delete temp;
		curr = head;
	}
};
//a>=b true ; a<b false
bool compare(DLLink<char>* a, DLLink<char>* b)
{
	if (a->linkLength() < b->linkLength())
		return false;
	else if (a->linkLength() == b->linkLength())
	{
		//从高位开始比较，遇到第一个a比b小的数字，则说明b>a
		a->moveToEnd();
		b->moveToEnd();
		int tempLena = a->linkLength();
		while (a->getValue() == b->getValue() && tempLena>0)
		{
			a->prev();
			b->prev();
			tempLena--;
		}
		if (tempLena == 0)
			return true;
		if (a->getValue() > b->getValue())
		{
			a->moveToStart();
			b->moveToStart();
			return true;
		}
		a->moveToStart();
		b->moveToStart();
		return false;
	}
	return true;
}
//结果高位靠近链表头、低位靠近链表尾
DLLink<char>* jia(DLLink<char>* a, DLLink<char>* b, DLLink<char>* result)
{
	if (compare(a, b) == false)
	{
		DLLink<char>* temp = a;
		a = b;
		b = temp;
	}
	a->moveToStart();
	b->moveToStart();
	int len = b->linkLength();
	//进位
	int count = 0;
	//计算a，b相同长度部分
	while (len > 0)
	{
		//从低位开始计算
		//将char型数据转化为int型计算
		int tempa = a->getValue() - '0';
		int tempb = b->getValue() - '0';
		int tempValue = tempa + tempb + count;
		//商为进位
		count = tempValue / 10;
		//余数为存储结果
		tempValue = tempValue % 10;
		result->insert(tempValue + '0');
		len--;
		//移动指针，获取下一位计算数据
		a->next();
		b->next();
	}
	//a、b长度相同时存储进位
	if ((a->linkLength() == b->linkLength()) && count == 1)
	{
		result->insert('1');
	}
	//拷贝a比b长的那部分数据
	if (a->linkLength() > b->linkLength())
	{
		int tempLen = a->linkLength() - b->linkLength();
		while (tempLen > 0)
		{
			//拷贝的第一位数据加上低位的进位
			result->insert(a->getValue() + count);
			tempLen--;
			a->next();
			//清空进位
			count = 0;
		}
	}
	return result;
}
DLLink<char>* jian(DLLink<char>* a, DLLink<char>* b, DLLink<char>* result)
{
	bool flag = false;
	if (compare(a, b) == false)
	{
		DLLink<char>* temp = a;
		a = b;
		b = temp;
		flag = true;
	}
	a->moveToStart();
	b->moveToStart();
	int len = b->linkLength();
	//借位
	int count = 0;
	//计算a，b相同长度部分
	while (len > 0)
	{
		//从低位开始计算
		//将char型数据转化为int型计算
		int tempa = a->getValue() - '0';
		int tempb = b->getValue() - '0';
		int tempValue;
		//有进位
		if ((tempa - count) < tempb)
		{
			tempa = tempa + 10 - count;
			tempValue = tempa - tempb;
			count = 1;
		}
		//没有进位
		else
		{
			tempValue = tempa - tempb - count;
			count = 0;
		}
		result->insert(tempValue + '0');
		len--;
		//移动指针，获取下一位计算数据
		a->next();
		b->next();
	}
	//拷贝a比b长的那部分数据
	if (a->linkLength() > b->linkLength())
	{
		int tempLen = a->linkLength() - b->linkLength();
		while (tempLen > 0)
		{
			//拷贝的第一位数据加上低位的进位
			result->insert(a->getValue() - count);
			tempLen--;
			a->next();
			//清空进位
			count = 0;
		}
	}
	//清除计算结果中高位的0
	while (result->getValue() == '0')
	{
		result->remove();
	}
	if (result->linkLength() == 0)
		result->insert('0');
	if (flag)
	{
		result->insert('-');
	}
	return result;
}
DLLink<char>* cheng(DLLink<char>* a, DLLink<char>* b, DLLink<char>* result)
{
	if (compare(a, b) == false)
	{
		DLLink<char>* temp = a;
		a = b;
		b = temp;
	}
	a->moveToStart();
	b->moveToStart();
	int len = b->linkLength();
	//借位
	int count = 0;
	//以b的长度作为循环相加的次数
	for (int i = 0; i < b->linkLength();i++)
	{
		int tempb = b->getValue() - '0';
		b->next();
		a->moveToStart();
		for (int j = 0; j < a->linkLength(); j++)
		{
			//从低位开始计算
			//将char型数据转化为int型计算
			int tempa = a->getValue() - '0';
			a->next();
			int tempValue;
			tempValue = tempa*tempb + count;
			count = tempValue / 10;
			tempValue = tempValue % 10;
			//有进位
			count=count+result->addElments(tempValue+'0');
			result->next();
			//移动指针，获取下一位计算数据
		}
		if (count != 0)
			result->addElments(count + '0');
		count = 0;
		result->moveToPos(i + 1);
		result->print();
		cout << endl;
	}
	//如果有一方为0，相乘结果为0，则result里没有存储数字，添加一个0
	if (result->linkLength() == 0)
		result->insert('0');
	result->reverse();
	return result;
}

DLLink<char>* chu(DLLink<char>* a, DLLink<char>* b, DLLink<char>* result)
{
	//如果a<b则输出结果为0
	if (compare(a, b) == false)
	{
		result->insert('0');
		return result;
	}
	a->moveToStart();
	b->moveToStart();
	while (compare(a,b))
	{
		a->moveToStart();
		b->moveToStart();
		int len = a->linkLength() - b->linkLength();
		for (int i = 0; i < len; i++)
			b->insert('0');
		if (compare(a,b)==false)
		{
			b->remove();
			len = len - 1;
		}
		a->moveToStart();
		b->moveToStart();
		int temp = 0;
		DLLink<char>* tempresult= nullptr;
		while (compare(a,b))
		{
			tempresult = new DLLink<char>();
			jian(a, b, tempresult);
			tempresult->reverse();
			delete a;
			a = tempresult;
			temp = temp + 1;
		}
		DLLink<char>* tempresult1 = new DLLink<char>();
		tempresult1->insert(temp+'0');
		temp = len;
		while (temp!=0)
		{
			tempresult1->insert('0');
			temp = temp - 1;
		}
		DLLink<char>* tempresult2 = new DLLink<char>();
		jia(tempresult1, result, tempresult2);
		delete result;
		tempresult2->reverse();
		result = tempresult2;
		b->moveToStart();
		for (int i = 0; i < len; i++)
			b->remove();
	}
	return result;
}
int main()
{
	while (1)
	{
		DLLink<char>* a = new DLLink<char>();
		DLLink<char>* b = new DLLink<char>();
		DLLink<char>* result = new DLLink<char>();
		char temp[MAXSIZE];
		char* tempChar=temp;
		char countMark = 0;
		cout << "输入a：" << endl;
		cin >> temp;
		//去除高位无效的数字0
		while (*tempChar == '0')
		{
			tempChar++;
		}
		//得到真正数据,存储时低位靠近头节点，高位靠近尾结点
		while (*tempChar !='\0')
		{
			a->insert(*tempChar);
			tempChar++;
		}
		cout << "输入运算符：" << endl;
		cin >> countMark;
		cout << "输入b：" << endl;
		cin >> temp;
		tempChar = temp;
		//去除高位无效的数字0
		while (*tempChar == '0')
		{
			tempChar++;
		}
		//得到真正数据,存储时低位靠近头节点，高位靠近尾结点
		while (*tempChar != '\0')
		{
			b->insert(*tempChar);
			tempChar++;
		}
		a->print();
		b->print();
		switch (countMark)
		{
		case '+':
			result = jia(a, b, result);
			result->print();
			break;
		case '-':
			result = jian(a, b, result);
			result->print();
			break;
		case '*':
			result = cheng(a, b, result);
			result->print();
			break;
		case '/':
			result = chu(a, b, result);
			result->print();
			break;
		default:
			cout << "输入了无效的运算符" << endl;
			break;
		}
		//释放链表空间
		delete a;
		delete b;
		delete result;
	}
	return 0;
}
