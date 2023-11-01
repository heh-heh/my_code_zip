#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ps system("PAUSE")

#define MR 5
#define MC 5
#define MP 50
#define X -9
#define rr return
#define bb break;

#define fo1(i,a,b) for(int i=a; i!=b; i+=a<b ? 1 : -1)
#define fo2(j,a,b) for(int j=a; j!=b; j+=a<b ? 1 : -1)
#define fo3 for(int k=1; k<4; k++)

#define T1(x) x==1 ? 1 : 3
#define T2(x) x==1 ? 1 : x==2 ? 3 : 2

#define pu fo1(i,1,MR-1) fo2(j,1,MC-1) xmap[i][j] = map[i][j];
#define pc fo1(i,1,4) fo2(j,1,4) if(smap[i][j] && smap[i][j] == map[i][j]) tmap[i][j]=1; else tmap[i][j]=0;

void SAT(int n);
int ST(void);
int ST2(void);
int smt(int n, int* dat);
int swap(int a, int b, int x, int y);
int ck(int a, int b, int x, int y);
void pr(void);

void turn(int a);
void move(int dir1, int p);

int map[5][5]={
    {X,X,X,X,X},
    {X,1,2,2,X},
    {X,1,0,1,X},
    {X,0,0,0,X},
    {X,X,X,X,X}
};

int smap[5][5]={
    {X,X,X,X,X},
    {X,0,0,0,X},
    {X,0,2,0,X},
    {X,0,0,0,X},
    {X,X,X,X,X}
};

int emap[5][5]={
    {X,X,X,X,X},
    {X,0,0,0,X},
    {X,0,2,0,X},
    {X,0,0,0,X},
    {X,X,X,X,X}
};

int tmap[5][5]={
    {X,X,X,X,X},
    {X,0,0,0,X},
    {X,0,0,0,X},
    {X,0,0,0,X},
    {X,X,X,X,X}
};

int xmap[5][5]={
    {X,X,X,X,X},
    {X,0,0,0,X},
    {X,0,0,0,X},
    {X,0,0,0,X},
    {X,X,X,X,X}
};
    
int cmap[3]={0,1,2};


int mpath[50][2], path[50], mptr = 0, mptr2 = 0, quit = 0, quit2 = 0;
int sdir1[5] = { 0,-MC,1,MC,-1 };
int dir = 0, now = 0, sdir = 0, move_turn = 0;

int main()
{
    if(smap[2][1] || smap[2][2] || smap[2][3]) SAT(1);
    else SAT(0);
    ST();
    fo1(i,0,MR) fo2(j,0,MC) smap[i][j]=emap[i][j];
    SAT(0);
    pc; pu;
    //ST2();
    return 0;
}

void SAT(int n){
    fo1(i,1,MR-1) fo2(j,1,MC-1) if(smap[i][j]){
        fo3 if(!smap[k][j]) smap[k][j]=2;
        fo3 if(!smap[i-n][k]) smap[i-n][k]=1;
        pr();
        rr;
    }
}

int ST(void){
    fo1(i,1,4) if(map[2][i]) swap(2,i,3,i);
    pc;
    fo1(i,1,4) fo2(j,1,4) if(map[1][i] && !map[3][i] && !tmap[1][j]) swap(1,j,3,i);
    for(int t=1; t<MR-1; t++) for(int tt=1; tt<MC-1; tt++){
        if(!tmap[t][tt] && smap[t][tt]){
            fo1(i,1,MR-1) fo2(j,1,MC-1) if(map[t][tt]){
                if(!map[T1(i)][j]){
                    swap(t,tt,T1(i),j);
                    pc;
                }
            }
            fo1(i,1,MR-1) fo2(j,1,MC-1){
                if(!tmap[T1(i)][j] && smap[T1(t)][tt] == map[T1(i)][j]){
                    swap(T1(i),j,T1(t),tt);
                    pc;
                }
            }
        }
    }
    rr 0;
}

int ST2(void){
    fo1(i,1,MR-1) if(!tmap[3][i] && smap[2][2] && smap[2][2] == map[3][i]){
        swap(3,i,2,2); tmap[2][2]=1;
    }
    for(int t=1; t<MC-1; t++) if(!tmap[2][t] && smap[2][t]){
        fo1(i,1,MR-1) if(!tmap[1][i] && smap[2][t] == map[1][i]){
            swap(1,i,2,t);
            tmap[2][t]=1;
            rr ST2();
        }
    }
    rr 0;
}

int smt(int n, int* dat){
    int i, j, * p, dir;
   ///move_turn = 0;
    do {
        j = 0;
        for (i = MC; i < (MR - 1) * MC; i++) if (*(dat + i) == n) {
            j++;
            for (dir = 1; dir < 5; dir++) {
                p = (dat + i) + sdir1[dir];
                if (!*p)*p = n + 1;
                else if (*p == 999) {
                    if (!quit) quit = i + sdir1[dir];
                    if (quit && mptr == 0) quit2 = i;
                    else if (quit && !quit2) quit2 = i + sdir1[dir];
                    *(dat + i) = 999;
                    //move_turn++;
                    path[mptr++]= dir;
                    rr 1;
                }
            }
        }
    } while (j && smt(n + 1, dat));
    rr 0;
}

int swap(int a, int b, int x, int y){
    int t=map[x][y];
    if(!map[a][b] || map[x][y] || !ck(a,b,x,y)) rr 0;

    pu;
    now = &map[a][b]-&map[0][0];printf("%d\n",now);
    xmap[a][b]=1; xmap[x][y]=999;
    //for(int ii=0; ii<MR; ii++) for(int jj=0; jj<MC; jj++) if(xmap[ii][jj]!=0&&ii!=x&&ii!=y&&ii!=b&&ii!=a)xmap[ii][jj]=-9;
    smt(1,&xmap[0][0]);
    for(int ii=mptr-1; ii>=0; ii--){
        move(path[ii],0);
    }mptr=0;

    map[x][y]=map[a][b]; map[a][b]=t;
    pr();
}

int ck(int a, int b, int x, int y){
    pu;
    xmap[a][b]=1; xmap[x][y]=999;
    printf("\n\n%d\n\n\n",smt(1,&xmap[0][0]));
    rr smt(1,&xmap[0][0]);
}

void pr(void){
    int iii=0;
    for(int ii=0; ii<MR; ii++){for(int jj=0; jj<MC; jj++) printf("%3d ",iii++); printf("\n\n");}

    printf("map\n");
    fo1(i,1,MR-1){
        fo2(j,1,MC-1) printf("%d ",map[i][j]);
        printf("\n");
    } printf("\n");
    printf("Tmap\n");
    fo1(i,1,MR-1){
        fo2(j,1,MC-1) printf("%d ",tmap[i][j]);
        printf("\n");
    } printf("\n");
    printf("Smap\n"); 
    fo1(i,1,MR-1){
        fo2(j,1,MC-1) printf("%d ",smap[i][j]);
        printf("\n");
    }
    printf("\n=============================\n");getchar();
    //ps;
}

void turn(int a){
	// gety;
	if(a!=sdir){
		int rt = sdir-a;
		if(a == 4|| a==1){
			// if(sdir==1) t(-900,100);
			// else t(900,100);
		}
		// else if(rt > 0) for(int ii=0; ii<abs(rt); ii++)t(-900,100);
		// else for(int ii=0; ii<abs(rt); ii++)t(900,100);
		sdir=a;
		// cg(900*rt);
	}
}
void move(int dir1, int p){
    if(p){
        printf("%d %d\n", dir1, now);getchar;
    }
    else{
        now += sdir1[dir1];
        printf("%d %d\n", dir1, now);getchar;
    }
}