
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void openfin();
void openfout();
void inputface();
void outputface();
int face[6][3][3];
ifstream fin;
ofstream fout;

int main()
{
	openfin();
	openfout();
	inputface();
	outputface();
	return 0;
}
void openfin()
{
	char h[100];
	cout<<"输入读入文件名"<<endl;
	cin>>h;
	fin.open(h);
	if(fin)
	cout<<"ok"<<endl;
	else
	cout<<"not found!"<<endl;
}
void openfout()
{
	char h[100];
	cout<<"输入写入文件名"<<endl;
	cin>>h;
	fout.open(h);
}
void inputface()
{
	int i,j,k;
	for(i=0;i<6;i++)
	for(j=0;j<3;j++)
	for(k=0;k<3;k++)
	fin>>face[i][j][k];
}
void outputface()
{
	int i,j,k;
	fout<<"+-------+\n";
	for(i=0;i<3;i++)
	{
		fout<<"|";
		for(j=0;j<3;j++)
		{
			fout<<" "<<face[4][i][j];
		}
		fout<<" |\n";
	}
	fout<<"+-------+-------+-------+-------+\n";
	for(i=0;i<3;i++)
	{
		fout<<"|";
		for(j=0;j<4;j++)
		{
			for(k=0;k<3;k++)
			{
				fout<<" "<<face[j][i][k];
			}
			fout<<" |";
		}
		fout<<"\n";
	}
	fout<<"+-------+-------+-------+-------+\n";
	for(i=0;i<3;i++)
	{
		fout<<"|";
		for(j=0;j<3;j++)
		{
			fout<<" "<<face[5][i][j];
		}
		fout<<" |\n";
	}
	fout<<"+-------+";
}
