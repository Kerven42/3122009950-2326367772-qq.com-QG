 #include <stdlib.h>
#include <stdio.h>


typedef struct node
{
	void* data;                   //������ָ��
	struct node* next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
	Node* front;                   //��ͷ
	Node* rear;                    //��β
	size_t length;            //���г���
} LQueue;

typedef enum
{
	FALSE = 0, TRUE = 1
} Status;
char type;
char datatype[30];

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q)
{
	Q->front = Q->rear = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q)
{
	node* p, * pre;
	p = pre = Q->front;
	while (p != NULL)
	{
		pre = p;
		p = p->next;
		free(pre);
	}
	Q->front = Q->rear = NULL;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q) {
	if (Q->front == NULL && Q->rear == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e) {


	if (Q == NULL)
	{
		printf("FALSE\n");
	}
		return FALSE;
	if (IsEmptyLQueue(Q))
	{
		printf("TRUE\n");
		return TRUE;
	}
	e = (int*)Q->front->data;

}



/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
	node* p = Q->front->next; // �Ӷ�ͷ��ʼѭ��
	int length = 0; // ���г��ȱ���
	while (p != NULL) { // ֻҪ����û�б�����
		length++; // ���ȼ�1
		p = p->next; // ����ƶ�ָ��
	}
	return length; // ���ض��г���
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (!new_node) { // �ڴ治�㣬����ʧ��
		return FALSE;
	}
	new_node->data = data; // �½ڵ��б�������
	new_node->next = NULL; // �½ڵ�� next ָ���ʼ��Ϊ��
	Q->rear->next = new_node; // ���½ڵ������ʽ����β��
	Q->rear = new_node; // ���¶���βָ��
	return TRUE; // ��ӳɹ������� TRUE
}


/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q) {
	if (Q->front == Q->rear) { // ����Ϊ��
		return FALSE;
	}
	Node* p = Q->front->next; // ָ�����ͷ���ڵ�
	void* data = p->data; // ����ͷ���ڵ������
	Q->front->next = p->next; // ɾ������ͷ���ڵ�
	if (Q->rear == p) { // �������ֻ��һ���ڵ㣬����Ҫ����βָ��
		Q->rear = Q->front;
	}
	free(p); // �ͷű�ɾ���Ľڵ���ռ�õ��ڴ�
	return TRUE; // ���ӳɹ������� TRUE
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
	Node* p, * q;
	p = Q->front->next; // p ָ�����ͷ���ڵ�
	while (p != NULL) { // ���������е����нڵ�
		q = p->next; // q ָ�� p ����һ���ڵ�
		free(p); // �ͷ� p ��ռ�õ��ڴ�ռ�
		p = q; // �� p ָ����һ���ڵ�
	}
	Q->front = Q->rear; // �ָ����еĳ�ʼ״̬
}


/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)) {
	Node* p = Q->front->next; // ָ�����ͷ���ڵ�
	while (p) { // ���������е����нڵ�
		foo(p->data); // ����ָ�� foo����������
		p = p->next; // �� p ָ����һ���ڵ�
	}
	return TRUE; // �����ɹ������� TRUE
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q) {
	printf("%d ", *(int*)q);
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
 // LQUEUE_H_INCLUDED


