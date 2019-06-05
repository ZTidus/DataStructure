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

