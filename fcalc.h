/*ヘッダファイル*/

#define BUFSIZE      256            /*入力バッファ用配列の長さ*/
#define MAXDATASIZE  32767          /*データ格納用配列の大きさ*/
#define DATAFILENAME "datafile.dat" /*データ格納用ファイルの名前*/

/*関数のプロトタイプ宣言*/
int    getint(void);                      /*メニュー番号をひとつだけ読み込む*/
void   showmenu(void);                    /*メニューの表示*/
int    datainput(double data[], int no);  /*1 データの新規入力・追加*/
void   display(double data[], int no);    /*2 データの出力*/
void   correct(double data[], int no);    /*3 データの修正*/
void   calc(double data[], int no);       /*4 平均・分散・標準偏差の計算*/
void   search(double data[], int no);     /*5 検索*/
void   sort(double data[], int no);       /*6 整列*/
int    getdouble(double *x);              /*実数の読み込み*/
void   partdisplay(double data[], int from,int till); /*display()関数の下請け関数*/
double average(double data[], int no);    /*calc()関数の下請け関数*/
double variance(double data[], int no, double ave);    /*calc()関数の下請け関数*/
void   dqsort(double data[], int lower, int upper);    /*クイックソート(実数用)*/
void   dswappdata(double *i, double *j);               /*データの入れ替え*/


void fileout(double data[], int no); /*7 ファイルの書き込み*/
int filein(double data[], int no);   /*8 ファイル読み出し*/
int fgetdouble(FILE *fp, double *x); /*ファイルからの実数の読み込み*/
