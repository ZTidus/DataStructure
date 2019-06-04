/* 树的双亲表示法结点结构定义 */
# define MAX_TREE_SIZE 100
typedef int TElementType; // 树结点的数据类型
typedef struct PTNode     // 结点结构
{
    TElementType data;    // 结点数据
    int parent;           // 双亲在数组中的位置
} PTNode;
typedef struct            // 树结构
{
    PTNode nodes[MAX_TREE_SIZE]; // 结点数组
    int r, n;                    // 根的位置和结点数
} PTree;

/* 树的孩子表示法结构定义 */
# define MAX_TREE_SIZE 100
typedef struct CTNode  // 孩子结点
{
    int child;
    struct CTNode *next;
} *ChildPtr;
typedef struct         // 表头结构
{
    TElementType data;
    ChildPtr firstchild;
} CTBox;
typedef struct         // 树结构
{
    CTBox nodes[MAX_TREE_SIZE];  // 结点数组
    int r, n;                    // 根的位置和结点数
} CTree;

/* 树的孩子兄弟表示法 */
typedef struct CSNode
{
    TElementType data;
    struct CSNode *firstchild, *rightsib;
} CSNode, *CSTree;

/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode  // 结点结构
{
    TElementType data;  // 结点数据
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

