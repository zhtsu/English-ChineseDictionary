#include <iostream>
#include <algorithm>
#include <string>
#include "my_hash.h"

using namespace std;

//ͨ���ַ�������ĸ�ж��ַ����Ƿ�ΪӢ�ĵ���
bool MyHash::IsEnglish_(string str) {
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

//���ݵ����в�ͬ��Ӣ����ĸ�ĸ������㵥���ڱ��ж�Ӧ��Ͱ��
int MyHash::GetEnglishKeyIn_(string str) {
	//ȥ��
	for (int i = 0; i < str.size() - 1; i++) {
		for (int j = i  + 1; j < str.size(); j++) {
			if (str[j] == str[i]) {
				str.erase(j, 1);
				j--;
			}
		}
	}

	return str.size();
}

//���ر������ݵ�������
int MyHash::get_length() {
	return length_;
}

//���ݼ�ֵ�����ϣ���в���һ���ڵ�
void MyHash::Insert(string english, string chinese) {
	int in = GetEnglishKeyIn_(english) % kMaxSize;

	MyHashNode* new_node = new MyHashNode(english, chinese);
	MyHashNode* p = buckets_[in];
	while (p->next != NULL && p->next->key < new_node->key) {
		p = p->next;
	}
	new_node->next = p->next;
	p->next = new_node;
}

//�޲ι���
MyHash::MyHash() {
	length_ = 0;
	for (int i = 0; i < kMaxSize; i++) {
		buckets_[i] = new MyHashNode;
	}
}

//���캯��
//������ͷָ�����飨Ͱ������ֵ
//���ֱ�洢����ֵ������洢��������
MyHash::MyHash(string key_array[], string val_array[], int length) {
	length_ = length;
	for (int i = 0; i < kMaxSize; i++) {
		buckets_[i] = new MyHashNode;
	}

	for (int i = 0; i < length; i++) {
		Insert(key_array[i], val_array[i]);
	}
}

//��������
//�ͷŹ�ϣ�������ռ�õĶ�̬�ڴ�ռ�
MyHash::~MyHash() {
	for (int i = 0; i < kMaxSize; i++) {
		MyHashNode* new_head = NULL;
		for (MyHashNode* p = buckets_[i]; p != NULL; p = new_head) {
			new_head = p->next;
			delete p;
		}
	}
}

//��ӡ����ϣ���ڴ洢������
void MyHash::PrintList() {
	for (int i = 0; i < kMaxSize; i++) {
		cout << i << endl;
		for (MyHashNode* p = buckets_[i]->next; p != NULL; p = p->next) {
			cout << "key:" << p->key << endl;
			cout << "val:" << p->val << endl;
		}
	}
}

//���ұ����Ƿ����ƥ��ļ�
bool MyHash::FindVal(string goal_key) {
	if (goal_key.empty()) {
		return false;
	}
	else if (IsEnglish_(goal_key) == false) {
		return false;
	}

	bool is_find = false;

	int in = GetEnglishKeyIn_(goal_key) % kMaxSize;
	MyHashNode* p = buckets_[in]->next;
	while (p != NULL && p->key != goal_key) {
		p = p->next;
	}

	if (p != NULL) {
		is_find = true;
	}

	return is_find;
}

//�ӱ��з��ض�Ӧ�� key ��ֵ
//��δ�ڱ����ҵ���Ӧ�� key
//����һ����NOT_FIND���ַ���
//�����ҵĵ��ʲ�ΪӢ�ģ��򷵻�һ�� "NOT_SUPPORT_OTHER" �ַ���
string MyHash::GetVal(string goal_key) {
	if (goal_key.empty()) {
		return "NOT_FIND";
	}
	else if (IsEnglish_(goal_key) == false) {
		return "NOT_SUPPORT_OTHER";
	}

	string res = "NOT_FIND";
	int in = GetEnglishKeyIn_(goal_key) % kMaxSize;
	MyHashNode* p = buckets_[in]->next;
	while (p != NULL && p->key != goal_key) {
		p = p->next;
	}

	if (p != NULL) {
		res = p->val;
	}

	return res;
}

//���ݼ�ɾ�����ж�Ӧ�Ľڵ�
//���ر�ɾ���ڵ��ֵ
//���ڵ㲻���ڱ��У�����һ�� "NOT_FIND" �ַ���
string MyHash::Delete(string key) {
	string del_val = "NOT_FIND";

	int in = GetEnglishKeyIn_(key) % kMaxSize;
	MyHashNode* p = buckets_[in]->next;
	while (p != NULL && p->next != NULL && p->next->key != key) {
		p = p->next;
	}
	if (p != NULL && p->next != NULL) {
		MyHashNode* del_node = p->next;
		del_val = del_node->val;
		p->next = p->next->next;
		delete del_node;
	}

	return del_val;
}

//������ָ�����������ݿ����� 2 ��������
//�����������ݽ�����������
void MyHash::CopyDataTo(string key_array[], string val_array[], int length) {
	int pos = 0;

	for (int i = 0; i < kMaxSize; i++) {
		MyHashNode* p = buckets_[i]->next;
		while (p != NULL) {
			key_array[pos] = p->key;
			val_array[pos] = p->val;
			pos++;
			p = p->next;
		}
	}

	//����
	sort(key_array, key_array + length);
	sort(val_array, val_array + length);
}