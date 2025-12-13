#include<bits/stdc++.h>
#define NDS ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
const long long int INF = LLONG_MAX;
int flag[50001];
typedef struct
{
	int x, y;
	int index;
}point;
typedef struct
{
	int p1, p2;
	long long int dist;
}clopair;
bool checkX(point p1, point p2)
{
	return p1.x< p2.x;
}

bool checkY(point p1, point p2)
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
clopair closestPair(point byX[], point byY[],int start, int c)
{
	clopair final;
	if(start == c)
	{
		final.dist = INF;
		return final;
	}
	else if(c - start == 1)
	{
		final.p1 = byX[start].index;
		final.p2 = byX[c].index;
		long long int xdiff = byX[start].x - byX[c].x;
		long long int ydiff = byX[start].y - byX[c].y;
		final.dist = xdiff*xdiff + ydiff*ydiff;
		return final;
	}
	else
	{
		point Yleft[(c - start+1)/2 ] ;
		point Yright[ (c - start+1) - ((c - start+1)/2)];
		int i;
		for(i=start;i < start + ((c - start+1)/2);i++)
		{
			flag[byX[i].index]=1;
		}
		for(;i <= c;i++)
		{
			flag[byX[i].index] = 0;
		}
		int yl = 0;
		int yr = 0;
		for(i = 0;i <= c-start;i++)
		{
			if(flag[byY[i].index]==0)
				Yright[yr++] = byY[i];
			else
				Yleft[yl++] = byY[i];
		}
		clopair left = closestPair(byX,Yleft,start, start + ((c-start+1)/2) - 1);
		clopair right = closestPair(byX,Yright,start + ((c-start+1)/2),c);
		clopair d;
		if(left.dist < right.dist)
			d = left;
		else
			d = right;
		point Ys[c-start+1];
		int len=0;
		formlist(Ys,byY,c-start+1,byX[start + (c-start+1)/2 -1].x,d.dist,&len);
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
    NDS
	int n;
	cin >> n;
	point X[n];
	point Y[n];
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		X[i].x = Y[i].x = x;
		X[i].y = Y[i].y = y;
		X[i].index = Y[i].index = i;
	}
	sort(X,X+n,checkX);
	sort(Y,Y+n,checkY);

	clopair ans = closestPair(X, Y, 0, n-1);
	int mini = min(ans.p1,ans.p2);
	int maxi = max(ans.p1,ans.p2);
	printf("%d %d %.6f\n",mini,maxi,round(1000000*sqrt((double)ans.dist))/1000000);
	return 0;
}
