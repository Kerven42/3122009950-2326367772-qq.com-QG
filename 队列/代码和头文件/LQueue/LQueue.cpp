 #include <stdlib.h>
#include <stdio.h>


typedef struct node
{
	void* data;                   //数据域指针
	struct node* next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
	Node* front;                   //队头
	Node* rear;                    //队尾
	size_t length;            //队列长度
} LQueue;

typedef enum
{
	FALSE = 0, TRUE = 1
} Status;
char type;
char datatype[30];

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q)
{
	Q->front = Q->rear = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
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
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
	node* p = Q->front->next; // 从队头开始循环
	int length = 0; // 队列长度变量
	while (p != NULL) { // 只要队列没有遍历完
		length++; // 长度加1
		p = p->next; // 向后移动指针
	}
	return length; // 返回队列长度
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (!new_node) { // 内存不足，分配失败
		return FALSE;
	}
	new_node->data = data; // 新节点中保存数据
	new_node->next = NULL; // 新节点的 next 指针初始化为空
	Q->rear->next = new_node; // 将新节点插入链式队列尾部
	Q->rear = new_node; // 更新队列尾指针
	return TRUE; // 入队成功，返回 TRUE
}


/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q) {
	if (Q->front == Q->rear) { // 队列为空
		return FALSE;
	}
	Node* p = Q->front->next; // 指向队列头部节点
	void* data = p->data; // 保存头部节点的数据
	Q->front->next = p->next; // 删除队列头部节点
	if (Q->rear == p) { // 如果队列只有一个节点，则需要更新尾指针
		Q->rear = Q->front;
	}
	free(p); // 释放被删除的节点所占用的内存
	return TRUE; // 出队成功，返回 TRUE
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
	Node* p, * q;
	p = Q->front->next; // p 指向队列头部节点
	while (p != NULL) { // 遍历队列中的所有节点
		q = p->next; // q 指向 p 的下一个节点
		free(p); // 释放 p 所占用的内存空间
		p = q; // 将 p 指向下一个节点
	}
	Q->front = Q->rear; // 恢复队列的初始状态
}


/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)) {
	Node* p = Q->front->next; // 指向队列头部节点
	while (p) { // 遍历队列中的所有节点
		foo(p->data); // 调用指针 foo，处理数据
		p = p->next; // 将 p 指向下一个节点
	}
	return TRUE; // 遍历成功，返回 TRUE
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q) {
	printf("%d ", *(int*)q);
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
 // LQUEUE_H_INCLUDED


