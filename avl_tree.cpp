#include <iostream>
#include <string>
#include <algorithm>
#include "avl_tree.h"

using namespace std;

//ͨ���ַ���ĩβ��ĸ�ж��ַ����Ƿ�ΪӢ�ĵ���
bool AvlTree::IsEnglish_(string str) {
	bool res;
	char first_ch = *str.begin();
	if (first_ch >= 'a' && first_ch <= 'z' || first_ch >= 'A' && first_ch <= 'Z') {
		res = true;
	}
	else {
		res = false;
	}

	return res;
}

//�ݹ��ȡ�ڵ�ĸ߶�
int AvlTree::GetHeight_(AvlTreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	int left_height = GetHeight_(root->left) + 1;
	int right_height = GetHeight_(root->right) + 1;

	return max(left_height, right_height);
}

//���ݽڵ�ĸ߶����Լ���ƽ������
int AvlTree::GetBalanceFactor_(AvlTreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	return GetHeight_(root->left) - GetHeight_(root->right);
}

//����һ�ö�����ʹ���Ϊƽ���������¸߶Ⱥ󷵻��µĸ��ڵ�
AvlTreeNode* AvlTree::LeftRotate_(AvlTreeNode* root) {
	AvlTreeNode* new_root = root->right;
	AvlTreeNode* new_son_right = new_root->left;

	root->right = new_son_right;
	new_root->left = root;

	return new_root;
}

//����һ�ö�����ʹ���Ϊƽ���������¸߶Ⱥ󷵻��µĸ��ڵ�
AvlTreeNode* AvlTree::RightRotate_(AvlTreeNode* root) {
	AvlTreeNode* new_root = root->left;
	AvlTreeNode* new_son_left = new_root->right;

	root->left = new_son_left;
	new_root->right = root;

	return new_root;
}

//����һ����ʹ�䱣��ƽ�⣬���ص��������ĸ��ڵ�
AvlTreeNode* AvlTree::BalanceTree_(AvlTreeNode* root) {
	int balance_factor = GetBalanceFactor_(root);
	//���������
	if (balance_factor < -1 && GetBalanceFactor_(root->right) < 0) {
		return LeftRotate_(root);
	}
	//���������
	if (balance_factor > 1 && GetBalanceFactor_(root->left) > 0) {
		return RightRotate_(root);
	}
	//�����������������
	if (balance_factor < -1 && GetBalanceFactor_(root->right) > 0) {
		root->right = RightRotate_(root->right);
		return LeftRotate_(root);
	}
	//�����������������
	if (balance_factor > 1 && GetBalanceFactor_(root->left) < 0) {
		root->left = LeftRotate_(root->left);
		return RightRotate_(root);
	}

	return root;
}

//��ƽ��������в���һ���ڵ㲢����ƽ�⣬���๹�캯������
//���ݼ��Ĵ�СѰ�Ҳ���λ�á���С�Ҵ�
//�ҵ�λ�ã��ݹ����������ڵ㲢����ƽ�������ĸ��ڵ�
AvlTreeNode* AvlTree::InsertNode_(AvlTreeNode* root, AvlTreeNode node) {
	if (root == NULL) {
		AvlTreeNode* new_node = new AvlTreeNode(node.key, node.val);
		return new_node;
	}
	if (node.key <= root->key) {
		root->left = InsertNode_(root->left, node);
	}
	else {
		root->right = InsertNode_(root->right, node);
	}

	return BalanceTree_(root);
}

//�ݹ��ͷ���ռ�õĶ�̬�ڴ�ռ�
void AvlTree::Release_(AvlTreeNode* root) {
	if (root == NULL) {
		return ;
	}

	Release_(root->left);
	Release_(root->right);
	delete root;
}

//�޲ι���
AvlTree::AvlTree() {
	root_ = NULL;
	del_val_ = "NOT_FIND";
}

//���캯��
//��ʼ����Ա����
//�����ֱ�洢�����ݺ�ֵ���ݵ�������� AVL ����
AvlTree::AvlTree(string key_array[], string val_array[], int length) {
	root_ = NULL;
	del_val_ = "NOT_FIND";
	AvlTreeNode temp_node;
	for (int i = 0; i < length; i++) {
		temp_node.key = key_array[i]; 
		temp_node.val = val_array[i];
		root_ = InsertNode_(root_, temp_node);
	}
}

//��������
//ͨ������ Release_ �����ͷ���ռ�õĶ�̬�ڴ�ռ�
AvlTree::~AvlTree() {
	Release_(root_);
}

//����������
void AvlTree::InOrderPrint_(AvlTreeNode* root) {
	if (root == NULL) {
		return ;
	}

	InOrderPrint_(root->left);
	cout << "key: " << root->key << endl;
	cout << "val: " << root->val << endl;
	InOrderPrint_(root->right);
}

//��ӡ���ڵ���������
void AvlTree::PrintData() {
	InOrderPrint_(root_);
}

//��ΪӢ��ʱ�Ĳ������
//�ݹ�ʵ��
//�� FindVal ������ GetVal ��������
string AvlTree::FindByEnglishKey_(AvlTreeNode* root, string goal_key) {
	if (root == NULL) {
		return "NOT_FIND";
	}
	else if (root->key < goal_key) {
		return FindByEnglishKey_(root->right, goal_key);
	}
	else if (root->key > goal_key) {
		return FindByEnglishKey_(root->left, goal_key);
	}
	else {
		return root->val;
	}
}

//���������Ƿ����ƥ��ļ�
bool AvlTree::FindVal(string goal_key) {
	if (goal_key.empty()) {
		return false;
	}
	else if (IsEnglish_(goal_key) == false) {
		return false;
	}

	bool res;
	string goal_val = FindByEnglishKey_(root_, goal_key);

	if (goal_val == "NOT_FIND") {
		res = false;
	}
	else {
		res = true;
	}

	return res;
}

//�õ���ƥ�������
string AvlTree::GetVal(string goal_key) {
	if (goal_key.empty()) {
		return "NOT_FIND";
	}
	else if (IsEnglish_(goal_key) == false) {
		return "NOT_SUPPORT_OTHER";
	}

	string goal_val = FindByEnglishKey_(root_, goal_key);

	return goal_val;
}

//���� InsertNode_ ����һ���ڵ�
void AvlTree::Insert(string key, string val) {
	AvlTreeNode node(key, val);
	InsertNode_(root_, node);
}

//��ͣ�ĵݹ�����
//�ҵ�ƽ�����е���С����Ӧ�Ľڵ�
//��������ڵ�ָ��
AvlTreeNode* AvlTree::GetMinNode_(AvlTreeNode* root) {
	if (root->left == NULL) {
		return root;
	}

	return GetMinNode_(root->left);
}

//ɾ��ָ���Ľڵ�
AvlTreeNode* AvlTree::DeleteNode_(AvlTreeNode* node) {
	del_val_ = node->val;
	//ΪҶ�ӽڵ�����
	if (node->left == NULL && node->right == NULL) {
		delete node;
		return NULL;
	}
	//������Ϊ�յ����
	else if (node->left == NULL) {
		AvlTreeNode* root = node->right;
		delete node;
		return root;
	} 
	//������Ϊ�յ����
	else if (node->right == NULL) {
		AvlTreeNode* root = node->left;
		delete node;
		return root;
	}
	//���������Էǿ�
	else {
		AvlTreeNode* right_min_node = GetMinNode_(node->right);
		swap(node->key, right_min_node->key);
		swap(node->val, right_min_node->val);
		node->right = Delete_(node->right, right_min_node->key);
		return node;
	}
}

//ɾ�����ж�Ӧ���Ľڵ�
//�������ӿڵ���
AvlTreeNode* AvlTree::Delete_(AvlTreeNode* root, string goal_key) {
	if (root == NULL) {
		return NULL;
	} 

	if (root->key > goal_key) {
		root->left = Delete_(root->left, goal_key);
		return root;
	}
	else if (root->key < goal_key) {
		root->right = Delete_(root->right, goal_key);
		return root;
	}
	else {
		root = DeleteNode_(root);
	}

	return BalanceTree_(root);
}

//ɾ����Ӧ���Ľڵ㣬���ر�ɾ���ڵ��ֵ
string AvlTree::Delete(string goal_key) {
	root_ = Delete_(root_, goal_key);

	return del_val_;
}
