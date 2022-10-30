#pragma once
#ifndef __MYHASH__H__
#define __MYHASH__H__

#include <iostream>
#include "my_hash_node.h"

using namespace std;

//����ϣ���Ͱ�����������ͬʱҲ�ǹ�ϣ���������ʹ�õ�ģ
const int kMaxSize = 10;

//����ϣ���࣬�洢����ĵ�������
//���洢ͬһ��ĸ��ͷ�ĵ���
//����ÿ������Ӣ���ַ������ġ���ֵ����ʹ�ó�����������Ϊ��ϣ����
//�ṩ��ɾ���������ֻ֧�ֲ�ѯӢ�ĵ���
class MyHash {
public:
	MyHash();
	MyHash(string key_array[], string val_array[], int length);
	~MyHash();

public:
	//��ӡ����
	void PrintList();
	//��������
	bool FindVal(string key);
	//�õ�����
	string GetVal(string key);
	//����һ���ڵ�
	void Insert(string english, string chinese);
	//ɾ��һ���ڵ�
	string Delete(string key);
	//�õ��������ݵ�������
	int get_length();
	//������������
	void CopyDataTo(string array[], string val_array[], int length);

private:
	//����ַ����Ƿ�ΪӢ��
	bool IsEnglish_(string str);
	//����һ��Ӣ���ַ�����Ӧ��ϣ���ڵ�Ͱ��
	int GetEnglishKeyIn_(string str);

private:
	//��¼���ݵ�����
	int length_;
	//�洢ͬ��ĸ��ͷ�ĵ��ʵĹ�ϣͰ
	MyHashNode* buckets_[kMaxSize];
};

#endif // !__MYHASH__H__
