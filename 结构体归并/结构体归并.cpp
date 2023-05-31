/*
	结构体归并函数 不知道能不能写出来

	结构体的归并函数  思路 大概是对的 代码需要优化
	竟然写出来了
*/
#include <iostream>
using namespace std;
struct student
{
	int age; 
	student * next;
};
int re_size(struct student* head) {
	student* p = head;
	int i = 0;
	//cout << p->next->age << endl;
	while (p->next != NULL)
	{
		p = p->next;
		i++;
	}
	return i;
}
void addstu(struct student* head,int age) {
	
	student* p = head;						//头插入法
	student* r = new student;
	r->age = age;
	r->next = p->next;
	p->next = r;
	
}
void bianli(struct student* head) {
	student* p = head ->next;
	int i = 1; 
	while (p!= NULL)
	{
		cout << "第" << i << "个节点为" << p->age << "\n";
		p = p->next;
		i++;
	}
}
void marge(struct student* head , int length);
void sort(struct student* head, student * temparr, int left, int rigth);
void gaibianzhi(student* head, int len , int item);
int shuchu(struct student* head, int n);
void guibing(struct student* head, struct student* tmparr, int left, int mid, int rigth);
int main() {
	student* st = new student;
	st->age = 0; 
	st->next = NULL;
	for (int i = 0; i < 10; i++) {
		addstu(st, rand() % 20);
	}
	
	bianli(st);
	marge(st, 10);
	cout << "归并以后 : " << endl;
	bianli(st);
	cout << "st的size 为 : " << re_size(st) << endl;
}

void gaibianzhi(student* head, int len , int item) {
	struct student* p = head;
	int i = 0;
	while (p->next != NULL && i < len) {
		p = p->next;
		i++;
	}
	p->age = item;
}

void guibing(struct student* head, struct student* tmparr, int left, int mid, int rigth) {
	int l_pos = left; 
	int r_pos = mid + 1;
	int pos = left;
	while (l_pos <= mid && r_pos <= rigth) {
		if (shuchu(head, l_pos) < shuchu(head, r_pos)) {
			int temp = shuchu(head, l_pos);
			//gaibianzhi(tmparr, pos, temp);
			tmparr[pos].age = temp;
			pos++;
			l_pos++;
		}
		else {
			int temp = shuchu(head, r_pos);
			//addstu(tmparr, pos);
			tmparr[pos].age = temp;
			pos++;
			r_pos++;
		}
	}

	while (l_pos <= mid)
	{
		int temp = shuchu(head, l_pos);
		//addstu(tmparr, pos);
		tmparr[pos].age = temp;
		pos++;
		l_pos++;
	}
	while (r_pos <= rigth)
	{
		int temp = shuchu(head, r_pos);
		//addstu(tmparr, pos);
		tmparr[pos].age = temp;
		pos++;
		r_pos++;
	}
	while (left <= rigth) {

		//int temp = shuchu(tmparr, left);
		//addstu(head, left);
		//tmparr[pos].age = temp;
		gaibianzhi(head, left, tmparr[left].age);
		left++;
	}

}

int shuchu(struct student* head, int n) {
	struct student* p = head ;
	int i = 0;
	while (p->next != NULL && i < n) {
		p = p->next;
		i++;
	}
	
	return p->age;
}

void sort(struct student* head, student* temparr, int left, int rigth) {
	//cout << "head : " << &head[1]  << endl;
	/*if (left == rigth) {
		cout << "arr[" << left << ']' <<  shuchu(head,left) << endl;

	}*/
	if (left < rigth) {
		int mind = left + (rigth - left) / 2;		
		sort(head, temparr, left, mind);
		sort(head, temparr, mind + 1, rigth);
		guibing(head,temparr,left,mind,rigth);
	}
}

void marge(struct student* head , int length) {
	student* temparr = new student[length + 1];
	if (temparr) {
		sort(head, temparr, 1, length );
		delete[] temparr;
	}
	else {
		cout << "内存分配失败!\n";
	}
}


