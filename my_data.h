#pragma once
#ifndef __MY_DATA__H__
#define __MY_DATA__H__

#include <iostream>
#include "my_file.h"
#include "avl_tree.h"
#include "my_hash.h"

using namespace std;

//��Ź�ϣ���ƽ����������ڵ���������
class MyData {
public:
	MyData();
	~MyData();

public:
	string AvlTreeSearch(string english);
	string MyHashSearch(string english);
	string AddData(string english, string chinese);
	string DeleteData(string key);

private:
	AvlTree* avl_tree_[26];
	MyHash* my_hash_[26];
};

#endif // !__MY_DATA__H__
