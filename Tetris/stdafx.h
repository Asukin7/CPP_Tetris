#pragma once
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define KUANG 14
#define GAO 22
#define SD 520

void start();//��ʼ��Ϸ����ʼ��
int tetris_j();//�ж���Ϸ�Ƿ�������Ƿ���1���񷵻�0��
void tetris_scxd();//�����µĶ���˹���鵽Ԥ��
void tetris_dyxd();//ȡԤ����ӡ�µĶ���˹����
void tetris_dydqsj(int ai_kg);//��ӡ��ǰ����˹��������
void tetris_dydqta();//��ӡ��ǰ����˹����ͼ��
void tetris_qcdq(int ai_kg);//�����ǰ����˹����
void tetris_qcyh();//���һ�ж���˹����
int tetris_xz(int ai_kg);//��ת����˹����
int tetris_fx(char fx, int ai_kg);//ѡ����ת�������ҷ����ƶ�
int tetris_j_fx(char fx, int ai_kg);//�ж��Ƿ�������ҷ����ƶ����Ƿ���1���񷵻�0��

int cz();//���̲����Լ��Զ�����
void kz();//��ȡ���̲������ƶ���˹����

void gotoxy(int x, int y);//�ƶ����

int ij[GAO][KUANG];//ȫ�ַ�������
int n;//���浱ǰ�Ķ���˹������
int x;//������һ������˹������
int temp[4][4];//4*4��ʱ����
int yl[4][4];//4*4Ԥ��
int tetris_x;//4*4���ϽǺ�����
int tetris_y;//4*4���Ͻ�������

int dj = 1;//��ǰ�ȼ�
int jf = 0;//��ǰ����

int tetris1[4][4] = { { 0,0,0,0 },{ 0,1,1,0 },{ 0,1,1,0 },{ 0,0,0,0 } };//��-1
int tetris2[4][4] = { { 0,0,0,0 },{ 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } };//һ-1
int tetris3[4][4] = { { 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 } };//һ-2
int tetris4[4][4] = { { 0,1,0,0 },{ 0,1,1,0 },{ 0,0,1,0 },{ 0,0,0,0 } };//Z1-1
int tetris5[4][4] = { { 0,0,0,0 },{ 0,0,1,1 },{ 0,1,1,0 },{ 0,0,0,0 } };//Z1-2
int tetris6[4][4] = { { 0,0,1,0 },{ 0,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 } };//Z2-1
int tetris7[4][4] = { { 0,0,0,0 },{ 0,1,1,0 },{ 0,0,1,1 },{ 0,0,0,0 } };//Z2-2
int tetris8[4][4] = { { 0,0,0,0 },{ 0,0,1,0 },{ 0,1,1,1 },{ 0,0,0,0 } };//T-1
int tetris9[4][4] = { { 0,1,0,0 },{ 0,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 } };//T-2
int tetris10[4][4] = { { 0,0,0,0 },{ 0,1,1,1 },{ 0,0,1,0 },{ 0,0,0,0 } };//T-3
int tetris11[4][4] = { { 0,0,1,0 },{ 0,1,1,0 },{ 0,0,1,0 },{ 0,0,0,0 } };//T-4
int tetris12[4][4] = { { 0,0,0,0 },{ 0,1,1,1 },{ 0,1,0,0 },{ 0,0,0,0 } };//L1-1
int tetris13[4][4] = { { 0,1,1,0 },{ 0,0,1,0 },{ 0,0,1,0 },{ 0,0,0,0 } };//L1-2
int tetris14[4][4] = { { 0,0,0,0 },{ 0,0,0,1 },{ 0,1,1,1 },{ 0,0,0,0 } };//L1-3
int tetris15[4][4] = { { 0,1,0,0 },{ 0,1,0,0 },{ 0,1,1,0 },{ 0,0,0,0 } };//L1-4
int tetris16[4][4] = { { 0,0,0,0 },{ 0,1,1,1 },{ 0,0,0,1 },{ 0,0,0,0 } };//L2-1
int tetris17[4][4] = { { 0,0,1,0 },{ 0,0,1,0 },{ 0,1,1,0 },{ 0,0,0,0 } };//L2-2
int tetris18[4][4] = { { 0,0,0,0 },{ 0,1,0,0 },{ 0,1,1,1 },{ 0,0,0,0 } };//L2-3
int tetris19[4][4] = { { 0,1,1,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 0,0,0,0 } };//L2-4

void ai();//���Բ���
void ai_mn();//ģ��������������������Ȩ
void ai_cz();//�������Ȩ����

double quanzhi();//���º���֮��
double LandingHeight();//(���+���)/2*-4.500158825082766
double ErodedPieceCells();//��������*���鹱��*3.4181268101392694
double RowTransitions();//�����з������ޱ仯����*-3.2178882868487753
double ColumTransitions();//�����з������ޱ仯����*-9.348695305445199
double NumberOfHoles();//�ն���*-7.899265427351652
double WellSum();//�ܡ�����ֵ*-3.3855972247263626

int ai_ij[GAO][KUANG];
int ai_n;
int ai_temp[4][4];
int ai_tetris_x;
int ai_tetris_y;

double ai_qz;
int ai_xz;
int ai_lr;

void msxz();//ѡ��ģʽ��1��AI 0��PLAYER��
int ms = -1;