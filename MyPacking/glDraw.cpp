#include "glDraw.h"
#include "cstdlib"
#include "PackStruct.h"
#include "stack"
//#include "windows.h"

static stack<BlockTree*>sNode;

#define SHOW_ALL//�Ƿ�һ����ȫ������,�����������ʱ��ע�͸þ䣬���������������

void glDraw::render()
{
	glClear(GL_COLOR_BUFFER_BIT);//�����ɫ�����
#ifdef SHOW_ALL
	PreOrderTraverse(g_root);
	glRasterPos2f(30.0f, g_maxH - 30.f);//��������λ��
	DrawString(CalculateFilledArea(0, 0));
#else
	sNode.push(g_root);//��������ʾ
#endif
	glColor3f(0.0f, 0.0f, 1.0f);
	glutSwapBuffers();

	glFlush();
}


void glDraw::PreOrderTraverse(BlockTree* node)
{//�ݹ��������������
	if (node == NULL || node->isUsed == 0)
		return;
	//���ƾ��Σ��������½�x,y���Ͻ�x,y����
	DrawRectangle(node->cur.x, g_maxH - node->cur.y - node->cur.h, node->cur.x + node->cur.w, g_maxH - node->cur.y);
	CalculateFilledArea(node->cur.w, node->cur.h);//���㵱ǰ��������
	PreOrderTraverse(node->left);
	PreOrderTraverse(node->right);
}

void glDraw::StackPreOrderTraverse(BlockTree* node)
{//ÿ�����������ջ��һ���ڵ�ֵ
	if (node)
	{
		sNode.pop();
		if (node->isUsed)
			DrawRectangle(node->cur.x, g_maxH - node->cur.y - node->cur.h, node->cur.x + node->cur.w, g_maxH - node->cur.y);
		if (node->right)
			sNode.push(node->right);
		if (node->left)
			sNode.push(node->left);
	}
}

string glDraw::CalculateFilledArea(int width, int height)
 {
	 static int area;
	 area += width * height;//������ռ�õ������С
	 int percentage = (int)((double)area / (g_maxW*g_maxH) * 100);
	 return "Filled:" + to_string(percentage).append("%");//��int��string
 }

void glDraw::DrawRectangle(float leftBottomX, float leftBottomY, float rightTopX, float rightTopY)
{
	float v = 1.0 / RAND_MAX;
	glColor3f(rand()*v, rand()*v, rand()*v);//���������ɫ��ͼ
	glRectf(leftBottomX, leftBottomY, rightTopX, rightTopY);//���ƾ���
}

void glDraw::DrawString(string str)
{
	static int isFirstCall = 1;
	static GLuint lists;
	
	if (isFirstCall)
	{//��һ�ε���ʱ Ϊÿ��ASCII�ַ�����һ����ʾ�б�
		isFirstCall = 0;
		//����MAX__CHAR����������ʾ�б���
		lists = glGenLists(MAX_CHAR);
		//��ÿ���ַ��Ļ�������װ����Ӧ����ʾ�б���
//		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	}

	//����ÿ���ַ���Ӧ����ʾ�б�����ÿ���ַ�
	for (int i=0; i<str.length(); i++)
		glCallList(lists + str.at(i));
}

void glDraw::LBClick(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
		if (button == GLUT_LEFT_BUTTON)
		{
			if (!sNode.empty())
			{
				//CalculateFilledArea(sNode.top()->cur.w, sNode.top()->cur.h);
				StackPreOrderTraverse(sNode.top());
			}
			glFlush();
		} 
}