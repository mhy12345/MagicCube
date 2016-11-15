//头文件，不需要知道含义
#include "MagicCube.h"
using namespace std;
//define A B 意思是将下文中A替换为B，方便理解
//定义步骤列表
#define STEP_NOTHING 0
#define STEP_BOTTOM_CROSS 1
#define STEP_LEVEL_ONE 2
#define STEP_LEVEL_TWO 3
#define STEP_TOP_CROSS 4
#define STEP_FINISH 5
//定义面编号
#define FACE_FRONT 0
#define FACE_RIGHT 1
#define FACE_BACK 2
#define FACE_LEFT 3
#define FACE_TOP 4
#define FACE_BOTTOM 5
const char *graph2=
"+-------+\n"
"| e e e |\n"
"| e e e |\n"
"| e e e |\n"
"+-------+-------+-------+-------+\n"
"| a a a | b b b | c c c | d d d |\n"
"| a a a | b b b | c c c | d d d |\n"
"| a a a | b b b | c c c | d d d |\n"
"+-------+-------+-------+-------+\n"
"| f f f |\n"
"| f f f |\n"
"| f f f |\n"
"+-------+\n";
const char* alphabet="012345678ghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int MagicCube::neighbors[6][4]={{1,4,3,5},{2,4,0,5},{3,5,1,4},{2,3,0,1},{0,3,2,1},{3,2,1,0}};
const char* MagicCube::fname[6]= {"front","right","back","left","top","bottom"};
const int MagicCube::trs[6][12][2]={
		{{1,0},{1,3},{1,6},{5,2},{5,1},{5,0},{3,8},{3,5},{3,2},{4,6},{4,7},{4,8}},
		{{4,8},{4,5},{4,2},{2,0},{2,3},{2,6},{5,8},{5,5},{5,2},{0,8},{0,5},{0,2}},
		{{4,2},{4,1},{4,0},{3,0},{3,3},{3,6},{5,6},{5,7},{5,8},{1,8},{1,5},{1,2}},
		{{4,0},{4,3},{4,6},{0,0},{0,3},{0,6},{5,0},{5,3},{5,6},{2,8},{2,5},{2,2}},
		{{3,2},{3,1},{3,0},{2,2},{2,1},{2,0},{1,2},{1,1},{1,0},{0,2},{0,1},{0,0}},
		{{0,6},{0,7},{0,8},{1,6},{1,7},{1,8},{2,6},{2,7},{2,8},{3,6},{3,7},{3,8}},
};
MagicCube::MagicCube()
{
		fliptimes=0;
}
void MagicCube::read(FILE *fin = stdin)
{
		for (int i=0;i<6;i++)
				for (int j=0;j<9;j++)
						fscanf(fin,"%d",&face[i][j]);
}
void MagicCube::read(const char *fname)
{
		FILE *fin = fopen(fname,"r");
		read(fin);
		fclose(fin);
}
void MagicCube::print(FILE *fout = stdout)
{
		for (int i=0;i<6;i++)
		{
				for (int j=0;j<3;j++)
				{
						for (int k=0;k<3;k++)
						{
								fprintf(fout,"%d ",face[i][j*3+k]);
						}
						fprintf(fout,"\n");
				}
				fprintf(fout,"\n");
		}
		fprintf(fout,"\n");
}
void MagicCube::print(const char* fname)
{
		FILE *fout = fopen(fname,"w");
		print(fout);
		fclose(fout);
}
void MagicCube::setFace(int x,int y,int t)
{
		face[x][y]=t;
}
void MagicCube::printPlane(FILE* fout = stdout)
{
		char res[500];
		strcpy(res,graph2);
		int l=(int)strlen(res);
		for (int i=0;i<6;i++)
				for (int j=0;j<9;j++)
						for (int kk=0;kk<l;kk++)
								if (res[kk]==i+'a')
								{
										res[kk]=alphabet[face[i][j]];
										break;
								}
		fprintf(fout,"%s\n",res);
}

int main()
{
		MagicCube mc;
		mc.read("task1_3.in");
		mc.print("task1_3.out");
}
