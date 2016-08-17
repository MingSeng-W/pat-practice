//length of biBitree
// 求二叉树的高度
#include "stdio.h"
#include "stdlib.h"
typedef struct BiNode *BiTree;
typedef int  ElememtType;

struct BiNode{
    ElememtType data;
    BiTree left;
    BiTree right;
};
