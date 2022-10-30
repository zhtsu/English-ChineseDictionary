#pragma once
#ifndef __AVLTREE__H__
#define __AVLTREE__H__

#include <iostream>
#include "avl_tree_node.h"

using namespace std;

//AVL���࣬�洢����ĵ�������
//�ṩ��ɾ�����
class AvlTree {
public:
	AvlTree();
	AvlTree(string key_array[], string val_array[], int length);
	~AvlTree();

public:
	//��ӡ���洢������
	void PrintData();
	//��������
	bool FindVal(string goal_key);
	//�õ�����
	string GetVal(string goal_key);
	//��������
	void Insert(string key, string val);
	//ɾ������
	string Delete(string goal_key);

private:
	//�ж��ַ����Ƿ�ΪӢ�ĵ���
	bool IsEnglish_(string str);
	//��������������
	void InOrderPrint_(AvlTreeNode* root);
	//��ֵΪӢ�ĵ������������
	string FindByEnglishKey_(AvlTreeNode* root, string goal_key);
	//����ڵ�߶�
	int GetHeight_(AvlTreeNode* root);
	//����ƽ������
	int GetBalanceFactor_(AvlTreeNode* root);
	//��������ƽ��
	AvlTreeNode* BalanceTree_(AvlTreeNode* root);
	//����ƽ��
	AvlTreeNode* LeftRotate_(AvlTreeNode* root);
	//����ƽ��
	AvlTreeNode* RightRotate_(AvlTreeNode* root);
	//����ڵ�
	AvlTreeNode* InsertNode_(AvlTreeNode* root, AvlTreeNode node);
	//�õ�һ�����е���С����Ӧ�Ľڵ�
	AvlTreeNode* GetMinNode_(AvlTreeNode* root);
	//ɾ���ڵ�ָ��ָ��Ľڵ�
	AvlTreeNode* DeleteNode_(AvlTreeNode* node);
	//ɾ���ڵ�
	AvlTreeNode* Delete_(AvlTreeNode* root, string goal_key);
	//�ͷ��ڴ�
	void Release_(AvlTreeNode* root);

private:
	//AVL���ĸ��ڵ�
	AvlTreeNode* root_;
	//�洢ÿ�α�ɾ���Ľڵ�ֵ
	string del_val_;
};

#endif // !__AVLTREE__H__
