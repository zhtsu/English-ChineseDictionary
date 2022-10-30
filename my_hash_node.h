#pragma once
#ifndef __MYHASHNODE__H__
#define __MYHASHNODE__H__

#include <iostream>

using namespace std;

//ʹ����������Ϊ��ͻ����Ĺ�ϣ��Ľڵ�ṹ
//���˱�Ҫ�Ľڵ�ָ���⣬
//�洢 2 �����ݣ��� key�� ֵ val
//���ļ����� my_hash.h �ļ�����
struct MyHashNode {
	string key;
	string val;
	MyHashNode* next;

	//�ṹ�幹�캯��
	MyHashNode() : next(NULL) { }
	MyHashNode(string node_key, string node_val)
		: key(node_key), val(node_val), 
		next(NULL) { }
};

#endif // !__MYHASHNODE__H__
