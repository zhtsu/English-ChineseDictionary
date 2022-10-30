#pragma once
#ifndef __AVLTREENODE__H__
#define __AVLTREENODE__H__

#include <iostream>

using namespace std;

//AVL���ڵ�Ľṹ
//���˱�Ҫ�Ľڵ�ָ���⣬
//�洢 2 �����ݣ��� key��ֵ val
//���ļ����� avl_tree.h �ļ�����
struct AvlTreeNode {
	string key;
	string val;
	AvlTreeNode* left;
	AvlTreeNode* right;

	//�ṹ�幹�캯��
	AvlTreeNode() : left(NULL), right(NULL) { }
	AvlTreeNode(string node_key, string node_val)
		: key(node_key), val(node_val),
		left(NULL), right(NULL) { }
};

#endif // !__AVLTREENODE__H__
