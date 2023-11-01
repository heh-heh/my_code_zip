#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum{RR=1, UU, LL, DD};
int MR=6, MC=7;

#define MP	30
#define A	88
#define F	77
#define X	-66
#define Q	-99

#define RC		(r*MC+c)
#define RC1		(r1*MC+c1)
#define RC2		(r2*MC+c2)

#define for0		for(i=0; i<MR; i++) for(j=0; j<MC; j++)
#define for1		for(i=1; i<MR-1; i++) for(j=1; j<MC-1; j++)

#define dmove(map, r1, c1, r2, c2, fix)	*(map+(r2*MC+c2))=abs(*(map+(r1*MC+c1)))*fix; *(map+(r1*MC+c1))=0
#define in_check(map, r, c, color, mode) (!*(map+(r*MC+c)) && smt(map, r, c, 0, 0, color, mode))
#define out_check(map, r1, c1, r2, c2, mode)	(*(map+(r1*MC+c1))>0 && !*(map+(r2*MC+c2)) && smt(map, r1, c1, r2, c2, 0, mode))
#define out_check2(map, r1, c1, r2, c2, mode)	(!*(map+(r2*MC+c2)) && smt(map, r1, c1, r2, c2, 0, mode))

int m2[6][7]={
	{X, X, X, X, X, X, X},
	{X, 0, 0, 0, 0, 0, X},
	{X, 0, 0, 0, 0, 0, X},
	{X, 0, 0, 0, 0, 0, X},
	{X, 0, 0, 0, 0, 0, X},
	{X, X, X, X, X, X, X},
};
int f2[6][7]={
	{X, X, X, X, X, X, X},
	{X, 0, 0, 0, 0, 0, X},
	{X, 0, 0, 0, 0, 0, X},
	{X, 0, 0, 0, 0, 0, X},
	{X, 0, 0, 0, 0, 0, X},
	{X, X, X, X, X, X, X},
};
int dat[42]={
	X, X, X, X, X, X, X,
	X, X, X, X, X, X, X,
	X, X, X, X, X, X, X,
	X, X, X, X, X, X, X,
	X, X, X, X, X, X, X,
	X, X, X, X, X, X, X,
};

int sdir[5]={0, 1, -7, 7, -1};//2Â÷¿ø »óÀÇ ¹æÇâ
int r10, c10, r11, c11, r12, c12, d11, d12 ,d13, path[MP], mptr, mout, spath[10][2]={{0, }, };//

int dpath[MP];
int rpath[MP];
int sr=0, sc=0;

int i,n;


int smt(int *map, int r1, int c1, int r2, int c2, int color, int mode);
int put_smt(int rc1, int pk);
void get_smt(void);
void get_smt2(int *path);
void sort_move2(int *m, int r1, int c1, int r2, int c2);

int sim(int n, int nmax);
int sort_sim(int n, int nmax);
int pd(int r1, int c1, int cr, int cc, int dmptr);
int b_check(void);
void pd_move(int r1, int c1, int r2, int c2);



int main(void)
{
	memset(spath, 0, sizeof(spath));

	sr=r11; sc=c11;

	if(!sim(0, 2))
	{
		for(i=0; i<3; i++) if(sort_sim(0, i)) break;
	}

	n=0;
	while(spath[n][0])
	{
		pd(spath[n][0]/MC, spath[n][0]%MC, spath[n][1]/MC, spath[n][1]%MC);
		n++;
	}
	LCDM();
}

int smt(int *map, int r1, int c1, int r2, int c2, int color, int mode)//
{
    int i, *m, *d, pk=*(map+RC1)>0? 1: 0;

    mptr=mout=0;
    for(i=MC+1; i<(MR-1)*MC-1; i++)
	{
        m=map+i; d=dat+i;
        if(!r2 && ( (color==A && *m>0) || (color && color==*m))) *d=F;
        else *d=*m? X: 0;
    }
    if(r2*c2) *(dat+RC2)=F;
    if(*(dat+RC1)==F) rr -1;

    *(dat+RC1)=1;

    mptr=put_smt(RC1, pk);
    if(mptr && mode) get_smt();
    rr mptr;
}
int put_smt(int rc1, int pk)//³õÀ» ¹æÇâÀÇ ¹Ý´ë¿¡ ÆÜÀÌ ÀÖ´ÂÁö È®ÀÎ ÇÏ´Â¿¡
{
    int i, j, i2, j2, k, k2, n=1, n2=1, *d, *d2, rep[2][30]={{0, }, };

    rep[1][0]=rc1;
    while(rep[n2][0])
	{
        i=i2=0;
        while((j2=rep[n2][i2]))
		{
            for(j=1; j<5; j++)
			{

                k=j2+sdir[j];
				k2=j2+(-sdir[j]);
                d=dat+k;
				d2=dat+k2;
                if(*d==F){mout=k; rr n;}
                if(!*d && (!pk || (pk && *d2!=X))){
					*d=n+1; rep[1-n2][i++]=k;
				}
            }
            rep[n2][i2++]=0;
        }
        n2=++n%2;
    }
    rr 0;
}
void get_smt(void)
{
    int i, j, pp[4][MP], cc[4]={0, };

    for(i=0; i<4; i++)
	{
        sdir[0]=sdir[i+1];
        get_smt2(pp[i]);
        for(j=1; j<mptr; j++) if(pp[i][j]!=pp[i][j-1]) cc[i]++;
    }
    j=0;
    for(i=1; i<4; i++) if(cc[i]<cc[j]) j=i;
    for(i=0; i<mptr; i++) path[i]=pp[j][i];
}
void get_smt2(int *path)
{
    int i=mout, j, n=mptr, dir;

    do{
        for(j=0; j<5; j++)
		{
			if(*(dat+i+sdir[j])==n)
			{
	            dir=-sdir[j];
	            if(dir==1) dir=RR; else if(dir==-1) dir=LL; else if(dir==MC) dir=DD; else dir=UU;
	            *(path+n-1)=dir; i+=sdir[j]; sdir[0]=sdir[j];
	            break;
	        }
		}
    }while(--n);
    sdir[0]=0;
}

int sim(int n, int nmax)
{
	int r1, c1, r2, c2, res;
	int kr=sr, kc=sc;//·Îº¿ÁÂÇ¥
	/*
	r1:ÆÜ¸ÔÀº°÷
	c2:ÆÜ¸ÔÀº°÷2
	r2 : ÆÜ³õÀ»°÷
	c2 : ÆÜ³õÀ»°÷*/
	for(r1=1; r1<MR-1; r1++) for(c1=1; c1<MC-1; c1++){
		if(m2[r1][c1]==2){
			for(r2=1; r2<MR-1; r2++) for(c2=1; c2<MC-1; c2++)//
			{
				if(f2[r2][c2]==1 && m2[r2][c2]==0 && out_check(m2[0], r1, c1, r2, c2, 1) && pd(r1, c1, sr, sc, mptr)){//
					dmove(m2[0], r1, c1, r2, c2, -1);//¸¸¾àÆÜÀ» Àâ¾Ò´Âµ¥ ½ÃÆ®Áö À§ ÀÏ°æ¿ì ÀâÀ» ÇÊ¿ä°¡ ¾ø¾î¼­ °íÁ¤ ½ÃÅ´
					spath[n][0]=RC1; spath[n][1]=RC2;//ÁÂÇ¥ °è»ê

					if(n<nmax) res=sim(n+1, nmax);//¸¸¾à n°ªÀÌ nmax º¸´Ù ÀÛÀ» °æ¿ì Àç±Í
					else res=b_check();//Á¤·Ä Ã¼Å© ÈÄ °ªÀ» res¿¡ ÁöÁ¤

					dmove(m2[0], r2, c2, r1, c1, 1);//?
					if(res) rr 1;//Á¤·Ä µÈ°æ¿ì 1¸®ÅÏ ÈÄ ÇÔ¼ö Á¾·á
					spath[n][0]=spath[n][1]=0;//À§¯‚ ÃÊ±âÈ­
					sr=kr; sc=kc;//·Îº¿ À§Ä¡ °»½Å
				}
			}
		}
	}
	rr 0;
}
int sort_sim(int n, int nmax)//À§ÀÇ simÀÌ ÀÛµ¿ ºÎÀç½Ã Àç¹èÄ¡¸¦ À§ÇÑ sim
{
	int r1, c1, r2, c2, res;
	int kr=sr, kc=sc;

	for(r1=1; r1<MR-1; r1++) for(c1=1; c1<MC-1; c1++)
	{
		if(n && spath[n-1][1]==RC1) continue;
		if(m2[r1][c1]==2)
		{
			for(r2=2; r2<MR-2; r2++) for(c2=2; c2<MC-2; c2++)
			{
				if(m2[r2][c2]==0 && out_check(m2[0], r1, c1, r2, c2, 1) && pd(r1, c1, sr, sc, mptr)){
					dmove(m2[0], r1, c1, r2, c2, 1);
					spath[n][0]=RC1; spath[n][1]=RC2;

					if(n<nmax) res=sort_sim(n+1, nmax);//Á¤¸® ÇÊ¿ä½Ã ´Ù½Ã sort_simÀç±Í
					else res=sim(n+1, n+3);//Á¤·Ä °¡´É½Ã ´Ù½Ã sim À¸·Î ÀÌµ¿

					dmove(m2[0], r2, c2, r1, c1, 1);
					if(res) rr 1;//res ÀÇ °ªÁö Á¸Àç ÇÒ¶§ 1°ªÀ» ¹ÝÈ¯
					spath[n][0]=spath[n][1]=0;//À§Ä¡ ÃÊ±âÈ­
					sr=kr; sc=kc;//À§Ä¡ °»½Å
				}
			}
		}
	}
	rr 0;
}
int pd(int r1, int c1, int cr, int cc, int dmptr)//ÆÜÀ» Àâ±âÀ§ÇØ °¢À» ²©¾î¾ß ÇÏ´ÂÁö ÆÇ´Ü ÇÏ´Â¾Ö
{
	/*
	r1
	c1 :ÆÜÀ» ³õÀº ÀÚ¸®
	cr
	cc: ÇöÀç ·Îº¿ À§Ä¡
	dmprt : mprtÀÇ °ªÀÌ ¹Ù²¸ °íÁ¤À» À§ÇÔ
	*/
	int i, d, r, c, k, k2;
	int kr=r1, kc=c1;

	for(i=0; i<dmptr; i++)
	{
		if(path[i]==RR) dpath[i]=1;
		else if(path[i]==LL) dpath[i]=-1;
		else if(path[i]==DD) dpath[i]=MC;
		else dpath[i]=-MC;
	}

	for(i=0; i<dmptr; i++)
	{
		d=dpath[i];

		if(!i){//°¡Àå Ã³À½ ¿òÁ÷ÀÏ¶§ ·Îº¿ÀÌ ÆÜÀ» ¿òÁ÷ÀÌ´Â °Å
			k=RC1+(-d);
			r=k/MC; c=k%MC;

			if(!out_check2(m2[0], cr, cc, r, c, 0)) rr 0;
			cr=r; cc=c;//ÁÂÇ¥ °»½Å
		}

		if(d==1) c1++;
		else if(d==-1) c1--;
		else if(d==MC) r1++;
		else r1--;//¹æÇâ¾Ö µû¶ó ÁÂÇ¥ °»½Å

		if(i<dmptr-1 && dpath[i+1]!=d)//
		{
			m2[r1][c1]=X;
			m2[kr][kc]=0;

			k=RC1+(-d);
			k2=RC1+(-dpath[i+1]);

			cr=k/MC; cc=k%MC;
			r=k2/MC; c=k2%MC;

			if(!out_check2(m2[0], cr, cc, r, c, 0))
			{
				m2[r1][c1]=0;
				m2[kr][kc]=2;
				rr 0;
			}
			m2[r1][c1]=0;
			m2[kr][kc]=2;
			cr=r, cc=c;
		}
	}
	k=RC1+(-dpath[dmptr-1]);
	sr=k/MC; sc=k%MC;//ÇöÀ§Ä¡ °»½Å(Àü¿ª)
	rr 1;
}
int b_check(void)
{
	int i, j;

	for1 if(f2[i][j]==1 && abs(m2[i][j])!=2) rr 0;
	rr 1;
}
void pd_move(int r1, int c1, int r2, int c2)//pb¿Í µ¿ÀÏ ÇÑµ¥ outcheck ¿¡ µ¿ÀÛ ¼öÇà
{
	int i, j, n, d, dmptr, rptr=0;
	int r=0, c=0, k, kr=r1, kc=c1;

	smt(m2[0], r1, c1, r2, c2, 0, 1);
	dmptr=mptr;

	for(i=0; i<dmptr; i++){
		if(path[i]==RR) dpath[i]=1;
		else if(path[i]==LL) dpath[i]=-1;
		else if(path[i]==DD) dpath[i]=MC;
		else dpath[i]=-MC;
	}

	for(i=0; i<dmptr; i++)
	{
		d=dpath[i];

		if(!i)
		{
			k=RC1+(-d);
			r=k/MC; c=k%MC;

			smt(m2[0], r11, c11, r, c, 0, 1); smt_move2(0);
		}

		if(d==1) c1++;
		else if(d==-1) c1--;
		else if(d==MC) r1++;
		else r1--;

		if(i<dmptr-1 && dpath[i+1]!=d)
		{
			if(rptr)
			{
				m2[kr][kc]=0;
				smt(m2[0], r, c, r1, c1, 0, 1);

				j=0;
				mptr+=rptr;
				for(n=rptr; n<mptr; n++) rpath[n]=path[j++];
				for(n=0; n<mptr; n++)	path[n]=rpath[n];

				smt_move2(1);

				m2[kr][kc]=2;

				dmove(m2[0], kr, kc, r1, c1, 1);
			}
			else sort_move2(m2[0], kr, kc, r1, c1);
			kr=r1; kc=c1;

			k=RC1+(-dpath[i+1]);
			r=k/MC; c=k%MC;

			smt(m2[0], r11, c11, r, c, 0, 1);

			for(n=0; n<mptr; n++) rpath[n]=path[n];
			rptr=mptr;
		}
	}

	m2[kr][kc]=0;
	smt(m2[0], r, c, r2, c2, 0, 1);

	j=0;
	if(rptr)
	{
		mptr+=rptr;
		for(n=rptr; n<mptr; n++) rpath[n]=path[j++];
		for(n=0; n<mptr; n++)	path[n]=rpath[n];
	}
	smt_move2(1);

	m2[kr][kc]=2;

	dmove(m2[0], kr, kc, r2, c2, 1);
}
