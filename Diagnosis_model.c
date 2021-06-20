//マージソート, structを用いた心臓病罹患有無の診断
//教師用データとして n人×d要素の過去診断データを入力, 1×dの新規診断データも入力
//　入力データは全て{0, 1}    1~d-1列が特徴量, d列が診断結果 {0=健康, 1=心臓病}
//ユークリッド距離を基に新規データの診断を行う
//  閾値は勝手に設定

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct data{                               //構造体の宣言
    double distance;                       //Euclid距離、診断結果をメンバとする
    int diag;                              /* ⇒マージソート時2つが連動して動ける */
};
typedef struct data row;                   //新たなデータ名 row



int knn_diag(int , int , int *, double *, double **);  //各関数の宣言
double e_distance(int , double *, double *);
int merge(row *e, int , int , int);
int merge_sort(row *e, int , int );



int main(){                                // main関数 - データの読込,結果の表示 //
    int n,d,*diag,i,j;
    double **data,*patient;
    printf("Input the number of ex-patients and feature value.\n");
    scanf("%d %d",&n,&d);                  //過去データの個数、特徴空間の次元数

    diag = (int *)malloc(sizeof(int) *n);

    data = (double **)malloc(sizeof(double) *n);
    for(i=0;i<n; i++){
        data[i] = (double *)malloc(sizeof(double) *d);
    }

    printf("Input the ex-diagnosis for n lines.  All number should be {0,1}\n");
    for(i=0; i<n; i++){                     //過去診断データ n×d 次元配列の入力
        for(j=0; j<d; j++){
            scanf("%lf",&data[i][j]);
        }
        scanf("%d",&diag[i]);               //各行の末列で過去の診断結果を入力
    }

    printf("Input the new diagnosis for n lines.  All number should be {0,1}\n");
    patient = (double *)malloc(sizeof(double) *d);
    for(i=0; i<d; i++){                     //診断対象のデータを入力.  d-1列
        scanf("%lf",&patient[i]);
    }

    if(knn_diag(n, d, diag, patient, data)==0){
        printf("You are healthy!\n");      //knn_diag関数の呼出,結果の出力
    }
    else{
        printf("You have a heart disease!\n");
    }

    free(diag);                            //各配列の不要になったメモリを解放
    free(data);
    for(i=0; i<n; i++){
        free(data[i]);
    }
    free(patient);
    return 0;
}



int knn_diag(int n, int d, int *diag, double *patient, double **data){
                                 //knn_diag関数 - 3近傍のデータ,心臓病診断の結果を出力//
    int i,flag=0;                         
    row *e;                                //struct data型配列e - 距離,診断結果を格納

    e = (row *)malloc(sizeof(row) *n);  
    for(i=0; i<n; i++){                    //配列eに, 各過去データと新規データの特徴量距離の合計, 過去の診断結果を格納
        e[i].distance = e_distance(d, patient, data[i]);
        e[i].diag = diag[i];
    }
    merge_sort(e, 0, n-1);                 //mergesort関数の呼出, 綺麗に表示させる

    for(i=0; i<n; i++){
        printf("%lf %d\n",e[i].distance, e[i].diag);
        if(e[i].distance<=1.4 & e[i].diag==1){                  //近傍データの診断結果が 1の回数を数え,
            flag++;                                             //2回以上検出された場合関数に1を返す
        }
    }
    free(e);
    if(flag>1){
        return 1;
    }
    else{
        return 0;
    }
}



double e_distance(int d, double *patient, double *data){
    double sum=0;                           //e_distance関数 - 特徴量どうしのEuclid距離の算出//
    int i;

    for(i=0; i<d; i++){
        sum += (patient[i]-data[i])*(patient[i]-data[i]);
    }                                       //(診断データと過去の各データの差)^2
    return (double)sqrt(sum);              
                                            //総和の平方根(ある行についてのEuclid距離)を関数に返す
}



int merge(row *e, int p, int q, int r){     //merge関数の定義
                                           
    row *t;
    t = (row *)malloc(sizeof(row)*(r-p+1));

    int count = 0;                         //比較回数count、初期値0
    int x=p, y=q+1, i=0;                   //マージ時比較する配列の位置を表す変数
    
    while(x<=q&&y<=r){                     /* 配列t[p~q]と配列t[q+1~r]の比較 */
      if(e[x].distance > e[y].distance){   //比較、小さいほうをt[i]に代入
        t[i]=e[y];
        i++;                               //i,yの値を増やし、次の比較へ
        y++;
      }
      else{
        t[i]=e[x];                         //同上
        i++;                        
        x++;
      }
      count++;
    }
    while(x<=q){                           /* 比較後、配列t[p~q]の要素が残った場合 */
      t[i]=e[x];
      i++;
      x++;
    }
    while(y<=r){                           /* 比較後、配列t[q+1~r]の要素が残った場合 */
      t[i]=e[y];
      i++;
      y++;
    }
    for(i=0; i<r-p+1; i++){                //マージソートの結果を元の配列に返す
        e[i+p]=t[i];
    }
    free(t);                               //メモリの解放
    return count;                          //比較回数を関数に返す
}

int merge_sort(row *e, int a, int b){      //mergesort関数の定義//
    int count=0,mid;                       //ソート回数count
  
    if(a>=b){                              //配列要素が一つの時
        return count;
    }
    mid=(a+b)/2;                           //配列の中央
    count+=merge_sort(e,a,mid);        //再帰呼び出し-左の部分配列を小さくし、比較回数を足す 
    count+=merge_sort(e,mid+1,b);      //再帰呼び出し-右の部分配列を小さくし、比較回数を足す
    count+=merge(e,a,mid,b);           //merge関数の呼出,マージ後の比較回数をソート回数に足す

    return count;                          //比較回数を関数に返す
}
