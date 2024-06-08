#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void up(int a[4][4])//Moving the contents Up
{
    int i,j,lt,ri;
    for(j=0;j<4;j++)
    {
        lt=0,ri=j;
        for(i=1;i<4;i++)
        {
            if(a[i][j]!=0)
            {
                if(a[i-1][j]==0||a[i-1][j]==a[i][j])
                {
                    if(a[lt][ri]==a[i][j])
                    {
                        a[lt][ri]*=2;
                        a[i][j]=0;
                    }
                    else
                    {
                        if(a[lt][ri]==0)
                        {
                            a[lt][ri]=a[i][j];
                            a[i][j]=0;
                        }
                        else
                        {
                            a[++lt][ri]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }
                else
                {
                    lt++;
                }
            }
        }
    }
}
void down(int a[4][4])//Moving the contents down
{
    int i,j,lt,ri;
        for(j=0;j<4;j++)
    {
        lt=3,ri=j;
        for(i=2;i>=0;i--)
        {
            if(a[i][j]!=0)
            {
                if(a[i+1][j]==0||a[i+1][j]==a[i][j])
                {
                    if(a[lt][ri]==a[i][j])
                    {
                        a[lt][ri]*=2;
                        a[i][j]=0;
                    }
                    else
                    {
                        if(a[lt][ri]==0)
                        {
                            a[lt][ri]=a[i][j];
                            a[i][j]=0;
                        }
                        else
                        {
                            a[--lt][ri]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }
            else
            {
                lt--;
            }
            }
        }
    }
}

void left(int a[4][4])//Moving the contents to the left
{
    int i,j,lt,ri;
    for(i=0;i<4;i++)
    {
        lt=i,ri=0;
        for(j=1;j<4;j++)
        {
            if(a[i][j]!=0)
            {
                if(a[i][j-1]==0||a[i][j-1]==a[i][j])
                {
                    if(a[lt][ri]==a[i][j])
                    {
                        a[lt][ri]*=2;
                        a[i][j]=0;
                    }
                    else
                    {
                        if(a[lt][ri]==0)
                        {
                            a[lt][ri]=a[i][j];
                            a[i][j]=0;
                        }
                        else
                        {
                            a[lt][++ri]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }

            else
            {
                ri++;
            }
        }
        }
    }
}

void right(int a[4][4])//Moving the contents to the right
{
    int i,j,lt,ri;
    for(i=0;i<4;i++)
    {
        lt=i,ri=3;
        for(j=2;j>=0;j--)
        {
            if(a[i][j]!=0)
            {
                if(a[i][j+1]==0||a[i][j+1]==a[i][j])
                {
                    if(a[lt][ri]==a[i][j])
                    {
                        a[lt][ri]*=2;
                        a[i][j]=0;
                    }
                    else
                    {
                        if(a[lt][ri]==0)
                        {
                            a[lt][ri]=a[i][j];
                            a[i][j]=0;
                        }
                        else
                        {
                            a[lt][--ri]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }
            else
            {
                ri--;
            }
            }
        }
    }
}

void join(int a[4][4])
{
    int lt,ri;
    srand(time(0));
    while(1)
    {
        lt=rand()%4;
        ri=rand()%4;
        if(a[lt][ri]==0)
        {
            a[lt][ri]=pow(2,lt%2+1);
            break;
        }
    }
}

void display(int a[4][4])
{
	cout<<"\n\t\t PRESS \"ESC\" TO QUIT THE GAME";
	cout<<"\n\n\n\n";
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t-----------------\n\t\t\t\t";
		for(j=0;j<4;j++)
		{
			if(a[i][j]==0) cout<<"|   ";
			else
				cout<<"| "<<a[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t-----------------\n";
}

int check(int temp[4][4], int a[4][4])
{
    int i,j,f=1;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(temp[i][j]!=a[i][j])
            {
                f=0;
                break;
            }
        }
    }
    return(f);
}

int checkgameover(int a[4][4])
{
    int f=0,g=0,i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0)
            {
                f=1;
                break;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i+1][j]==a[i][j]||a[i][j+1]==a[i][j])
            {
                g=1;
                break;
            }
        }
    }
    if(f||g)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    cout<<"\n\n\n\n\t\t\t 2048 GAME \n\n\n\t\t PRESS ENTER TO BEGIN........";
    getch();
    system("cls");
    int i1,i2,i3,i4,i,j;
    int a[4][4]={0};
    int temp[4][4]={0};
    i1=rand()%4;
    i2=rand()%4;
    while(1)
    {
        i3=rand()%4;
        i4=rand()%4;
        if(i3!=i1||i4!=i2)
        {
            break;
        }
    }
    a[i1][i2]=2;
    a[i3][i4]=4;
    display(a);
    int ch;
    while(1)
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                temp[i][j]=a[i][j];
            }
        }
        ch=getch();
        system("cls");
        if(ch==72)
        {
            up(a);
        }
        if(ch==80)
        {
            down(a);
        }
        if(ch==75)
        {
            left(a);
        }
        if(ch==77)
        {
            right(a);
        }
        if(ch==27)
        {
            break;
        }
        if(!check(temp,a))
        {
            join(a);
        }
        display(a);

        if(!checkgameover(a))
        {
            cout<<"\n\n\n\t\t\t GAME OVER \n\n\n";
            getch();
            break;
        }
    }
    return 0;
}
