
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

// KMP查找算法
int Index_KMP(ClassType S, ClassType T, int next[]);

// 实现
int Index_KMP(ClassType S, ClassType T, int next[])
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
