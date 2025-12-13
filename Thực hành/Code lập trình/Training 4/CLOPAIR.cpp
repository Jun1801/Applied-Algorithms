#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<limits>
#include<set>
using namespace std;
const long long int INF = 1LL << 60;
int flag[50001];

typedef struct
{
	int x;
	int y;
	int index;
}point;

typedef struct
{
	int p1;
	int p2;
	long long int dist;
}clopair;

bool sortX(point p1, point p2)
{
	return p1.x< p2.x;
}

bool sortY(point p1, point p2)
{
	return p1.y < p2.y;
}

void formlist(point Ys[], point byY[], int length, int x, long long int d, int* ptr)
{

	for(int i=0;i<length;i++)
	{
		if((byY[i].x - x)*(byY[i].x - x) <= d)
			Ys[(*ptr)++] = byY[i];
	}
}
clopair closestPair(point byX[], point byY[],int start, int end)
{
	clopair final;
	if(start==end)
	{
		final.dist = INF;
		return final;
	}
	else if(end-start == 1)
	{
		final.p1 = byX[start].index;
		final.p2 = byX[end].index;
		long long int xdiff = byX[start].x - byX[end].x;
		long long int ydiff = byX[start].y - byX[end].y;
		final.dist = xdiff*xdiff + ydiff*ydiff;
		return final;
	}
	else
	{
		point Yleft[(end-start+1)/2 ] ;
		point Yright[ (end-start+1) - ((end-start+1)/2)];
		int i;
		for(i=start;i < start + ((end-start+1)/2);i++)
		{
			flag[byX[i].index]=1;
		}
		for(;i<=end;i++)
		{
			flag[byX[i].index]=0;
		}
		int yl=0;
		int yr=0;
		for(i=0;i<=end-start;i++)
		{
			if(flag[byY[i].index]==0)
				Yright[yr++] = byY[i];
			else
				Yleft[yl++] = byY[i];
		}
		clopair left = closestPair(byX,Yleft,start, start + ((end-start+1)/2) - 1);
		clopair right = closestPair(byX,Yright,start + ((end-start+1)/2),end);
		clopair d;
		if(left.dist < right.dist)
			d = left;
		else
			d = right;
		point Ys[end-start+1];
		int len=0;
		formlist(Ys,byY,end-start+1,byX[start + (end-start+1)/2 -1].x,d.dist,&len);
		clopair temp;
		temp.dist = INF;
		for(int i=0;i<len;i++)
		{
			for(int j=1;j<=7;j++)
			{
				if(i+j<len)
				{
					long long int dx = Ys[i].x - Ys[i+j].x;
					long long int dy = Ys[i].y - Ys[i+j].y;
					long long int distance = dx*dx + dy*dy;
					if(distance<temp.dist)
					{

						temp.dist = distance;
						temp.p1 = Ys[i].index;
						temp.p2 = Ys[i+j].index;
					}
				}
				else
					break;
			}
		}
		return d.dist < temp.dist ? d:temp;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	point byX[n];
	point byY[n];
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		byX[i].x = byY[i].x = x;
		byX[i].y = byY[i].y = y;
		byX[i].index = byY[i].index = i;
	}
	sort(byX,byX+n,sortX);
	sort(byY,byY+n,sortY);
	clopair ans = closestPair(byX, byY, 0, n-1);
	int mini = min(ans.p1,ans.p2);
	int maxi = max(ans.p1,ans.p2);
	printf("%d %d %.6f\n",mini,maxi,round(1000000*sqrt((double)ans.dist))/1000000);
	return 0;
}
