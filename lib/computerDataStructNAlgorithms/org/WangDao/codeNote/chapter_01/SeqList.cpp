#include <stdio.h>

using ElemType = int; // 待定数据类型
using ClassType = SeqList; // 待定结构类型
using Unknown = void;

// 静态顺序表基础结构
# define MAXSIZE 10 // 宏定义：默认数组最大长度
typedef struct
{
    ElemType data[MAXSIZE]; // 静态数组数据
    int length; // 有效数据量长度
}SeqList;

// 线性表的基本操作
void InitList(ClassType &L); // 初始化表
void DestroyList(ClassType &L); // 销毁表

// 线性表的常用操作
void PrintList(ClassType L); // 打印顺序表

// 应用
void run(){
    // 创建
    SeqList L; // 声明顺序表
    InitList(L); // 初始化顺序表

    // 输出
    PrintList(L);

    return;
}

// 函数实现
void InitList(ClassType &L)
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        L.data[i] = 0; // 将所有的数据元素设为默认的初始值

    }
    L.length = 0; // 顺序表的初始大小为0
}

void PrintList(ClassType L)
{
    //  for (int i = 0; i < MAXSIZE; i++) // 非法操作，这样会导致打印脏数据
    //                       ⬇
    for (int i = 0; i < L.length; i++) // 这样只会打印有效数据
    {
        printf("data[%d] = %d\n", i, L.data);
    }
    
}
