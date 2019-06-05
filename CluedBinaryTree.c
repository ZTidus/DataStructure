typedef int TElemType; // 树结点的数据类型
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
