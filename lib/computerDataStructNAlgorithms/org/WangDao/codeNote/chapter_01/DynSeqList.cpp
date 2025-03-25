#include <stdio.h>
#include <stdlib.h>

using ElemType = int; // 待定数据类型
using ClassType = DynSeqList; // 待定结构类型
using Unknown = void;

// 动态顺序表基础结构
# define INITSIZE 10 // 宏定义：默认数组初始长度
typedef struct
{
    ElemType *data; // 动态数组数据首指针
    int maxSize; // 数组最大长度
    int length; // 有效数据量长度
}DynSeqList;

// 线性表的基本操作
void InitList(ClassType &L); // 初始化表
void DestroyList(ClassType &L); // 销毁表

// 线性表的常用操作
void PrintList(ClassType L); // 打印动态顺序表
void IncreaseListSize(ClassType &L, int len); // 增加动态顺序表的长度

// 应用
void run(){
    // 创建
    DynSeqList L; // 声明动态顺序表
    InitList(L); // 初始化动态顺序表

    // 输出
    PrintList(L);

    return;
}

// 函数实现
void InitList(ClassType &L)
{
    L.data = (ElemType *)malloc(sizeof(ElemType) * INITSIZE); // 分配空间
    L.length = 0; // 动态顺序表的初始大小为0
    L.maxSize = INITSIZE; // 动态顺序表的最大大小为初始值
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

void IncreaseListSize(ClassType &L, int len)
{
    // ElemType 
}
