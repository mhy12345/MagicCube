//头文件，不需要知道含义
#include "MagicCube.hpp"
using namespace std;
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

int main()
{
		MagicCube mc;
		freopen("task2_tmp.txt","w",stdout);
		mc.read();
}
