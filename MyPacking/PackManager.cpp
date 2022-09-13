#include "PackManager.h"
#include "binPackingAlgorithm.h"
#include "stdlib.h"
#include "string"
#include "iostream"
#include "FileManager.h"
#include "glDraw.h"

int main()
{
	binPackingAlgorithm manager;

	//�������ڣ�ѡ��������ݼ�
	//------------------------------------------
	std::string filePath = FileManager::GetFilePath();
	if (filePath == "")
		return 0;
	vector<vector<int>> bInfo = FileManager::GetFileIntData(filePath);
	int i;
	for (i = 0; i < bInfo.size(); i++)
		manager.AddBlocks(bInfo[i][0], bInfo[i][1], bInfo[i][2]);
	                                                                
	//�����Ű��㷨
	//------------------------------------------
	//�����о��ΰ��������
	int sortType;
	cout << "*********************************" << endl;
	cout << "**  ��ѡ��װ������������㷨�� **" << endl;
	cout << "**  1.���ο������             **" << endl;
	cout << "**  2.���θ߶�����             **" << endl;
	cout << "**  3.�����������             **" << endl;
	cout << "**  4.������������(����)     **" << endl;
	cout << "**  ��������1                  **" << endl;
	cout << "*********************************" << endl;
	cin >> sortType;
	switch (sortType)
	{
		case 1:manager.SortByWidth(); break;
		case 2:manager.SortByHeight(); break;
		case 3:manager.SortByArea(); break;
		case 4: default:manager.SortByMaxside(); break;
	}

	cout << endl << "------------����ǰ------------" << endl;
	manager.PrintBlocks();
	cout << endl << "------------�����------------" << endl;
	manager.PrintBlocks();
	//������������
	manager.Fit();
	//��ӡ������
	cout << endl << "------------��ӡ���������------------" << endl;
	string prefix = "";
	manager.PrintTree(g_root, g_root, prefix);

	//opengl���ƽ��
	//------------------------------------------
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//������ʾģʽ
	glutInitWindowSize(g_maxW, g_maxH); //���ô��ڴ�С
	glutInitWindowPosition(200, 100);   //���ô�������Ļ�ϵ�λ�� 
	glutCreateWindow("�����Ű���"); //�������ڲ���������
	glutDisplayFunc(glDraw::render);   //ע����ʾ����ʱ�ص�����renderScene
	glutMouseFunc(glDraw::LBClick);
	glOrtho(0.0f, g_maxW, 0.0f, g_maxH, 1.0, -1.0);//���û���ʱ���������ֵ
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);   //ʹ�ð�ɫ��ձ�����
	glutMainLoop();     //��Ϣѭ�����������ϵͳ�ȵ���Ϣ��������̡�����¼��ȣ�

	cin >> prefix;//��ֹ����
	system("pause");
	return 0;
}