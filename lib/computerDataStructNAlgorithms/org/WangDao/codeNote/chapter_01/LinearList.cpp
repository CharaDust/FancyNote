
using ElemType = int; // 待定数据类型
using ClassType = int; // 待定结构类型
using Unknown = void;

// 线性表的基本操作
void InitList(ClassType &L); // 初始化表
void DestroyList(ClassType &L); // 销毁表

// 线性表的基本运算
Unknown ListInsert(ElemType &L, int index, ElemType elem); // 插入元素
Unknown ListDelete(ElemType &L, int index, ElemType &elem); // 删除元素
Unknown LocateElem(ElemType L, ElemType key); // 按值查找
Unknown LocateElem(ElemType L, int order); // 按序查找

// 线性表的常用操作
int LengthList(ElemType L); // 求线性表长
void PrintList(ClassType L); // 打印线性表
bool EmptyList(ElemType L); // 判定空线性表
