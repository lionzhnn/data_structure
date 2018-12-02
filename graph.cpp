#include "graph.h"
#include <iostream>
using namespace std;
class Graphm :public Graph
{
private:
	int numVertex, numEdge;
	int **maxtrix;
	int *max;
public:
	Graphm(int objVertex=0) {
		numVertex = objVertex;
		numEdge = 0;
		maxtrix = new int*[objVertex];
		max = new int[objVertex];
		for (int i = 0; i < objVertex; i++) {
			maxtrix[i] = new int[objVertex];			
		}
		for (int i = 0; i < objVertex; i++) {
			max[i] = 0;
			for (int j = 0; j < objVertex; j++) {
				maxtrix[i][j] = 0;
			}
		}
	}
	~Graphm() {
		for (int i = 0; i < numVertex; i++) {
			delete[] maxtrix[i];
		}
		delete[] maxtrix;
		delete[] max;
	}
	// Return the number of vertices in the graph
	int n()	{
		return numVertex;
	}

	// Return the current number of edges in the graph
	int e()	{
		return numEdge;
	}

	// Store an edge from v1 to v2 with weight wgt
	void setEdge(int v1, int v2, int wgt){
		if (wgt <= 0){
			cout << "权重应该大于0";
			return;
		}
		if (maxtrix[v1][v2] == 0) {
			numEdge++;
		}
		maxtrix[v1][v2] = wgt;
	}

	// Delete the edge going from v1 to v2
	void delEdge(int v1, int v2) {
		if (maxtrix[v1][v2] == 0)
			return;
		maxtrix[v1][v2] = 0;
		numEdge--;
	}

	// Return weight of the edge from v1 to v2.
	// Return 0 if no such edge exists.
	int weight(int v1, int v2) {
		return maxtrix[v1][v2];
	}

	// Get the mark value for vertex v
	int getMark(int v) {
		return max[v];
	}

	//  Set the mark value for vertex v to be val
	void setMark(int v, int val) {
		max[v] = val;
	}

	// Return the index of the first neighbor for vertex v
	int first(int v) {
		for (int i = 0; i < numVertex; i++) {
			if (maxtrix[v][i] != 0)
			{
				return i;
			}
		}
		return numVertex;
	}

	// Return the index of the next neighbor
	// (after v2) for vertex v1
	int next(int v1, int v2) {
		for (int i = v2+1; i < numVertex; i++) {
			if (maxtrix[v1][i] != 0)
			{
				return i;
			}
		}
		return numVertex;
	}
	bool isEdge(int v1, int v2) {
		return maxtrix[v1][v2] != 0;
	}
};
class Edge
{
public:
	Edge() {
		vert = -1, wt = -1;
	}
	Edge(int objVert,int objWt) {
		vert = objVert, wt = objWt;
	}
	Edge operator=(const Edge obj){
		Edge temp;
		temp.vert = obj.vert;
		temp.wt = obj.wt;
		return temp;
	}
	int getVert() {
		return vert;
	}
	int getWt() {
		return wt;
	}
private:
	int vert, wt;
};
template<typename E> class LNode
{
public:
	E elment;
	LNode* next;
	LNode(E x, DLNode* objNext = nullptr)
	{
		elment = x;
		next = objNext;
	}
	LNode(DLNode* objNext = nullptr)
	{
		next = objNext;
	}
};
template<typename E> class LLink
{
private:
	int length; //当前链表的长度
	LNode<E>* curr; //当前位置
	LNode<E>* head;
	LNode<E>* tail;
public:
	LLink()
	{
		head = curr = tail = new LNode<E>();
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
	//插入元素
	void insert(int x)
	{
		curr->next = new LNode<E>(x, curr->next);
		if (tail == curr)
			tail = curr->next;
		length++;
	}
	//添加到链表尾
	void append(E x)
	{
		tail = tail->next = new LNode<E>(x, tail->next);
		length++;
	}
	//移除元素
	int remove()
	{
		if (curr == tail)
			return -1;
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
		LNode* temp = head;
		while (temp->next != curr)
		{
			temp = temp->next;
		}
		curr = temp;
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
		LNode<E>* temp = head;
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
			return Edge();
		return curr->next->elment;
	}
};
class Graphl:public Graph
{
private:
	int numVertex, numEdge;
	LLink<Edge> **vertex;
	int *max;
public:
	Graphl(int objVertex = 0) {
		numVertex = objVertex;
		numEdge = 0;
		vertex = new LLink<Edge>*[objVertex];
		max = new int[objVertex];
		for (int i = 0; i < objVertex; i++) {
			vertex[i] = new LLink<Edge>();
		}
		for (int i = 0; i < objVertex; i++) {
			max[i] = 0;
		}
	}
	~Graphl() {
		for (int i = 0; i < numVertex; i++) {
			delete[] vertex[i];
		}
		delete[] vertex;
		delete[] max;
	}
	// Return the number of vertices in the graph
	int n() {
		return numVertex;
	}

	// Return the current number of edges in the graph
	int e() {
		return numEdge;
	}

	// Store an edge from v1 to v2 with weight wgt
	void setEdge(int v1, int v2, int wgt) {
		Edge* temp = new Edge(v2, wgt);
		vertex[v1]->append(*temp);
		numEdge++;
	}

	// Delete the edge going from v1 to v2
	void delEdge(int v1, int v2) {
		if (isEdge(v1, v2)) {
			vertex[v1]->remove();
			numEdge--;
		}
	}

	// Return weight of the edge from v1 to v2.
	// Return 0 if no such edge exists.
	int weight(int v1, int v2) {
		if (isEdge(v1, v2)) {
			Edge temp= vertex[v1]->getValue();
			return temp.getVert();
		}
		return 0;
	}

	// Get the mark value for vertex v
	int getMark(int v) {
		return max[v];
	}

	//  Set the mark value for vertex v to be val
	void setMark(int v, int val) {
		max[v] = val;
	}

	// Return the index of the first neighbor for vertex v
	int first(int v) {
		//该顶点没有与它相邻的边
		if (vertex[v]->linkLength() == 0)
			return numVertex;
		//在与顶点相邻的边中找到最开始的边
		vertex[v]->moveToStart();
		Edge temp = vertex[v]->getValue();
		return temp.getVert;
	}

	// Return the index of the next neighbor
	// (after v2) for vertex v1
	int next(int v1, int v2) {
		if (isEdge(v1, v2)) {
			//判断v2之后还有没有结点
			if ((vertex[v1]->currPos + 1) < vertex[v1]->linkLength()) {
				vertex[v1]->next();
				Edge temp = vertex[v1]->getValue();
				return temp.getVert();
			}
		}
		return numVertex;
			
	}
	bool isEdge(int v1, int v2) {
		Edge it;
		for (vertex[v1]->moveToStart(); vertex[v1]->currPos() < vertex[v1]->linkLength(); vertex[v1]->next()) {
			Edge temp = vertex[v1]->getValue();
			if (temp.getVert == v2) {
				return true;
			}
		}
		return false;
	}
};
