#include <stdio.h>

#define K 1    /* K をバネ定数を表すとしてそれを 1 と定める */

int main(){
    double t;     /* 時間変数 */
    double x,xa;   /* xは現在のxの値、xaは次のステップの値 */
    double xc;    /* xcはxの中点のステップ t+dt/2 での値 */
    double v,va;  /* vは現在のvの値、vaは前のステップの値 */
    double vc;    /* vcはvの中点のステップ t+dt/2 での値 */
    double dt;    /* 時間の刻み */

    dt=0.05;      /* 時間の刻みを 0.05 にする */

    x=1.0;        /* 初期条件の設定（初期位置） */
    v=0.0;       /* 初期条件の設定（初期速度）*/

    for(t=0.0; t<10; t=t+dt){ /* 0秒から10秒まで dt 刻みで計算 */

        printf("%f %f\n",t,x);

        xc=x+v*dt/2;    /* 中点の座標を求める */
        vc=v-K*x*dt/2;

        xa=x+vc*dt;     /* 中点での微分値を用いて、次のステップを計算 */
        va=v-K*xc*dt;

        x=xa;           /*次のステップの値を現在の値とする*/
        v=va;
    }
    return	0;
}
