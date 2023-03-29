#include "LinkStack.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Á´Õ»
typedef enum
{
	FALSE = 0, TRUE = 1
} Status;

//³õÊ¼»¯Õ»
Status initLStack(LinkStack *s) {
	s->top = NULL;
	return TRUE;
}

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
Status isEmptyLStack(LinkStack *s) {
	if (s->top == NULL) {
		return TRUE;
	}
	else {    
		return FALSE;
	}
}

//µÃµ½Õ»¶¥ÔªËØ
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s->top == NULL) {
		return FALSE;
	}
	else {
		*e = s->top->data;
		return TRUE;
	}
}

//Çå¿ÕÕ»
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

//Ïú»ÙÕ»
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

//¼ì²âÕ»³¤¶È
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

//ÈëÕ»
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

//³öÕ»
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

