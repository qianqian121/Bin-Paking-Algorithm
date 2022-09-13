#pragma once

#include <string>
#include "PackStruct.h"
#include "vector"
using namespace std;

class binPackingAlgorithm
{
public:

	int curX = 0;//��ǰ����x
	int curY = 0;//��ǰ����y
	vector<vector<int>> blocks;//������еľ��δ�С

	//�ظ����һ��������ͬһ����
	void AddBlocks(int width, int height, int num);

	//���������
	BlockTree* CreateNode(int x, int y, int w, int h);
/*	BlockTree * CopyNodeValue(BlockTree * node);//���Ʒ�����ʱ*/

	//������νڵ�
	void SplitNode(BlockTree* targetNode, BlockTree* tempNode);//�Զ���������ʽ���Target����Ϊ������
	BlockTree* GrowNode(BlockTree* block);//���ݹ����������
	BlockTree* GrowRight(BlockTree* block);
	BlockTree* GrowDown(BlockTree* block);
	void Fit();//�������о���
	BlockTree* FindNode(BlockTree* leafNode, int fitW, int fitH);//Ϊ����Ѱ�Һ��ʵ�λ��

	//����Ҷ������
	void InsertListNode(BlockTree * deletePos, BlockTree* insertLeft, BlockTree* insertRight);
	void DeleteListNode(BlockTree* node);


	//�����㷨
	void SortByWidth();
	void SortByHeight();
	void SortByArea();//��������������
	void SortByMaxside();//ȡ��������е����ߣ����бȽ�

	//��ӡ���о����������
	void PrintBlocks();
	void PrintTree(BlockTree * parent, BlockTree * node, string & prefix);\
};

