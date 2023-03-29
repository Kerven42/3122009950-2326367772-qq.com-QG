#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h" 

#define MAXSIZE 100   // ջ���������

typedef int ElemType;  // ����Ԫ������


typedef enum
{
    FALSE = 0, TRUE = 1
} Status;


int main(void) {
    LinkStack stack;

    int option, length;
    ElemType data;

    initLStack(&stack);

    printf("�밴����������������Ӧָ�\n");
    printf("1. ��ջ����\n");
    printf("2. ��ջ����\n");
    printf("3. ��ȡջ��Ԫ��\n");
    printf("4. �ж�ջ�Ƿ�Ϊ��\n");
    printf("5. ��ȡջ�ĳ���\n");
    printf("6. ���ջ\n");
    printf("7. ����ջ\n");
    printf("0. �˳�����\n");

    do {
        printf("\n������������֣�");
        scanf_s("%d", &option);

        switch (option) {
        case 1:
            printf("��������Ҫ��ջ��Ԫ�أ�");
            scanf_s("%d", &data);
            if (pushLStack(&stack, data)) {
                printf("��ջ�ɹ���\n");
            }
            else {
                printf("��ջʧ�ܣ�\n");
            }
            break;
        case 2:
            if (popLStack(&stack, &data)) {
                printf("��ջ�ɹ���������Ԫ��Ϊ��%d\n", data);
            }
            else {
                printf("��ջʧ�ܣ�\n");
            }
            break;
        case 3:
            if (getTopLStack(&stack, &data)) {
                printf("ջ��Ԫ��Ϊ��%d\n", data);
            }
            else {
                printf("��ȡջ��Ԫ��ʧ�ܣ�\n");
            }
            break;
        case 4:
            if (isEmptyLStack(&stack)) {
                printf("ջΪ��ջ��\n");
            }
            else {
                printf("ջ��Ϊ��ջ��\n");
            }
            break;
        case 5:
            if (LStackLength(&stack, &length)) {
                printf("ջ�ĳ���Ϊ��%d\n", length);
            }
            else {
                printf("��ȡջ�ĳ���ʧ�ܣ�\n");
            }
            break;
        case 6:
            if (clearLStack(&stack)) {
                printf("ջ����գ�\n");
            }
            else {
                printf("ջ���ʧ�ܣ�\n");
            }
            break;
        case 7:
            if (destroyLStack(&stack)) {
                printf("ջ�����٣�\n");
            }
            else {
                printf("ջ����ʧ�ܣ�\n");
            }
            break;
        case 0:
            printf("�������˳���\n");
            break;
        default:
            printf("����Ĳ���������Ч�����������룡\n");
            break;
        }
    } while (option != 0);

    return 0;
}

