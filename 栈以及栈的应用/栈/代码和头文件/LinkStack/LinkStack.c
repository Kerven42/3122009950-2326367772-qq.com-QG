#include "LinkStack.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��ջ
typedef enum
{
	FALSE = 0, TRUE = 1
} Status;

//��ʼ��ջ
Status initLStack(LinkStack *s) {
	s->top = NULL;
	return TRUE;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s) {
	if (s->top == NULL) {
		return TRUE;
	}
	else {    
		return FALSE;
	}
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s->top == NULL) {
		return FALSE;
	}
	else {
		*e = s->top->data;
		return TRUE;
	}
}

//���ջ
Status clearLStack(LinkStack* s) {
	if (s->top == NULL) {
		return FALSE;
	}
	LinkStackPtr p, q;
	p = s->top;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	s->top = NULL;
	return TRUE;
}

//����ջ
Status destroyLStack(LinkStack* s) {
	if (s->top == NULL) {
		return FALSE;
	}
	LinkStackPtr p, q;
	p = s->top;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	s->top = NULL;
	return TRUE;
}

//���ջ����
Status LStackLength(LinkStack* s, int* length) {
	if (s == NULL) {
		return FALSE;
	}
	LinkStackPtr p = s->top;
	int count = 0;
	while (p != NULL) {
		++count;
		p = p->next;
	}
	*length = count;
	return TRUE;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType data) {
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p == NULL) {
		return FALSE;
	}
	p->data = data;
	p->next = s->top;
	s->top = p;
	return TRUE;
}

//��ջ
Status popLStack(LinkStack* s, ElemType* data) {
	if (s->top == NULL) {
		return FALSE;
	}
	LinkStackPtr p = s->top;
	*data = p->data;
	s->top = p->next;
	free(p);
	return TRUE;
}

