/*		sudoku.c		*/
#include <stdio.h>
#include <stdlib.h>
/*
#define		CROSS			/* 対角要素の制限を付加するオプション */
#define		N		1

void printmatrix(void);
int datain(int mn, int point);
void determine(void);
void printans(int mn, int *ans);
void save(int *rs, int *cs, int *vs);
int assume(int *i, int *j, int *rr, int *cc, int rs, int cs, int vs);
void nestup(int *rk, int i, int j, int rr, int cc, int v, int *cs, int *vs);
void nestdown(int *rk, int *rs, int *cs, int *vs);
void load(int rk);

int data[N][81] = {

/*
{ 0,0,4, 5,0,0, 0,8,0,  0,3,0, 0,6,0, 7,0,4,  0,2,0, 0,7,8, 0,5,0,
  1,0,0, 0,0,0, 4,0,0,  9,8,7, 0,0,0, 5,6,0,  0,0,6, 0,0,0, 0,0,7,
  0,0,3, 6,5,0, 0,0,8,  0,0,0, 0,4,0, 1,9,0,  0,0,0, 0,3,2, 0,0,0}
*/


{ 0,0,4, 5,0,7, 8,0,0,  0,3,0, 0,6,0, 0,9,0,  0,2,0, 8,0,4, 0,1,0,
  1,0,0, 0,5,0, 0,0,2,  0,0,0, 0,0,0, 0,0,0,  5,4,0, 0,2,0, 0,7,6,
  0,6,0, 0,0,0, 0,5,0,  0,7,9, 0,1,0, 2,4,0,  0,0,8, 9,0,2, 3,0,0}


/*
{ 0,6,0, 2,0,4, 0,5,0,  4,7,0, 0,6,0, 0,8,3,  0,0,5, 0,7,0, 1,0,0,
  9,0,0, 1,0,3, 0,0,2,  0,1,2, 0,0,0, 3,4,0,  6,0,0, 7,0,9, 0,0,8,
  0,0,6, 0,8,0, 7,0,0,  1,4,0, 0,9,0, 0,2,5,  0,8,0, 3,0,5, 0,9,0}
*/

/*
{ 0,0,0, 3,0,0, 0,1,0,  0,9,4, 0,0,1, 0,0,7,  2,0,0, 7,0,0, 4,0,0,
  0,0,0, 0,5,0, 3,0,0,  5,8,0, 0,0,0, 0,6,9,  0,0,3, 0,8,0, 0,0,0,
  0,0,7, 0,0,5, 0,0,6,  6,0,0, 4,0,0, 2,8,0,  0,1,0, 0,0,6, 0,0,0}
*/

/*
{ 0,0,3, 0,4,0, 8,0,0,  0,0,0, 1,0,9, 0,0,0,  2,0,9, 0,0,0, 3,0,7,
  0,5,0, 0,0,0, 0,4,0,  8,0,0, 0,2,0, 0,0,9,  0,1,0, 0,0,0, 0,6,0,
  5,0,1, 0,0,0, 4,0,6,  0,0,0, 2,0,5, 0,0,0,  0,0,6, 0,8,0, 7,0,0}
*/

/*
{ 0,2,0, 0,7,5, 0,1,0,  1,0,0, 0,0,4, 5,0,8,  0,5,6, 8,0,0, 2,0,0,
  8,1,0, 0,0,0, 7,0,0,  9,0,0, 0,0,0, 0,0,3,  0,0,2, 0,0,0, 0,4,5,
  0,0,9, 0,0,1, 4,3,0,  3,0,1, 7,0,0, 0,0,9,  0,7,0, 3,9,0, 0,2,0}
*/

/*
{ 0,0,1, 0,0,0, 8,0,0,  0,2,0, 0,1,0, 0,7,0,  3,0,0, 0,2,0, 0,0,6,
  0,0,2, 0,3,0, 7,0,0,  4,0,0, 2,0,7, 0,0,5,  0,0,0, 0,6,0, 0,0,0,
  5,0,0, 0,7,0, 0,0,4,  0,6,0, 0,8,0, 0,3,0,  0,0,7, 6,0,3, 2,0,0}
*/

};

static int nstack = 50;
int cq, rq, iq, jq;
int ds, dss;
int D[10], R[9], C[9], Mat[3][3];
int AR[9], AC[9], AM[3][3];
int V[9][9];
int AV[9][9];
int *RS, *CS, *VS;
#ifdef	CROSS
int X1, X2, AX1, AX2;
#endif

void printmatrix(void)
{
	int i, j, k;

	for(j = 0; j < 3; j++)
	{
		printf("+");
		for(k = 0; k < 3; k++)	printf("---");
	}
	printf("+\n");
	for(i = 0; i < 9;)
	{
		printf("|");
		for(j = 0; j < 9;)
		{
			printf("%2d ", V[i][j]);
			if(++j % 3 == 0)	printf("|");
		}
		printf("\n");
		if(++i % 3 == 0)
		{
			for(j = 0; j < 3; j++)
			{
				printf("+");
				for(k = 0; k < 3; k++)	printf("---");
			}
			printf("+\n");
		}
	}
}

void printans(int mn, int *ans)
{
	printf("*** answer %d - %d ***\n", mn, (*ans)++);
	printmatrix();
}

int datain(int mn, int point)
{
	int c, i, ii, j, jj, p, r, s, v;

	p = 0;
	if(point >= N)	return 0;
	for(i = 0; i < 9; i++)	R[i] = C[i] = 511;
	for(i = 0; i < 3; i++)	for(j = 0; j < 3; j++)	Mat[i][j] = 511;
#ifdef	CROSS
	X1 = X2 = 511;
#endif
	ds = r = 0;
	for(i = 0; i < 3; i++)
	{
		for(ii = 0; ii < 3; ii++, r++)
		{
			c = 0;
			for(j = 0; j < 3; j++)
			{
				for(jj = 0; jj < 3; jj++, c++)
				{
					V[r][c] = v = data[point][p++];
					if(v == 0)	continue;
					ds++;
					s = D[v];
					R[r] -= s;
					C[c] -= s;
					Mat[i][j] -= s;
				}
			}
		}
	}
#ifdef	CROSS
	for(p = 0; p < 9; p++)
	{
		if(V[p][p])			X1 -= D[V[p][p]];
		if(V[p][9 - p])	X2 -= D[V[p][9 - p]];
	}
#endif
	printf("*** problem %d ***\n", mn);
	printmatrix();
	return 1;
}

void determine(void)
{
	int rc, rm, cc, cm, mm, mr, s;
	int c, f, i, ii, j, jj, nc, r, v;

	do
	{
		f = 0;
		for(v = 1; v <= 9; v++)
		{
			s = D[v];
#ifdef	CROSS
			if(X1 == s)
			{
				f++;
				for(r = 0; r < 9; r++)
				{
					if(V[r][r])	continue;
					V[r][r] = v;
					R[r / 3] -= s;
					C[r / 3] -= s;
					Mat[r / 3][r / 3] -= s;
					break;
				}
			}
			if(X2 == s)
			{
				f++;
				for(r = 0; r < 9; r++)
				{
					c = 9 - r;
					if(V[r][c])	continue;
					V[r][c] = v;
					R[r / 3] -= s;
					C[c / 3] -= s;
					Mat[r / 3][c / 3] -= s;
					break;
				}
			}
#endif
			r = 0;
			for(i = 0; i < 3; i++)
			{
				for(ii = 0; ii < 3; ii++, r++)
				{
					rc = R[r];
					if((rc & s) == 0)	continue;
					nc = 0;
					for(j = 0; j < 3; j++)
					{
						if((s & Mat[i][j]) == 0)	continue;
						c = j * 3;
						rm = rc & Mat[i][j];
						for(jj = 0; jj < 3; jj++, c++)
						{
							if(V[r][c] > 0 || (s & C[c]) == 0)	continue;
							if((s ^ (rm & C[c])) == 0)
							{
								nc = 1;
								cq = c;
								jq = j;
								goto next1;
							}
							nc++;
							if(nc == 1)
							{
								cq = c;
								jq = j;
							}
						}
					}
next1:				if(nc == 1)
					{
						f++;
						V[r][cq] = v;
						R[r] -= s;
						C[cq] -= s;
						Mat[i][jq] -= s;
#ifdef	CROSS
						if(r == cq)	X1 -= s;
						if(r == 3 - cq)	X2 -= s;
#endif
					}
				}
			}
			c = 0;
			for(j = 0; j < 3; j++)
			{
				for(jj = 0; jj < 3; jj++, c++)
				{
					cc = C[c];
					if((cc & s) == 0)	continue;
					nc = 0;
					for(i = 0; i < 3; i++)
					{
						if((s & Mat[i][j]) == 0)	continue;
						r = i * 3;
						cm = cc & Mat[i][j];
						for(ii = 0; ii < 3; ii++, r++)
						{
							if(V[r][c] > 0 || (s & R[r]) == 0)	continue;
							if((s ^ (cm & R[r])) == 0)
							{
								nc = 1;
								rq = r;
								iq = i;
								goto next2;
							}
							nc++;
							if(nc == 1)
							{
								rq = r;
								iq = i;
							}
						}
					}
next2:				if(nc == 1)
					{
						f++;
						V[rq][c] = v;
						R[rq] -= s;
						C[c] -= s;
						Mat[iq][j] -= s;
#ifdef	CROSS
						if(rq == c)	X1 -= s;
						if(rq == 3 - c)	X2 -= s;
#endif
					}
				}
			}
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					if((Mat[i][j] & s) == 0)	continue;
					nc = 0;
					r = i * 3;
					mm = Mat[i][j];
					for(ii = 0; ii < 3; ii++, r++)
					{
						if((R[r] & s) == 0)	continue;
						c = j * 3;
						mr = mm & R[r];
						for(jj = 0; jj < 3; jj++, c++)
						{
							if(V[r][c] > 0 || (s & C[c]) == 0)	continue;
							if((s ^ (mr & C[c])) == 0)
							{
								nc = 1;
								rq = r;
								cq = c;
								goto next3;
							}
							nc++;
							if(nc == 1)
							{
								rq = r;
								cq = c;
							}
						}
					}
next3:				if(nc == 1)
					{
						f++;
						V[rq][cq] = v;
						R[rq] -= s;
						C[cq] -= s;
						Mat[i][j] -= s;
#ifdef	CROSS
						if(rq == cq)	X1 -= s;
						if(rq == 3 - cq)	X2 -= s;
#endif
					}
				}
			}
		}
		ds += f;
#ifdef	CROSS
	}while(ds < 83 && f > 0);
#else
	}while(ds < 81 && f > 0);
#endif
}

void save(int *rs, int *cs, int *vs)
{
	int c, r;

	dss = ds;
	*rs = *cs = *vs = 0;
	for(r = 0; r < 9; r++)
	{
		AR[r] = R[r];
		AC[r] = C[r];
		for(c = 0; c < 9; c++)	AV[r][c] = V[r][c];
	}
	for(r = 0; r < 3; r++)	for(c = 0; c < 3; c++)	AM[r][c] = Mat[r][c];
#ifdef	CROSS
	AX1 = X1;
	AX2 = X2;
#endif
}

int assume(int *i, int *j, int *rr, int *cc, int rs, int cs, int vs)
{
	int rmc;
	int c, k, r;

	for(r = rs; r < 9; r++)
	{
		for(c = cs; c < 9; c++)
		{
			if(V[r][c] > 0)	cs = vs = 0;
			else
			{
				*i = r / 3;
				*j = c / 3;
				rmc = (R[r] & C[c]) & Mat[*i][*j];
				for(k = vs + 1; k <= 9; k++)
				{
					if((D[k] & rmc) > 0)
					{
						*rr = r + 1;
						*cc = c + 1;
						return k;
					}
				}
				return 0;
			}
		}
	}
	return 0;
}

void nestup(int *rk, int i, int j, int rr, int cc, int v, int *cs, int *vs)
{
	int s;
	int *wc, *wr, *wv;
	int k, n;

	(*rk)++;
	if(*rk >= nstack)
	{
		n = nstack + 20;
		wr = (int *)malloc(n * sizeof(int *));
		wc = (int *)malloc(n * sizeof(int *));
		wv = (int *)malloc(n * sizeof(int *));
		if(wr == NULL || wc == NULL || wv == NULL)
		{
			fprintf(stderr, "Error : memory allocation error.\n");
			exit(-1);
		}
		for(k = 0; k < nstack; k++)
		{
			wr[k] = RS[k];
			wc[k] = CS[k];
			wv[k] = VS[k];
		}
		free((char *)RS);
		free((char *)CS);
		free((char *)VS);
		RS = wr;
		CS = wc;
		VS = wv;
		nstack = n;
	}
	RS[*rk] = rr;
	CS[*rk] = cc;
	VS[*rk] = v;
	ds++;
	V[rr-1][cc-1] = v;
	s = D[v];
	R[rr-1] -= s;
	C[cc-1] -= s;
	Mat[i][j] -= s;
	(*cs)++;
	*vs = 0;
}

void nestdown(int *rk, int *rs, int *cs, int *vs)
{
	*rs = RS[*rk] - 1;
	*cs = CS[*rk] - 1;
	*vs = VS[*rk];
	(*rk)--;
}

void load(int rk)
{
	int s;
	int c, k, r, v;

	ds = dss;
	for(r = 0; r < 9; r++)
	{
		R[r] = AR[r];
		C[r] = AC[r];
		for(c = 0; c < 9; c++)	V[r][c] = AV[r][c];
	}
	for(r = 0; r < 3; r++)	for(c = 0; c < 3; c++)	Mat[r][c] = AM[r][c];
	for(k = 0; k <= rk; k++)
	{
		r = RS[k]-1;
		c = CS[k]-1;
		v = VS[k];
		ds++;
		V[r][c] = v;
		s = D[v];
		R[r] -= s;
		C[c] -= s;
		Mat[r / 3][c / 3] -= s;
	}
#ifdef	CROSS
	X1 = AX1;
	X2 = AX2;
#endif
	determine();
}

int main(void)
{
	int jj;
	int mn = 1, ans = 1, point = 0;
	int i, j, rk, rr, cc, v;
	int rs, cs, vs;

	RS = (int *)malloc(nstack * sizeof(int));
	CS = (int *)malloc(nstack * sizeof(int));
	VS = (int *)malloc(nstack * sizeof(int));
	if(RS == NULL || CS == NULL || VS == NULL)
	{
		fprintf(stderr, "Error : memory allocation error.\n");
		exit(-1);
	}

	jj = 1;
	for(i = 1; i <= 9; i++)
	{
		D[i] = jj;
		jj *= 2;
	}

	while(datain(mn, point++))
	{
		ans = 1;
		determine();
#ifdef	CROSS
		if(ds >= 83)	printans(mn, &ans);
#else
		if(ds >= 81)	printans(mn, &ans);
#endif
		else
		{
			save(&rs, &cs, &vs);
			rk = -1;
			while(1)
			{
				while(1)
				{
					v = assume(&i, &j, &rr, &cc, rs, cs, vs);
					if(v == 0)	break;
					nestup(&rk, i, j, rr, cc, v, &cs, &vs);
					determine();
#ifdef	CROSS
					if(ds >= 83)
#else
					if(ds >= 81)
#endif
					{
						printans(mn, &ans);
						break;
					}
				}
				if(rk == -1)	break;
				nestdown(&rk, &rs, &cs, &vs);
				load(rk);
			}
		}
		mn++;
	}
	return 1;
}
