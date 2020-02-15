#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int Status; // Status 为函数类型，值为函数结果状态代码,如OK
typedef char TElemType; // 树结点的数据类型

TElemType Nil = '#';

Status visit(TElemType e)
{
    printf("%c", e);
    return OK;
}

/* 二叉树的二叉线索存储结构定义 */
typedef enum {Link, Thread} PointerTag;
// Link == 0 时表示指向左右孩子指针
// Thread == 1 时表示指向前驱或后继的线索

typedef struct BiThrNode  // 二叉线索存储结点结构 
{
    TElemType data;  // 结点数据
    struct BiThrNode *lchild, *rchild; // 左右孩子指针
    PointerTag LTag;
    PointerTag RTag;  // 左右标志
} BiThrNode, *BiThrTree;

/* 中序遍历线索化 */
BiThrTree pre; // 全局变量，始终指向刚刚访问过的结点
void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild); // 递归左子树线索化
        if(!p->lchild) // 若本结点没有左孩子
        {
            p->LTag = Thread; // 前驱线索
            p->lchild = pre; // 左孩子指向前驱
        }
        if(!pre->rchild) // 若前驱没有右孩子
        {
            pre->RTag = Thread; // 后继线索
            pre->rchild = p; // 前驱右孩子指针指向后继p
        }
        pre = p; // 将当前结点赋值給p，以便下一次使用
        InThreading(p->rchild); // 递归右子树线索化
    }
}

/* 中序遍历二叉树T， 并将其中序线索化， Thrt指向头结点 */
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
    *Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
    if(!*Thrt)
        exit(OVERFLOW);
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Link;
    (*Thrt)->rchild = (*Thrt);  // 右指针回指
    if(!T)  // 若二叉树为空，则左指着回指
        (*Thrt)->lchild = *Thrt;
    else
    {
        (*Thrt)->lchild = T;
        pre = (*Thrt);
        InThreading(T);
        pre->rchild = *Thrt;
        pre->RTag = Thread;
        (*Thrt)->rchild = pre;
    }
    return OK;
}
    
/* 中序遍历二叉线索链表 */
Status InOrderTraverse_Thr(BiThrTree T) // T指向头结点
{
    BiThrTree p;
    p = T->lchild;  // p指向跟结点
    while(p != T)  // 当p不指向头结点时
    {
        while(p->LTag == Link)  // p->LTag == 0
            p = p->lchild;
        if(!visit(p->data))  
            return ERROR;
        while(p->RTag == Thread && p->rchild != T)
        // 当p->RTag == 1且p不指向头结点
        {
            p = p->rchild;
            visit(p->data);
        }
        p = p->rchild;
    }
    return OK;
}

/* 按前序输入二叉线索树中结点的值，构造二叉线索树T */
/* 0(int)/空格(char)表示空结点 */
Status CreateBiThrTree(BiThrTree *T)
{
    TElemType h;
    scanf("%c", &h);

    if(h == '#')
        *T = NULL;
    else
    {
        *T = (BiThrTree)malloc(sizeof(BiThrNode));
        if(!*T)
            exit(OVERFLOW);
        (*T)->data = h; // 生成根结点
        CreateBiThrTree(&(*T)->lchild); // 递归构造左子树
        if((*T)->lchild) // 有做孩子
            (*T)->LTag = Link;
        CreateBiThrTree(&(*T)->rchild); // 递归构造右子树
        if((*T)->rchild) // 有右孩子
            (*T)->RTag = Link;
    }
}

int main() 
{
    BiThrTree H, T;
    printf("按前序输入二叉树(eg. 'ABDH##I##EJ###CF##G##')\n");
    CreateBiThrTree(&T);
    InOrderThreading(&H, T);
    printf("中序遍历二叉线索树：\n");
        InOrderTraverse_Thr(H);
    printf("\n");
    
    return 0;
}
