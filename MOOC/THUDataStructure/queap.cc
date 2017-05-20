#include <stdio.h>
#include <cstring>
#include <cstdlib>
class Stack
{
public:
	//注意：你不能添加更多的public函数或变量
	Stack();
	bool empty();
	void push(int);
	int pop();
	int top();
private:
	int po, data[1000050];
	//此处可以扩展
};

Stack::Stack()
{
	po=-1;
}

bool Stack::empty()
{
	return (po==-1);
}

void Stack::push(int value)
{
	data[++po]=value;
}

int Stack::pop()
{
	return data[po--];
}

int Stack::top()
{
	return data[po];	
}

/*
class Queue {
public:
	Queue();
	void push(int);
	int pop();
	int front();
private:
	Stack l,r;
}

Queue::Queue()
{
	while(!l.empty()) l.pop();
	while(!r.empty()) r.pop();
}

void Queue::push(int value) {
	l.push(value);
}

int Queue::pop()
{
	if(r.empty()) {
		while(!l.empty()) {
			r.push(l.pop());
		}
	}
	int ret=r.pop();
	return ret;
}

int Queue::front() {
	if(r.empty()) {
		while(!l.empty()) {
			r.push(l.pop());
		}
	}
	return r.top();
}
*/
class Queap
{
public:
	Queap();
	void enqueap(int);
	int dequeap();
	int max();
private:
	Stack l,r,ml,mr;
};
#define Clear(x) while(!x.empty())x.pop()
Queap::Queap() {
	Clear(l); 
	Clear(r);
	Clear(ml);
	Clear(mr);

}
void Queap::enqueap(int value)
{
	l.push(value);
	if(ml.empty()||(ml.top()<=value)) ml.push(value);
}
int Queap::dequeap() {
	if(r.empty()) {
		while(!l.empty()) {
			int t=l.pop();
			if((!ml.empty())&&ml.top()==t) ml.pop();
			r.push(t);
			if(mr.empty()||t>=mr.top()) mr.push(t);
		}
	}
	int k;
	k=r.pop();
	if((!mr.empty())&&mr.top()==k) mr.pop();
	return k;
}
int Queap::max()
{
	if(ml.empty()) return mr.top();
	else if(mr.empty()) return ml.top();
	else {
		return mr.top()>ml.top()? mr.top():ml.top();
	}
}
//5

//5 6
//5 6 2

//6 2
//2
Queap q;
int main()
{
	int m; scanf("%d",&m);
	while(m--) {
		char cmd=getchar(); while(cmd<'A'||cmd>'Z') cmd=getchar();
		if(cmd=='E') {
			int x; scanf("%d",&x);
			q.enqueap(x);
		} else if(cmd=='D') {
			printf("%d\n",q.dequeap());
		} else  {
			printf("%d\n",q.max());
		}
	}
	return 0;
}
