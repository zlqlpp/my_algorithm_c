//https://www.runoob.com/data-structures/data-structures-tutorial.html
//
//
//常见的数据结构
//栈（Stack）：栈是一种特殊的线性表，它只能在一个表的一个固定端进行数据结点的插入和删除操作。
//队列（Queue）：队列和栈类似，也是一种特殊的线性表。和栈不同的是，队列只允许在表的一端进行插入操作，而在另一端进行删除操作。
//数组（Array）：数组是一种聚合数据类型，它是将具有相同类型的若干变量有序地组织在一起的集合。
//链表（Linked List）：链表是一种数据元素按照链式存储结构进行存储的数据结构，这种存储结构具有在物理上存在非连续的特点。
//树（Tree）：树是典型的非线性结构，它是包括，2 个结点的有穷集合 K。
//图（Graph）：图是另一种非线性数据结构。在图结构中，数据结点一般称为顶点，而边是顶点的有序偶对。
//堆（Heap）：堆是一种特殊的树形数据结构，一般讨论的堆都是二叉堆。
//散列表（Hash table）：散列表源自于散列函数(Hash function)，其思想是如果在结构中存在关键字和T相等的记录，那么必定在F(T)的存储位置可以找到该记录，这样就可以不用进行比较操作而直接取得所查记录。
//
//常用算法
//数据结构研究的内容：就是如何按一定的逻辑结构，把数据组织起来，并选择适当的存储表示方法把逻辑结构组织好的数据存储到计算机的存储器里。算法研究的目的是为了更有效的处理数据，提高数据运算效率。数据的运算是定义在数据的逻辑结构上，但运算的具体实现要在存储结构上进行。一般有以下几种常用运算：
//
//检索：检索就是在数据结构里查找满足一定条件的节点。一般是给定一个某字段的值，找具有该字段值的节点。
//插入：往数据结构中增加新的节点。
//删除：把指定的结点从数据结构中去掉。
//更新：改变指定节点的一个或多个字段的值。
//排序：把节点按某种指定的顺序重新排列。例如递增或递减。


#include <cstdlib>
#include <stdio.h>
#include <iostream>
  
using namespace std;
  
//树的结点
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} Node;
  
//树根
typedef struct {
    Node* root;
} Tree;
  
//创建树--插入数据
void insert(Tree* tree, int value){
    //创建一个节点，让左右指针全部指向空，数据为value
    Node* node=(Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
  
    //判断树是不是空树，如果是，直接让树根指向这一个结点即可
    if (tree->root == NULL){
        tree->root = node;
    } else {//不是空树
        Node* temp = tree->root;//从树根开始
        while (temp != NULL){
            if (value < temp->data){ //小于就进左儿子
                if (temp->left == NULL){
                    temp->left = node;
                    return;
                } else {//继续往下搜寻
                    temp = temp->left;
                }
            } else { //否则进右儿子
                if (temp->right == NULL){
                    temp->right = node;
                    return;
                }
                else {//继续往下搜寻
                    temp = temp->right;
                }
            }
        }
    }
    return;
}
  
  
  //树的先序遍历 Preorder traversal
void preorder(Node* node){
    if (node != NULL)
    {
        printf("%d ",node->data);
        inorder(node->left);
        inorder(node->right);
    }
}

//树的中序遍历 In-order traversal
void inorder(Node* node){
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}

//树的后序遍历 Post-order traversal
void postorder(Node* node){
    if (node != NULL)
    {
        inorder(node->left);
        inorder(node->right);
        printf("%d ",node->data);
    }
}


int main(){
    Tree tree;
    tree.root = NULL;//创建一个空树
    int n;
    scanf("%d",&n);
  
    //输入n个数并创建这个树
    for (int i = 0; i < n; i++){
        int temp;
        scanf("%d",&temp);
        insert(&tree, temp);
    }
  
    inorder(tree.root);//中序遍历
  
    return 0;
}