//头文件，不需要知道含义
#include "MagicCube.hpp"
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
void MagicCube::read()
{
		for (int i=0;i<6;i++)
				for (int j=0;j<9;j++)
						scanf("%d",&face[i][j]);
}
void MagicCube::print()
{
		for (int i=0;i<6;i++)
		{
				for (int j=0;j<3;j++)
				{
						for (int k=0;k<3;k++)
						{
								printf("%d ",face[i][j*3+k]);
						}
						printf("\n");
				}
				printf("\n");
		}
		printf("\n");
}
void MagicCube::set_face(int x,int y,int t)
{
		face[x][y]=t;
}
void MagicCube::print_face(int faceId=-1)//每调用一次将魔方通过某种方式输出到屏幕上
{
		for (int i=0;i<6;i++)
		{
				if (~faceId && i!=faceId)continue;
				for (int j=0;j<3;j++)
				{
						for (int k=0;k<3;k++)
						{
								printf("%d ",face[i][j*3+k]);
						}
						printf("\n");
				}
				printf("\n");
		}
}
void MagicCube::print_plane()
{
		char res[500];
		strcpy(res,graph2);
		int l=(int)strlen(res);
		for (int i=0;i<6;i++)
		{
				for (int j=0;j<9;j++)
				{
				//		if (face[i][j]!=face[i][4])throw 1;
						for (int kk=0;kk<l;kk++)
						{
								if (res[kk]==i+'a')
								{
										res[kk]=alphabet[face[i][j]];
										break;
								}
						}
				}
		}
		printf("%s\n",res);
}
void MagicCube::flip(int faceId,int dir)//将第faceId个面旋转，方向为dir，dir取1或-1
{
		if (fliptimes++>10000)
		{
				cerr<<"Error!\n"<<endl;
				exit(0);
		}
		//		cout<<">>>FLIP "<<fname[faceId]<<" "<<(dir==1?"clockwise":"anticlockwise")<<endl;
		MagicCube tmp=*this;
		for (int j=0;j<3;j++)
				for (int k=0;k<3;k++)
						if (dir==1)
								tmp.set_face(faceId,k*3+(2-j),face[faceId][j*3+k]);
						else
								tmp.set_face(faceId,(2-k)*3+j,face[faceId][j*3+k]);
		for (int i=0;i<12;i++)
		{
				tmp.set_face(trs[faceId][(i+3*dir+12)%12][0],trs[faceId][(i+3*dir+12)%12][1],
								face[trs[faceId][i][0]][trs[faceId][i][1]]);
		}
		*this=tmp;
}
int MagicCube::getStepId()//返回当前在哪个状态，
{
		if (face[FACE_BOTTOM][4] != face[FACE_BOTTOM][3] ||
						face[FACE_BOTTOM][4] != face[FACE_BOTTOM][5] ||
						face[FACE_BOTTOM][4] != face[FACE_BOTTOM][1] ||
						face[FACE_BOTTOM][4] != face[FACE_BOTTOM][7])
				return 0;
		if (face[FACE_BOTTOM][4] != face[FACE_BOTTOM][0] ||
						face[FACE_BOTTOM][4] != face[FACE_BOTTOM][2] ||
						face[FACE_BOTTOM][4] != face[FACE_BOTTOM][6] ||
						face[FACE_BOTTOM][4] != face[FACE_BOTTOM][8] ||
						face[FACE_FRONT][4] != face[FACE_FRONT][6] ||
						face[FACE_FRONT][4] != face[FACE_FRONT][7] ||
						face[FACE_FRONT][4] != face[FACE_FRONT][8] ||
						face[FACE_RIGHT][4] != face[FACE_RIGHT][6] ||
						face[FACE_RIGHT][4] != face[FACE_RIGHT][7] ||
						face[FACE_RIGHT][4] != face[FACE_RIGHT][8] ||
						face[FACE_BACK][4] != face[FACE_BACK][6] ||
						face[FACE_BACK][4] != face[FACE_BACK][7] ||
						face[FACE_BACK][4] != face[FACE_BACK][8] ||
						face[FACE_LEFT][4] != face[FACE_LEFT][6] ||
						face[FACE_LEFT][4] != face[FACE_LEFT][7] ||
						face[FACE_LEFT][4] != face[FACE_LEFT][8])
				return 1;
		if (face[FACE_FRONT][4] != face[FACE_FRONT][3] ||
						face[FACE_FRONT][4] != face[FACE_FRONT][5] ||
						face[FACE_RIGHT][4] != face[FACE_RIGHT][3] ||
						face[FACE_RIGHT][4] != face[FACE_RIGHT][5] ||
						face[FACE_BACK][4] != face[FACE_BACK][3] ||
						face[FACE_BACK][4] != face[FACE_BACK][5] ||
						face[FACE_LEFT][4] != face[FACE_LEFT][3] ||
						face[FACE_LEFT][4] != face[FACE_LEFT][5])
				return 2;
		if (face[FACE_TOP][4] != face[FACE_TOP][3] ||
						face[FACE_TOP][4] != face[FACE_TOP][5] ||
						face[FACE_TOP][4] != face[FACE_TOP][1] ||
						face[FACE_TOP][4] != face[FACE_TOP][7])
				return 3;
		if (face[FACE_TOP][4] != face[FACE_TOP][0] ||
						face[FACE_TOP][4] != face[FACE_TOP][2] ||
						face[FACE_TOP][4] != face[FACE_TOP][6] ||
						face[FACE_TOP][4] != face[FACE_TOP][8])
				return 4;
		if (face[FACE_FRONT][4] != face[FACE_FRONT][0] ||
						face[FACE_FRONT][4] != face[FACE_FRONT][2] ||
						face[FACE_RIGHT][4] != face[FACE_RIGHT][0] ||
						face[FACE_RIGHT][4] != face[FACE_RIGHT][2] ||
						face[FACE_BACK][4] != face[FACE_BACK][0] ||
						face[FACE_BACK][4] != face[FACE_BACK][2] ||
						face[FACE_LEFT][4] != face[FACE_LEFT][0] ||
						face[FACE_LEFT][4] != face[FACE_LEFT][2])
				return 5;
		if (face[FACE_FRONT][4] != face[FACE_FRONT][1] ||
						face[FACE_RIGHT][4] != face[FACE_RIGHT][1] ||
						face[FACE_BACK][4] != face[FACE_BACK][1] ||
						face[FACE_LEFT][4] != face[FACE_LEFT][1])
				return 6;
		return 7;
}
void MagicCube::rotate(int dir)
{
		//		cout<<">>>ROTATE "<<(dir==1?"clockwise":"anticlockwise")<<endl;
		MagicCube tmp=*this;
		for (int j=0;j<3;j++)
				for (int k=0;k<3;k++)
						if (dir==1)
						{
								tmp.set_face(FACE_TOP,k*3+(2-j),face[FACE_TOP][j*3+k]);
								tmp.set_face(FACE_BOTTOM,(2-k)*3+j,face[FACE_BOTTOM][j*3+k]);
						}
						else
						{
								tmp.set_face(FACE_TOP,(2-k)*3+j,face[FACE_TOP][j*3+k]);
								tmp.set_face(FACE_BOTTOM,k*3+(2-j),face[FACE_BOTTOM][j*3+k]);
						}
		for (int i=0;i<4;i++)
				for (int j=0;j<9;j++)
						tmp.set_face((i+4-dir)%4,j,face[i][j]);
		*this = tmp;
}
void MagicCube::operations(const char* str)
{
		while (*str)
		{
				switch(*(str++))
				{
						case 'F':
								flip(FACE_FRONT,1);break;
						case 'f':
								flip(FACE_FRONT,-1);break;
						case 'U':
								flip(FACE_TOP,1);break;
						case 'u':
								flip(FACE_TOP,-1);break;
						case 'R':
								flip(FACE_RIGHT,1);break;
						case 'r':
								flip(FACE_RIGHT,-1);break;
						case 'L':
								flip(FACE_LEFT,1);break;
						case 'l':
								flip(FACE_LEFT,-1);break;
						case 'B':
								flip(FACE_BACK,1);break;
						case 'b':
								flip(FACE_BACK,-1);break;
						case 'T':
								flip(FACE_BOTTOM,1);break;
						case 't':
								flip(FACE_BOTTOM,-1);break;
				}
		}
}
void MagicCube::doStep0()
{
		int times=40;
		while (times--)
		{
				if (face[FACE_BOTTOM][1] == face[FACE_BOTTOM][4] &&
								face[FACE_BOTTOM][3] == face[FACE_BOTTOM][4] &&
								face[FACE_BOTTOM][5] == face[FACE_BOTTOM][4] &&
								face[FACE_BOTTOM][7] == face[FACE_BOTTOM][4] &&
								face[FACE_FRONT][7] == face[FACE_FRONT][4] &&
								face[FACE_RIGHT][7] == face[FACE_RIGHT][4] &&
								face[FACE_BACK][7] == face[FACE_BACK][4] &&
								face[FACE_LEFT][7] == face[FACE_LEFT][4])
						break;
				for (int i=0;i<4;i++)
				{
						flip(FACE_TOP,1);
						if (face[FACE_FRONT][1] == face[FACE_BOTTOM][4] &&
										face[FACE_TOP][7] == face[FACE_FRONT][4])
								flip(FACE_FRONT,1),flip(FACE_BOTTOM,1),flip(FACE_RIGHT,-1),flip(FACE_BOTTOM,-1);
						if (face[FACE_TOP][7] == face[FACE_BOTTOM][4]
										&& face[FACE_FRONT][1] == face[FACE_FRONT][4])
								flip(FACE_FRONT,1),flip(FACE_FRONT,1);
						if (face[FACE_FRONT][7] == face[FACE_BOTTOM][4] &&
										face[FACE_FRONT][4] == face[FACE_BOTTOM][1])
								operations("FTft");
				}
				int fc=face[FACE_FRONT][4];
				for (int i=0;i<4;i++)
				{
						rotate(1);
						flip(FACE_BOTTOM,1);
						if (face[FACE_FRONT][5] == fc &&
										face[FACE_RIGHT][3] == face[FACE_BOTTOM][4])
								flip(FACE_FRONT,1);
						if (face[FACE_FRONT][3] == fc &&
										face[FACE_LEFT][5] == face[FACE_BOTTOM][4])
								flip(FACE_FRONT,-1);
				}
				if ((face[FACE_BOTTOM][1] == face[FACE_BOTTOM][4] &&
										face[FACE_FRONT][7] != face[FACE_FRONT][4]) ||
								face[FACE_FRONT][7] == face[FACE_BOTTOM][4])
						flip(FACE_FRONT,1);
				rotate(1);
		}
}
void MagicCube::doStep1()
{
		int times=30;
		while (times--)
		{
				if (face[FACE_BOTTOM][2] == face[FACE_BOTTOM][4] &&
								face[FACE_FRONT][8] == face[FACE_FRONT][4] &&
								face[FACE_RIGHT][6] == face[FACE_RIGHT][4])
				{
						rotate(1);
						continue;
				}
				bool flag0=false;
				for (int i=0;i<4;i++)
				{
						flip(FACE_TOP,1);
						int tot[9];memset(tot,0,sizeof(tot));
						tot[face[FACE_FRONT][2]]++;
						tot[face[FACE_RIGHT][0]]++;
						tot[face[FACE_TOP][8]]++;
						tot[face[FACE_FRONT][4]]++;
						tot[face[FACE_RIGHT][4]]++;
						tot[face[FACE_BOTTOM][4]]++;
						bool flag=tot[face[FACE_BOTTOM][4]]==2;
						for (int i=0;i<9;i++)
								if (tot[i]==1)flag=false;
						while (flag)
						{
								operations("fuFU");
								if (face[FACE_BOTTOM][2] == face[FACE_BOTTOM][4] &&
												face[FACE_FRONT][8] == face[FACE_FRONT][4] &&
												face[FACE_RIGHT][6] == face[FACE_RIGHT][4])
								{
										flag0=true;
										break;
								}
						}
				}
				if (flag0)continue;
				if (face[FACE_BOTTOM][2] == face[FACE_BOTTOM][4] ||
								face[FACE_FRONT][8] == face[FACE_BOTTOM][4] ||
								face[FACE_RIGHT][6] == face[FACE_BOTTOM][4])
						operations("fuFU");
				rotate(1);
		}
}
void MagicCube::doStep2()
{
		int times=50;
		while (times--)
		{
				for (int i=0;i<4;i++)
				{
						flip(FACE_TOP,1);
						if (face[FACE_FRONT][1] == face[FACE_FRONT][4] && 
										face[FACE_TOP][7] == face[FACE_RIGHT][4])
								operations("URurufUF");
						if (face[FACE_FRONT][1] == face[FACE_FRONT][4] && 
										face[FACE_TOP][7] == face[FACE_LEFT][4])
								operations("ulULUFuf");
				}
				if (face[FACE_FRONT][5]<4 && face[FACE_RIGHT][3]<4 &&
								(face[FACE_FRONT][5]!=face[FACE_FRONT][4] || face[FACE_RIGHT][3]!=face[FACE_RIGHT][4]))
						operations("URurufUF");
				rotate(1);
		}
}
void MagicCube::doStep3()
{
		int times=30;
		while (times--)
		{
				if (face[FACE_TOP][1] == face[FACE_TOP][4] &&
								face[FACE_TOP][3] == face[FACE_TOP][4] &&
								face[FACE_TOP][5] == face[FACE_TOP][4] &&
								face[FACE_TOP][7] == face[FACE_TOP][4])
						break;
				if (face[FACE_TOP][3] == face[FACE_TOP][4] &&
								face[FACE_TOP][5] == face[FACE_TOP][4])
				{
						operations("FRUruf");
						continue;
				}
				if (face[FACE_TOP][1] == face[FACE_TOP][4] &&
								face[FACE_TOP][3] == face[FACE_TOP][4])
				{
						operations("FURurf");
						continue;
				}
				operations("FRUruf");
				rotate(1);
		}
}
void MagicCube::doStep4()
{
		int times=15;
		while (times--)
		{
				int cnt=(face[FACE_TOP][0] == face[FACE_TOP][4]) +
						(face[FACE_TOP][2] == face[FACE_TOP][4]) +
						(face[FACE_TOP][6] == face[FACE_TOP][4]) +
						(face[FACE_TOP][8] == face[FACE_TOP][4]);
				if (cnt==0)
				{
						while (true)
						{
								flip(FACE_TOP,1);
								if (face[FACE_LEFT][2] == face[FACE_TOP][4])
										break;
						}
				}else if (cnt==1)
				{
						while (true)
						{
								flip(FACE_TOP,1);
								if (face[FACE_TOP][6] == face[FACE_TOP][4])
										break;
						}
				}else if (cnt==2)
				{
						while (true)
						{
								flip(FACE_TOP,1);
								if (face[FACE_FRONT][0] == face[FACE_TOP][4] ||
												face[FACE_FRONT][2] == face[FACE_TOP][4])
										break;
						}
				}else if (cnt==4)
						break;
				operations("RUrURUUr");
		}
}
void MagicCube::doStep5()
{
		int times=15;
		while (times--)
		{
				rotate(1);
				bool flag=true;
				for (int i=0;i<4;i++)
						if (face[i][0]!=face[i][4] || face[i][2]!=face[i][4])
								flag=false;
				if (flag)break;
				for (int i=0;i<4;i++)
				{
						flip(FACE_TOP,1);
						bool flag=false;
						if (face[FACE_BACK][0] == face[FACE_BACK][4] &&
										face[FACE_BACK][2] == face[FACE_BACK][4] &&
										face[FACE_LEFT][0] == face[FACE_LEFT][4] &&
										face[FACE_RIGHT][2] == face[FACE_RIGHT][4])
								flag=true;
						if (face[FACE_BACK][0] == face[FACE_BACK][4] &&
										face[FACE_RIGHT][2] == face[FACE_RIGHT][4] &&
										face[FACE_LEFT][2] == face[FACE_LEFT][4] &&
										face[FACE_FRONT][0] == face[FACE_FRONT][4])
								flag=true;
						if (face[FACE_BACK][2] == face[FACE_BACK][4] &&
										face[FACE_LEFT][0] == face[FACE_LEFT][4] &&
										face[FACE_RIGHT][0] == face[FACE_RIGHT][4] &&
										face[FACE_FRONT][2] == face[FACE_FRONT][4])
								flag=true;
						if (!flag)continue;
						operations("rFrBBRfrBBRRu");
						break;
				}
		}
}
void MagicCube::doStep6()
{
		int times=15;
		while (times--)
		{
				bool flag=false;
				for (int i=0;i<4;i++)
						if (face[i][1]!=face[i][0])
								flag=true;
				if (!flag)break;
				int cnt=4;
				while (cnt-- && face[FACE_BACK][1]!=face[FACE_BACK][4])
						rotate(1);
				operations("FFULrFFlRUFF");
		}
}
void MagicCube::doDisturb(int times=10)//对于初始魔方随机打乱，默认打乱十次
{
		srand(time(0));
		while (times--)
		{
				int x,y;
				x=rand()%6;
				y=rand()%2?-1:1;
				flip(x,y);
		}
}
void MagicCube::doDisturb2()
{
		srand(1);
		doDisturb(30);
		int x1=rand()%6;
		int y1=rand()%9;
		int x2=rand()%6;
		int y2=rand()%9;
		swap(face[x1][y1],face[x2][y2]);
}
void MagicCube::initial()
{
		for (int i=0;i<6;i++)
				for (int j=0;j<9;j++)
						face[i][j]=i;
}
void MagicCube::initial_unique()
{
		for (int i=0;i<6;i++)
				for (int j=0;j<9;j++)
						face[i][j]=j+i*9;;
}
void MagicCube::solve()
{
		doStep0();
		doStep1();
		doStep2();
		doStep3();
		doStep4();
		doStep5();
		doStep6();
}

int main()
{
		while(true)
		{
				/*		FILE *fin = fopen("seed.txt","r");
						fscanf(fin,"%d",&seed);
						fclose(fin);
						FILE *fout = fopen("seed.txt","w");
						fprintf(fout,"%d\n",seed+1);
						fclose(fout);
						cout<<"SEED:"<<seed<<endl;*/
				//seed=3519;
				MagicCube mc;
				mc.initial();
				mc.doDisturb();
				mc.solve();
				mc.print_plane();
				//		usleep(200000);
		}
		return 0;
}
