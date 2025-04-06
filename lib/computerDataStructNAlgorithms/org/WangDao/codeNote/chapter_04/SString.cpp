
using ElemType = int; // 待定数据类型
using ClassType = SString; // 待定结构类型
using Unknown = void;

// 串基础结构
#define MAXSIZE 100
typedef struct 
{
    /* data */
    ElemType ch[MAXSIZE];
    int length;
}SString;

// 串的基本操作
Unknown Destroy(ClassType &S); // 销毁串

// 串的基本算法
Unknown StrAssign(ClassType &T, char chars[]); // 赋值串
Unknown StrCopy(ClassType &T, ClassType S); // 复制串
Unknown StrConcat(ClassType &T, ClassType S1, ClassType S2); // 连接串

Unknown StrClean(ClassType &S); // 清空串

Unknown StrLocate(ClassType S, ClassType key); // 按值定位子串
Unknown StrSubGet(ClassType &Sub, ClassType S, int pos, int len); // 按序查找子串

// 串的常用操作
Unknown StrEmpty(ClassType S); // 判定空串
Unknown StrLength(ClassType S); // 求串长
Unknown StrCompare(ClassType S1, ClassType S2); // 比较串

// KMP查找算法
int StrIndex_KMP(ClassType S, ClassType T, int next[]);

// 实现
int StrIndex_KMP(ClassType S, ClassType T, int next[])
{
    int i=1, j=1;
    while (i<=S.length&&j<=T.length)
    {
        if (j==0||S.ch[i]==T.ch[j]) // 逐一比对
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j>T.length)
        return i-T.length;
    else
        return 0;
}
