//二入力文字列を一致させるための操作{置換/削除/挿入}最小回数を求めるprogram

#include<stdio.h>
#include<string.h>
int ld(char *, int ,char *, int);
int min3(int , int , int);

int main(){
  char x[100],y[100];
  int m,n,a=0,b=0,c=0;
  scanf("%s %s",x,y);
  m=strlen(x);
  n=strlen(y);

  printf("Minimum Operation Time : %d\n",ld(x,m,y,n));       /* ld関数呼び出し */
  return 0;
}


int ld(char *x, int m, char *y, int n){       //再帰手続き-各操作回数算出
  int i=m, j=n;
  int p=0,q=0,r=0;
  if(i==0||j==0){                     //iまたはjが0になった場合
    if(i>j){                          //j,iの値を返す(C_0,0の場合は0を返す)
      return i;
    }
    else{
      return j;
    }
  }
  if(x[i-1]==y[j-1]){                  //添字が等しいとき
    p=ld(x,i-1,y,j-1);                 //コピー,
  }
  else{                                //添字が異なるとき
    p=ld(x,i-1,y,j-1)+1;               //置換、
  }
  q=ld(x,i-1,y,j)+1;                   //削除
  r=ld(x,i,y,j-1)+1;                   //挿入
  return min3(p,q,r);                  //min3関数の呼出
}

int min3(int p, int q, int r){         /* 操作回数の最小値を比較 */
  int min;
  min=p;
  if(min>q){
    min=q;
  }
  if(min>r){
    min=r;
  }
  return min;
}

