#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void openfin();
void inputface();
void outputface();
void maker();
void makel();
void makeu();
void maked();
void makef();
void makeb();
void maker1();
void makel1();
void makeu1();
void maked1();
void makef1();
void makeb1();
void solve0ten();
void solve1();
void solve2();
void solve4ten();
void solve4whole();
void solve3cor();
void solve3whole();
int check0ten1();
int check0ten2();
int check1();
int check2();
int check4ten();
int check4ten1();
//check4ten1判断底面是否存在中间三个成一排 若不存在返回0 横返回2 竖返回3 
int check4ten2();
//check4ten2判断底面是否出现半十字 若不存在返回0 位置正确返回2 位置不正确返回3 
int check4whole();
int check4whole1();
//check4whole1判断底面颜色正确角块的数量 返回0/1/2/3/4 
int check3();
int checkcolor1(int,int,int,int,int,int);
int checkcolor2(int,int,int,int,int,int);
int checkcolor3(int,int);
int checkcolor4(int,int,int,int);
int checkcolor5(int,int,int,int);
char colo1(int);
int recolo(char);
#define up 0
#define right 1
#define back 4
#define left 3
#define front 5
#define bottom 2
int up1,right1,left1,bottom1,back1,front1;
int face[6][3][3];
int face1[6][3][3];
//共有12种操作 分别为R,L,U,D,F,B,R1,L1,D1,U1,F1,B1
//R为右上,R1为右下 
//L1为左上,L为左下 
//U为上左,U1为上右 
//D1为下左,D为下右 
//F1为前左,F为前右 
//B为后左,B1为后右 
int main()
{
//		freopen("input.txt","r",stdin);
	inputface();	
	solve0ten();
	solve1();
	solve2();
	solve4ten();
	solve4whole();
	solve3cor();
	solve3whole();
//	cout<<endl;
//	outputface();
	return 0;
}

void inputface()
{
	int i,j,k;
	char acolo;
	for(i=0;i<6;i++)
	for(j=0;j<3;j++)
	for(k=0;k<3;k++)
	{
		cin>>acolo;
		face1[i][j][k]=recolo(acolo);
	}
	for(j=0;j<3;j++)
	for(k=0;k<3;k++)
	{
		face[front][j][k]=face1[0][j][k];
		face[up][j][k]=face1[4][j][k];
		face[back][j][k]=face1[1][2-j][2-k];
		face[right][j][k]=face1[2][k][2-j];
		face[bottom][j][k]=face1[5][2-j][2-k];
		face[left][j][k]=face1[3][2-k][j];
	}
	up1=face[up][1][1];
	front1=face[front][1][1];
	back1=face[back][1][1];
	right1=face[right][1][1];
	left1=face[left][1][1];
	bottom1=face[bottom][1][1];
}
void outputface()
{
	int i,j,k;
	for(j=0;j<3;j++)
	for(k=0;k<3;k++)
	{
		face1[0][j][k]=face[front][j][k];
		face1[4][j][k]=face[up][j][k];
		face1[1][2-j][2-k]=face[back][j][k];
		face1[2][k][2-j]=face[right][j][k];
		face1[5][j][k]=face[bottom][2-j][2-k];
		face1[3][2-k][j]=face[left][j][k];
	}
	for(i=0;i<6;i++)
	{
		for(j=0;j<3;j++)
	    {
	    	for(k=0;k<3;k++)
	       	cout<<colo1(face1[i][j][k]);
	    }
	    cout<<endl;
	}
}
void maker()
{
	cout<<"R"<<" ";
	int changex=0;
	int changey[3];
	int i;
	changex=face[right][0][1];
	face[right][0][1]=face[right][1][0];
	face[right][1][0]=face[right][2][1];
	face[right][2][1]=face[right][1][2];
	face[right][1][2]=changex;
	changex=face[right][0][0];
	face[right][0][0]=face[right][2][0];
	face[right][2][0]=face[right][2][2];
	face[right][2][2]=face[right][0][2];
	face[right][0][2]=changex;
	for(i=0;i<3;i++)
	changey[i]=face[up][i][2];
	for(i=0;i<3;i++)
	face[up][i][2]=face[front][i][2];
	for(i=0;i<3;i++)
	face[front][i][2]=face[bottom][2-i][0];
	for(i=0;i<3;i++)
	face[bottom][2-i][0]=face[back][i][2];
	for(i=0;i<3;i++)
	face[back][i][2]=changey[i];
}
void maker1()
{
	cout<<"Ri"<<" ";
	int changex=0;
	int changey[3];
	int i;
	changex=face[right][0][1];
	face[right][0][1]=face[right][1][2];
	face[right][1][2]=face[right][2][1];
	face[right][2][1]=face[right][1][0];
	face[right][1][0]=changex;
	changex=face[right][0][0];
	face[right][0][0]=face[right][0][2];
	face[right][0][2]=face[right][2][2];
	face[right][2][2]=face[right][2][0];
	face[right][2][0]=changex;
	for(i=0;i<3;i++)
	changey[i]=face[up][i][2];
	for(i=0;i<3;i++)
	face[up][i][2]=face[back][i][2];
	for(i=0;i<3;i++)
	face[back][i][2]=face[bottom][2-i][0];
	for(i=0;i<3;i++)
	face[bottom][2-i][0]=face[front][i][2];
	for(i=0;i<3;i++)
	face[front][i][2]=changey[i];
}
void makel1()
{
	cout<<"Li"<<" ";
	int changex=0;
	int changey[3];
	int i;
	changex=face[left][0][1];
	face[left][0][1]=face[left][1][2];
	face[left][1][2]=face[left][2][1];
	face[left][2][1]=face[left][1][0];
	face[left][1][0]=changex;
	changex=face[left][0][0];
	face[left][0][0]=face[left][0][2];
	face[left][0][2]=face[left][2][2];
	face[left][2][2]=face[left][2][0];
	face[left][2][0]=changex;
	for(i=0;i<3;i++)
	changey[i]=face[up][i][0];
	for(i=0;i<3;i++)
	face[up][i][0]=face[front][i][0];
	for(i=0;i<3;i++)
	face[front][i][0]=face[bottom][2-i][2];
	for(i=0;i<3;i++)
	face[bottom][2-i][2]=face[back][i][0];
	for(i=0;i<3;i++)
	face[back][i][0]=changey[i];
}
void makel()
{
	cout<<"L"<<" ";
	int changex=0;
	int changey[3];
	int i;
	changex=face[left][0][1];
	face[left][0][1]=face[left][1][0];
	face[left][1][0]=face[left][2][1];
	face[left][2][1]=face[left][1][2];
	face[left][1][2]=changex;
	changex=face[left][0][0];
	face[left][0][0]=face[left][2][0];
	face[left][2][0]=face[left][2][2];
	face[left][2][2]=face[left][0][2];
	face[left][0][2]=changex;
	for(i=0;i<3;i++)
	changey[i]=face[up][i][0];
	for(i=0;i<3;i++)
	face[up][i][0]=face[back][i][0];
	for(i=0;i<3;i++)
	face[back][i][0]=face[bottom][2-i][2];
	for(i=0;i<3;i++)
	face[bottom][2-i][2]=face[front][i][0];
	for(i=0;i<3;i++)
	face[front][i][0]=changey[i];
}
void makeu()
{
	cout<<"U"<<" ";
	int changex=0;
	int changey[3];
	int i;
	changex=face[up][0][1];
	face[up][0][1]=face[up][1][0];
	face[up][1][0]=face[up][2][1];
	face[up][2][1]=face[up][1][2];
	face[up][1][2]=changex;
	changex=face[up][0][0];
	face[up][0][0]=face[up][2][0];
	face[up][2][0]=face[up][2][2];
	face[up][2][2]=face[up][0][2];
	face[up][0][2]=changex;
	for(i=0;i<3;i++)
	changey[i]=face[right][i][0];
	for(i=0;i<3;i++)
	face[right][i][0]=face[back][2][i];
	for(i=0;i<3;i++)
	face[back][2][i]=face[left][2-i][2];
	for(i=0;i<3;i++)
	face[left][2-i][2]=face[front][0][2-i];
	for(i=0;i<3;i++)
	face[front][0][2-i]=changey[i];
}
void makeu1()
{
	cout<<"Ui"<<" ";
	int changex=0;
	int changey[3];
	int i;
	changex=face[up][0][1];
	face[up][0][1]=face[up][1][2];
	face[up][1][2]=face[up][2][1];
	face[up][2][1]=face[up][1][0];
	face[up][1][0]=changex;
	changex=face[up][0][0];
	face[up][0][0]=face[up][0][2];
	face[up][0][2]=face[up][2][2];
	face[up][2][2]=face[up][2][0];
	face[up][2][0]=changex;
	for(i=0;i<3;i++)
	changey[i]=face[right][i][0];
	for(i=0;i<3;i++)
	face[right][i][0]=face[front][0][2-i];
	for(i=0;i<3;i++)
	face[front][0][2-i]=face[left][2-i][2];
	for(i=0;i<3;i++)
	face[left][2-i][2]=face[back][2][i];
	for(i=0;i<3;i++)
	face[back][2][i]=changey[i];
}
void maked1()
{
	cout<<"Di"<<" ";
	int changex=0;
	int changey[3];
	int i;
	changex=face[bottom][0][1];
	face[bottom][0][1]=face[bottom][1][2];
	face[bottom][1][2]=face[bottom][2][1];
	face[bottom][2][1]=face[bottom][1][0];
	face[bottom][1][0]=changex;
	changex=face[bottom][0][0];
	face[bottom][0][0]=face[bottom][0][2];
	face[bottom][0][2]=face[bottom][2][2];
	face[bottom][2][2]=face[bottom][2][0];
	face[bottom][2][0]=changex;
	for(i=0;i<3;i++)
	changey[i]=face[right][i][2];
	for(i=0;i<3;i++)
	face[right][i][2]=face[back][0][i];
	for(i=0;i<3;i++)
	face[back][0][i]=face[left][2-i][0];
	for(i=0;i<3;i++)
	face[left][2-i][0]=face[front][2][2-i];
	for(i=0;i<3;i++)
	face[front][2][2-i]=changey[i];
}
void maked()
{
	cout<<"D"<<" ";
	int changex=0;
	int changey[3];
	int i;
	changex=face[bottom][0][1];
	face[bottom][0][1]=face[bottom][1][0];
	face[bottom][1][0]=face[bottom][2][1];
	face[bottom][2][1]=face[bottom][1][2];
	face[bottom][1][2]=changex;
	changex=face[bottom][0][0];
	face[bottom][0][0]=face[bottom][2][0];
	face[bottom][2][0]=face[bottom][2][2];
	face[bottom][2][2]=face[bottom][0][2];
	face[bottom][0][2]=changex;
	for(i=0;i<3;i++)
	changey[i]=face[right][i][2];
	for(i=0;i<3;i++)
	face[right][i][2]=face[front][2][2-i];
	for(i=0;i<3;i++)
	face[front][2][2-i]=face[left][2-i][0];
	for(i=0;i<3;i++)
	face[left][2-i][0]=face[back][0][i];
	for(i=0;i<3;i++)
	face[back][0][i]=changey[i];
}
void makef1()
{
	cout<<"Fi"<<" ";
	int changex=0;
	int changey[3];
	int i;
	changex=face[front][0][1];
	face[front][0][1]=face[front][1][2];
	face[front][1][2]=face[front][2][1];
	face[front][2][1]=face[front][1][0];
	face[front][1][0]=changex;
	changex=face[front][0][0];
	face[front][0][0]=face[front][0][2];
	face[front][0][2]=face[front][2][2];
	face[front][2][2]=face[front][2][0];
	face[front][2][0]=changex;
	for(i=0;i<3;i++)
	changey[i]=face[right][2][i];
	for(i=0;i<3;i++)
	face[right][2][i]=face[bottom][2][i];
	for(i=0;i<3;i++)
	face[bottom][2][i]=face[left][2][i];
	for(i=0;i<3;i++)
	face[left][2][i]=face[up][2][i];
	for(i=0;i<3;i++)
	face[up][2][i]=changey[i];
}
void makef()
{
	cout<<"F"<<" ";
	int changex=0;
	int changey[3];
	int i;
	changex=face[front][0][1];
	face[front][0][1]=face[front][1][0];
	face[front][1][0]=face[front][2][1];
	face[front][2][1]=face[front][1][2];
	face[front][1][2]=changex;
	changex=face[front][0][0];
	face[front][0][0]=face[front][2][0];
	face[front][2][0]=face[front][2][2];
	face[front][2][2]=face[front][0][2];
	face[front][0][2]=changex;
	for(i=0;i<3;i++)
	changey[i]=face[right][2][i];
	for(i=0;i<3;i++)
	face[right][2][i]=face[up][2][i];
	for(i=0;i<3;i++)
	face[up][2][i]=face[left][2][i];
	for(i=0;i<3;i++)
	face[left][2][i]=face[bottom][2][i];
	for(i=0;i<3;i++)
	face[bottom][2][i]=changey[i];
}
void makeb()
{
	cout<<"B"<<" ";
	int changex=0;
	int changey[3];
	int i;
	changex=face[back][0][1];
	face[back][0][1]=face[back][1][0];
	face[back][1][0]=face[back][2][1];
	face[back][2][1]=face[back][1][2];
	face[back][1][2]=changex;
	changex=face[back][0][0];
	face[back][0][0]=face[back][2][0];
	face[back][2][0]=face[back][2][2];
	face[back][2][2]=face[back][0][2];
	face[back][0][2]=changex;
	for(i=0;i<3;i++)
	changey[i]=face[right][0][i];
	for(i=0;i<3;i++)
	face[right][0][i]=face[bottom][0][i];
	for(i=0;i<3;i++)
	face[bottom][0][i]=face[left][0][i];
	for(i=0;i<3;i++)
	face[left][0][i]=face[up][0][i];
	for(i=0;i<3;i++)
	face[up][0][i]=changey[i];
}
void makeb1()
{
	cout<<"Bi"<<" ";
	int changex=0;
	int changey[3];
	int i;
	changex=face[back][0][1];
	face[back][0][1]=face[back][1][2];
	face[back][1][2]=face[back][2][1];
	face[back][2][1]=face[back][1][0];
	face[back][1][0]=changex;
	changex=face[back][0][0];
	face[back][0][0]=face[back][0][2];
	face[back][0][2]=face[back][2][2];
	face[back][2][2]=face[back][2][0];
	face[back][2][0]=changex;
	for(i=0;i<3;i++)
	changey[i]=face[right][0][i];
	for(i=0;i<3;i++)
	face[right][0][i]=face[up][0][i];
	for(i=0;i<3;i++)
	face[up][0][i]=face[left][0][i];
	for(i=0;i<3;i++)
	face[left][0][i]=face[bottom][0][i];
	for(i=0;i<3;i++)
	face[bottom][0][i]=changey[i];
}
char colo1(int p)
{
	char str[]="RGBOWY";
	return str[p];
}
int recolo(char acolo)
{
	char str[]="RGBOWY";
	int i=0;
	for(i=0;i<6;i++)
	if(str[i]==acolo)
	break;
	return i;
}
int check0ten1()
{
	int i,j,col=1;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	if(i==1 || j==1)
	if(face[up][i][j]!=face[up][1][1])
	col=0;
	return col;
}
int check0ten2()
{
	int col=1;
	if(face[right][1][0]!=face[right][1][1] || face[left][1][2]!=face[left][1][1] || face[front][0][1]!=face[front][1][1] || face[back][2][1]!=face[back][1][1])
	col=0;
	return col;
}
int check1()
{
	int i,j,col=1;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	if(face[up][i][j]!=face[up][1][1])
	col=0;
	for(i=0;i<3;i++)
	if(face[right][i][0]!=face[right][1][1] || face[left][i][2]!=face[left][1][1] || face[front][0][i]!=face[front][1][1] || face[back][2][i]!=face[back][1][1])
	col=0;
	return col;
}
int check2()
{
	int i,col=1;
	for(i=0;i<3;i++)
	if(face[right][i][1]!=face[right][1][1] || face[left][i][1]!=face[left][1][1] || face[front][1][i]!=face[front][1][1] || face[back][1][i]!=face[back][1][1])
	col=0;
	return col;
}
int check4ten()
{
	int i,j,col=1;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	if(i==1 || j==1)
	if(face[bottom][i][j]!=face[bottom][1][1])
	col=0;
	return col;
}
int check4whole()
{
	int i,j,col=1;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	if(face[bottom][i][j]!=face[bottom][1][1])
	col=0;
	return col;
}
int check3()
{
	int i,col=1;
	for(i=0;i<3;i++)
	if(face[right][i][2]!=face[right][1][1] || face[left][i][0]!=face[left][1][1] || face[front][2][i]!=face[front][1][1] || face[back][0][i]!=face[back][1][1])
	col=0;
	return col;
}
void solve0ten()
{
	while(check0ten1()!=1)
	{
	if(face[front][0][1]==up1)
	{
		makef();
		while(face[up][1][2]==up1)
		{
			makeu1();
		}
		maker();
	}
	if(face[right][1][0]==up1)
	{
		maker();
		while(face[up][0][1]==up1)
		{
			makeu1();
		}
		makeb();
	}
	if(face[left][1][2]==up1)
	{
		makel();
		while(face[up][2][1]==up1)
		{
			makeu1();
		}
		makef();
	}
	if(face[back][2][1]==up1)
	{
		makeb1();
		while(face[up][1][2]==up1)
		{
			makeu1();
		}
		maker1();
	}
	if(face[front][1][0]==up1)
	{
		while(face[up][1][0]==up1)
		{
			makeu1();
		}
		makel1();
	}
	if(face[front][1][2]==up1)
	{
		while(face[up][1][2])
		{
			makeu1();
		}
		maker();
	}
	if(face[right][0][1]==up1)
	{
		while(face[up][0][1]==up1)
		{
			makeu1();
		}
		makeb();
	}
	if(face[right][2][1]==up1)
	{
		while(face[up][2][1]==up1)
		{
			makeu1();
		}
		makef1();
	}
	if(face[left][0][1]==up1)
	{
		while(face[up][0][1]==up1)
		{
			makeu1();
		}
		makeb1();
	}
	if(face[left][2][1]==up1)
	{
		while(face[up][2][1]==up1)
		{
			makeu1();
		}
		makef();
	}
	if(face[back][1][0]==up1)
	{
		while(face[up][1][0]==up1)
		{
			makeu1();
		}
		makel();
	}
	if(face[back][1][2]==up1)
	{
		while(face[up][1][2]==up1)
		{
			makeu1();
		}
		maker1();
	}
	if(face[front][2][1]==up1)
	{
		while(face[up][2][1]==up1)
		{
			makeu1();
		}
		makef1();
		while(face[up][1][2]==up1)
		{
			makeu1();
		}
		maker();
	}
	if(face[right][1][2]==up1)
	{
		while(face[up][1][2]==up1)
		{
			makeu1();
		}
		maker();
		while(face[up][2][1]==up1)
		{
			makeu1();
		}
		makef1();
	}
	if(face[left][1][0]==up1)
	{
		while(face[up][1][0]==up1)
		{
			makeu1();
		}
		makel1();
		while(face[up][2][1]==up1)
		{
			makeu1();
		}
		makef();
	}
	if(face[back][0][1]==up1)
	{
		while(face[up][0][1]==up1)
		{
			makeu1();
		}
		makeb();
		while(face[up][1][2]==up1)
		{
			makeu1();
		}
		maker1();
	}
	if(face[bottom][2][1]==up1)
	{
		while(face[up][2][1]==up1)
		{
			makeu1();
		}
		makef1();
		makef1();
	}
	if(face[bottom][1][0]==up1)
	{
		while(face[up][1][2]==up1)
		{
			makeu1();
		}
		maker();
		maker();
	}
	if(face[bottom][1][2]==up1)
	{
		while(face[up][1][0]==up1)
		{
			makeu1();
		}
		makel1();
		makel1();
	}
	if(face[bottom][0][1]==up1)
	{
		while(face[up][0][1]==up1)
		{
			makeu1();
		}
		makeb();
		makeb();
	}
	}
	if(face[front][0][1]!=front1)
	{
		if(face[right][1][0]==front1)
		{
			maker();
			maker();
			maked1();
			makef();
			makef();
			maked();
			maker();
			maker();
		}
		if(face[left][1][2]==front1)
		{
			makel();
			makel();
			maked();
			makef();
			makef();
			maked1();
			makel();
			makel();
		}
		if(face[back][2][1]==front1)
		{
			makeb();
			makeb();
			maked();
			maked();
			makef();
			makef();
			maked();
			maked();
			makeb();
			makeb();
		}
	}
	if(face[right][1][0]!=right1)
	{
		if(face[left][1][2]==right1)
		{
			makel();
			makel();
			maked();
			maked();
			maker();
			maker();
			maked();
			maked();
			makel();
			makel();
		}
		if(face[back][2][1]==right1)
		{
			makeb();
			makeb();
			maked1();
			maker();
			maker();
			maked();
			makeb();
			makeb();
		}
	}
	if(face[left][1][2]!=left1)
	{
		makel();
		makel();
		maked1();
		makeb();
		makeb();
		maked();
		makel();
		makel();
	}
}
void solve1()
{
	if(checkcolor1(face[front][0][0],face[up][2][0],face[left][2][2],front1,up1,left1)==1)
	{
		makef1();
		maked1();
		makef();
		maked();
	}
	if(checkcolor1(face[front][0][2],face[up][2][2],face[right][2][0],front1,up1,left1)==1)
	{
		maker1();
		maked1();
		maker();
		maked();
	}
	if(checkcolor1(face[back][2][2],face[up][0][2],face[right][0][0],front1,up1,left1)==1)
	{
		makeb1();
		maked1();
		makeb();
		maked();
	}
	if(checkcolor1(face[back][2][0],face[up][0][0],face[left][0][2],front1,up1,left1)==1)
	{
		makeb();
		maked();
		makeb1();
	}
	while(checkcolor1(face[front][2][0],face[bottom][2][2],face[left][2][0],front1,up1,left1)!=1)
	{
		maked();
	}
	while(checkcolor2(face[front][0][0],face[up][2][0],face[left][2][2],front1,up1,left1)!=1)
	{
			makef1();
			maked1();
			makef();
			maked();
	}
	if(checkcolor1(face[front][0][2],face[up][2][2],face[right][2][0],front1,up1,right1)==1)
	{
		maker1();
		maked();
		maker();
	}
	if(checkcolor1(face[back][2][2],face[up][0][2],face[right][0][0],front1,up1,right1)==1)
	{
		makeb1();
		maked();
		makeb();
	}
	if(checkcolor1(face[back][2][0],face[up][0][0],face[left][0][2],front1,up1,right1)==1)
	{
		makeb();
		maked();
		makeb1();
	}
	while(checkcolor1(face[front][2][2],face[bottom][2][0],face[right][2][2],front1,up1,right1)!=1)
	{
		maked();
	}
	while(checkcolor2(face[front][0][2],face[up][2][2],face[right][2][0],front1,up1,right1)!=1)
	{
		maker1();
		maked1();
		maker();
		maked();
	}
	if(checkcolor1(face[back][2][2],face[up][0][2],face[right][0][0],back1,up1,right1)==1)
	{
		makeb1();
		maked();
		makeb();
	}
	if(checkcolor1(face[back][2][0],face[up][0][0],face[left][0][2],back1,up1,right1)==1)
	{
		makeb();
		maked();
		makeb1();
	}
	while(checkcolor1(face[back][0][2],face[bottom][0][0],face[right][0][2],back1,up1,right1)!=1)
	{
		maked();
	}
	while(checkcolor2(face[back][2][2],face[up][0][2],face[right][0][0],back1,up1,right1)!=1)
	{
		makeb1();
		maked1();
		makeb();
		maked();
	}
	if(checkcolor1(face[back][2][0],face[up][0][0],face[left][0][2],back1,up1,left1)==1)
	{
		while(checkcolor2(face[back][2][0],face[up][0][0],face[left][0][2],back1,up1,left1)!=1)
		{
			makel1();
			maked1();
			makel();
			maked();
		}
	}
	else
	{
		while(checkcolor1(face[back][0][0],face[bottom][0][2],face[left][0][0],back1,up1,left1)!=1)
		{
			maked();
		}
		while(checkcolor2(face[back][2][0],face[up][0][0],face[left][0][2],back1,up1,left1)!=1)
		{
			makel1();
			maked1();
			makel();
			maked();
		}
	}
}
void solve2()
{
	if(checkcolor3(face[front][1][2],face[right][2][1])==0)
	{
		while(checkcolor3(face[front][2][1],face[bottom][2][1])!=1)
		{
			maked();
		}
		maked1();
		maker1();
		maked();
		maker();
		maked();
		makef();
		maked1();
		makef1();
	}
	if(checkcolor3(face[front][1][0],face[left][2][1])==0)
	{
		while(checkcolor3(face[front][2][1],face[bottom][2][1])!=1)
		{
			maked();
		}
		maked();
		makel();
		maked1();
		makel1();
		maked1();
		makef1();
		maked();
		makef();
	}
	if(checkcolor3(face[right][0][1],face[back][1][2])==0)
	{
		while(checkcolor3(face[right][1][2],face[bottom][1][0])!=1)
		{
			maked();
		}
		maked1();
		makeb1();
		maked();
		makeb();
		maked();
		maker();
		maked1();
		maker1();
	}
	if(checkcolor3(face[left][0][1],face[back][1][0])==0)
	{
		while(checkcolor3(face[left][1][0],face[bottom][1][2])!=1)
		{
			maked();
		}
		maked();
		makeb();
		maked1();
		makeb1();
		maked1();
		makel1();
		maked();
		makel();
	}
	while(checkcolor4(front1,right1,face[front][1][2],face[right][2][1])==0)
	{
	maked();
	if(checkcolor4(front1,right1,face[front][2][1],face[bottom][2][1])==1)
	{
		maked1();
		maker1();
		maked();
		maker();
		maked();
		makef();
		maked1();
		makef1();
	}
	if(checkcolor4(front1,right1,face[bottom][1][0],face[right][1][2])==1)
	{
		maked();
		makef();
		maked1();
		makef1();
		maked1();
		maker1();
		maked();
		maker();
	}
	}
	while(checkcolor4(right1,back1,face[right][0][1],face[back][1][2])==0)
	{
	maked();
	if(checkcolor4(right1,back1,face[right][1][2],face[bottom][1][0])==1)
	{
		maked1();
		makeb1();
		maked();
		makeb();
		maked();
		maker();
		maked1();
		maker1();
	}
	if(checkcolor4(right1,back1,face[bottom][0][1],face[back][0][1])==1)
	{
		maked();
		maker();
		maked1();
		maker1();
		maked1();
		makeb1();
		maked();
		makeb();
	}
	}
	while(checkcolor4(left1,back1,face[left][0][1],face[back][1][0])==0)
	{
	maked();
	if(checkcolor4(left1,back1,face[left][1][0],face[bottom][1][2])==1)
	{
		maked();
		makeb();
		maked1();
		makeb1();
		maked1();
		makel1();
		maked();
		makel();
	}
	if(checkcolor4(left1,back1,face[bottom][0][1],face[back][0][1])==1)
	{
		maked1();
		makel1();
		maked();
		makel();
		maked();
		makeb();
		maked1();
		makeb1();
	}
	}
	while(checkcolor4(front1,left1,face[front][1][0],face[left][2][1])==0)
	{
	maked();
	if(checkcolor4(front1,left1,face[front][2][1],face[bottom][2][1])==1)
	{
		maked();
		makel();
		maked1();
		makel1();
		maked1();
		makef1();
		maked();
		makef();
	}
	if(checkcolor4(front1,left1,face[bottom][1][2],face[left][1][0])==1)
	{
		maked1();
		makef1();
		maked();
		makef();
		maked();
		makel();
		maked1();
		makel1();
	}
	}
}
void solve4ten()
{
	while(check4ten()==0)
	{
	if(check4ten1()==2 || check4ten1()==3)
	{
		while(check4ten1()!=2)
		{
			maked();
		}
		makef();
		makel();
		maked();
		makel1();
		maked1();
		makef1();
		return;
	}
	else
	{
		if(check4ten2()==2 || check4ten2()==3)
		{
			while(check4ten2()!=2)
			{
				maked();
			}
			makef();
			maked();
			makel();
			maked1();
			makel1();
			makef1();
			return;
		}
	}
	makef();
	maked();
	makel();
	maked1();
	makel1();
	makef1();
	}
}
void solve4whole()
{
	while(check4whole1()!=4)
	{
		if(check4whole1()==0)
		{
			while(face[right][2][2]!=bottom1)
			{
				maked();
			}
			makel();
			maked();
			makel1();
			maked();
			makel();
			maked();
			maked();
			makel1();
		}
		if(check4whole1()==1)
		{
			while(face[bottom][2][0]!=bottom1)
			{
				maked();
			}
			makel();
			maked();
			makel1();
			maked();
			makel();
			maked();
			maked();
			makel1();
		}
		if(check4whole1()>=2)
		{
			while(face[front][2][2]!=bottom1)
			{
				if(check4whole1()==4)
				goto here;
				maked();
			}
			makel();
			maked();
			makel1();
			maked();
			makel();
			maked();
			maked();
			makel1();
		}
	}
here: return;
}
void solve3cor()
{
	while(checkcolor5(face[right][0][2],face[back][0][2],right1,back1)==0)
	{
		maked();
	}
	if(checkcolor5(face[front][2][2],face[right][2][2],left1,back1)==1)
	{
		makel1();
		makef();
		makel1();
		makeb();
		makeb();
		makel();
		makef1();
		makel1();
		makeb();
		makeb();
		makel();
		makel();
		maked1();
	}
	if(checkcolor5(face[front][2][0],face[left][2][0],left1,back1)==1)
	{
		makeb1();
		makel();
		makeb1();
		maker();
		maker();
		makeb();
		makel1();
		makeb1();
		maker();
		maker();
		makeb();
		makeb();
		maked1();
	}
	if(checkcolor5(face[front][2][0],face[left][2][0],front1,left1)==0)
	{
		makel1();
		makef();
		makel1();
		makeb();
		makeb();
		makel();
		makef1();
		makel1();
		makeb();
		makeb();
		makel();
		makel();
		maked1();
	}
}
void solve3whole()
{
	int tch=0;
	while(face[back][0][1]!=back1)
	{
		maker();
		maker();
		maked();
		makeb();
		makef1();
		maker();
		maker();
		makeb1();
		makef();
		maked();
		maker();
		maker();
		tch++;
		if(tch==2 || face[back][0][1]==back1)
		break;
	}
	tch=0;
	while(face[back][0][1]!=back1)
	{
		makel();
		makel();
		maked();
		makef();
		makeb1();
		makel();
		makel();
		makef1();
		makeb();
		maked();
		makel();
		makel();
		tch++;
		if(tch==2 || face[back][0][1]==back1)
		break;
	}
	if(face[back][0][1]==back1)
	{
		
		tch=0;
		while(check3()!=1)
		{
			makef();
		    makef();
		    maked();
		    maker();
		    makel1();
		    makef();
		    makef();
		    maker1();
		    makel();
		    maked();
		    makef();
		    makef();
			tch++;
			if(tch==2 || check3()==1)
			break;
		}
		tch=0;
		while(check3()!=1)
		{
			makef();
		    makef();
		    maked1();
		    maker();
		    makel1();
		    makef();
		    makef();
		    maker1();
		    makel();
		    maked1();
		    makef();
		    makef();
			tch++;
			if(tch==2 || check3()==1)
			break;
		}
	}
}
int checkcolor1(int aoc,int boc,int coc,int coloa,int colob,int coloc)
{
	int tc[3]={0,0,0};
	int oc[3]={aoc,boc,coc};
	int colo2[3]={coloa,colob,coloc};
	int i,j;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
		if(oc[i]==colo2[j])
		tc[i]=1;
	}
	if(tc[0]==1 &&tc[1]==1 &&tc[2]==1)
	return 1;
	else
	return 0;
}
int checkcolor2(int aoc,int boc,int coc,int coloa,int colob,int coloc)
{
	int tc[3]={0,0,0};
	int oc[3]={aoc,boc,coc};
	int colo2[3]={coloa,colob,coloc};
	int i;
	for(i=0;i<3;i++)
	{
		if(oc[i]==colo2[i])
		tc[i]=1;
	}
	if(tc[0]==1 &&tc[1]==1 &&tc[2]==1)
	return 1;
	else
	return 0;
}
int checkcolor3(int aoc,int boc)
{
	if(aoc==bottom1 || boc==bottom1)
	return 1;
	else
	return 0;
}
int checkcolor4(int aoc,int boc,int coloa,int colob)
{
	if(aoc==coloa && boc==colob)
	return 1;
	else
	return 0;
}
int checkcolor5(int aoc,int boc,int coloa,int colob)
{
	if((aoc==coloa && boc==colob)||(aoc==colob && boc==coloa))
	return 1;
	else
	return 0;
}
int check4ten1()
{
	if(face[bottom][1][0]==bottom1 && face[bottom][1][2]==bottom1)
	return 2;
	if(face[bottom][0][1]==bottom1 && face[bottom][2][1]==bottom1)
	return 3;
	return 0;
}
int check4ten2()
{
	if(face[bottom][0][1]==bottom1 && face[bottom][1][0]==bottom1)
	return 2;
	if(face[bottom][1][0]==bottom1 && face[bottom][2][1]==bottom1)
	return 3;
	if(face[bottom][2][1]==bottom1 && face[bottom][1][2]==bottom1)
	return 3;
	if(face[bottom][1][2]==bottom1 && face[bottom][0][1]==bottom1)
	return 3;
	return 0;
}
int check4whole1()
{
	int tcw=0;
	if(face[bottom][0][0]==bottom1)
	tcw++;
	if(face[bottom][0][2]==bottom1)
	tcw++;
	if(face[bottom][2][0]==bottom1)
	tcw++;
	if(face[bottom][2][2]==bottom1)
	tcw++;
	return tcw;
}
