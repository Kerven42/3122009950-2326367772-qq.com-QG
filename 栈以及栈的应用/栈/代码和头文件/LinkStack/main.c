#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h" 

#define MAXSIZE 100   // 栈的最大容量

typedef int ElemType;  // 定义元素类型


typedef enum
{
    FALSE = 0, TRUE = 1
} Status;


int main(void) {
    LinkStack stack;

    int option, length;
    ElemType data;

    initLStack(&stack);

    printf("请按照以下数字输入相应指令：\n");
    printf("1. 入栈操作\n");
    printf("2. 出栈操作\n");
    printf("3. 获取栈顶元素\n");
    printf("4. 判断栈是否为空\n");
    printf("5. 获取栈的长度\n");
    printf("6. 清空栈\n");
    printf("7. 销毁栈\n");
    printf("0. 退出程序\n");

    do {
        printf("\n请输入操作数字：");
        scanf_s("%d", &option);

        switch (option) {
        case 1:
            printf("请输入需要入栈的元素：");
            scanf_s("%d", &data);
            if (pushLStack(&stack, data)) {
                printf("入栈成功！\n");
            }
            else {
                printf("入栈失败！\n");
            }
            break;
        case 2:
            if (popLStack(&stack, &data)) {
                printf("出栈成功，弹出的元素为：%d\n", data);
            }
            else {
                printf("出栈失败！\n");
            }
            break;
        case 3:
            if (getTopLStack(&stack, &data)) {
                printf("栈顶元素为：%d\n", data);
            }
            else {
                printf("获取栈顶元素失败！\n");
            }
            break;
        case 4:
            if (isEmptyLStack(&stack)) {
                printf("栈为空栈！\n");
            }
            else {
                printf("栈不为空栈！\n");
            }
            break;
        case 5:
            if (LStackLength(&stack, &length)) {
                printf("栈的长度为：%d\n", length);
            }
            else {
                printf("获取栈的长度失败！\n");
            }
            break;
        case 6:
            if (clearLStack(&stack)) {
                printf("栈已清空！\n");
            }
            else {
                printf("栈清空失败！\n");
            }
            break;
        case 7:
            if (destroyLStack(&stack)) {
                printf("栈已销毁！\n");
            }
            else {
                printf("栈销毁失败！\n");
            }
            break;
        case 0:
            printf("程序已退出！\n");
            break;
        default:
            printf("输入的操作数字无效，请重新输入！\n");
            break;
        }
    } while (option != 0);

    return 0;
}

