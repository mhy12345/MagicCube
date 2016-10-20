#ifndef __MAGICCUBE_H__
#define __MAGICCUBE_H__
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<string>
#include<unistd.h>
class MagicCube
{
		private:
				static const int maxn = 3;//魔方每一面是maxn*maxn，默认3*3
				static const int neighbors[6][4];//每一个面的相邻面
				static const char* fname[6];//每一个面的名称，用于输出
				static const int trs[6][12][2];//每一个面那一层的12个颜色坐标
				int face[6][maxn*maxn];//储存颜色
				int fliptimes;//程序执行次数，如果超出限制，说明无解
		public:
				MagicCube();
				void read(FILE* fin);//读入魔方
				void read(const char* fname);//按文件名读入魔方
				void print(FILE* fout);//输出魔方
				void print(const char *fname);//按文件名输出魔方
				void setFace(int x,int y,int t);//修改face数组
				void printFace(int faceId);//每调用一次将魔方通过某种方式输出到屏幕上
				void printPlane(FILE *fout);//输出展开图
				void flip(int faceId,int dir);//将第faceId个面旋转，方向为dir，dir取1或-1
				void rotate(int dir);//整体旋转
				void operations(const char* str);//输入公式，执行翻转操作
				int getStepId();//返回当前在哪个状态
				void doStep0();//底面十字架
				void doStep1();//一面一层
				void doStep2();//一面两层
				void doStep3();//顶面十字架
				void doStep4();//顶面
				void doStep5();//第三层角
				void doStep6();//第三层棱
				void doDisturb(int times);//对于初始魔方随机打乱，默认打乱十次
				void doDisturb2();//不保证有解
				void initial();//初始化
				void initialUnique();//用9*6种不同颜色初始化，用于检测旋转是否正确
				void solve();//恢复魔方
};

#endif
