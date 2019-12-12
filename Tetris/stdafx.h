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

void start();//开始游戏并初始化
int tetris_j();//判断游戏是否结束（是返回1，否返回0）
void tetris_scxd();//生成新的俄罗斯方块到预览
void tetris_dyxd();//取预览打印新的俄罗斯方块
void tetris_dydqsj(int ai_kg);//打印当前俄罗斯方块数据
void tetris_dydqta();//打印当前俄罗斯方块图案
void tetris_qcdq(int ai_kg);//清除当前俄罗斯方块
void tetris_qcyh();//清除一行俄罗斯方块
int tetris_xz(int ai_kg);//旋转俄罗斯方块
int tetris_fx(char fx, int ai_kg);//选择旋转或下左右方向移动
int tetris_j_fx(char fx, int ai_kg);//判断是否可下左右方向移动（是返回1，否返回0）

int cz();//键盘操作以及自动下落
void kz();//获取键盘操作控制俄罗斯方块

void gotoxy(int x, int y);//移动光标

int ij[GAO][KUANG];//全局方块数据
int n;//储存当前的俄罗斯方块编号
int x;//储存下一个俄罗斯方块编号
int temp[4][4];//4*4临时储存
int yl[4][4];//4*4预览
int tetris_x;//4*4左上角横坐标
int tetris_y;//4*4左上角纵坐标

int dj = 1;//当前等级
int jf = 0;//当前积分

int tetris1[4][4] = { { 0,0,0,0 },{ 0,1,1,0 },{ 0,1,1,0 },{ 0,0,0,0 } };//田-1
int tetris2[4][4] = { { 0,0,0,0 },{ 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } };//一-1
int tetris3[4][4] = { { 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 } };//一-2
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

void ai();//电脑操作
void ai_mn();//模拟所有下落情况并求最大权
void ai_cz();//进行最大权操作

double quanzhi();//以下函数之和
double LandingHeight();//(最高+最低)/2*-4.500158825082766
double ErodedPieceCells();//消除行数*方块贡献*3.4181268101392694
double RowTransitions();//所有行方块有无变化次数*-3.2178882868487753
double ColumTransitions();//所有列方块有无变化次数*-9.348695305445199
double NumberOfHoles();//空洞数*-7.899265427351652
double WellSum();//总“井”值*-3.3855972247263626

int ai_ij[GAO][KUANG];
int ai_n;
int ai_temp[4][4];
int ai_tetris_x;
int ai_tetris_y;

double ai_qz;
int ai_xz;
int ai_lr;

void msxz();//选择模式（1：AI 0：PLAYER）
int ms = -1;