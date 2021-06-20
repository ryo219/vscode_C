//選択ソートを用い, 入力数列データを 小 < 大 に並び替え, ソート結果, max値, 及び比較回数を表示


#include<stdio.h>
#include<stdlib.h>                          //malloc で動的メモリ確保するため

void swap(int *, int *);                    //各関数のプロトタイプ宣言
int selectionsort(int *, int );
void print(int , int , int , int *);


int main(){
    int i,n,count;
    int *s;

    printf("Input the number of data  :  ");
    scanf("%d",&n);                         //データ数の入力
    s=(int *)malloc(sizeof(int) *n);        //メモリ領域の動的確保

    printf("Input the data.  Every data should be positive integer.\n");
    for(i=0; i<n; i++){
        scanf("%d",&s[i]); 
    }
    count = selectionsort(s,n);             //selectionsort関数の呼出(比較回数をcountに代入)
    
    for(i=0; i<n-1; i++){                   //選択ソート後の配列を表示
        printf("%d ",s[i]);
    }
    printf("\nSorted data : %d\n",s[n-1]);
    printf("Comparisons : %d times\n",count);                   //比較回数の表示
    free(s);                                //不要になったメモリの解放
    return 0;
}


void swap(int *x, int *y){                  //swap関数-ソート時のデータ入れ替え
    int Nx=*x, Ny=*y;
    *x=Ny;
    *y=Nx;
}

void print(int i, int k, int n, int *s){    //print関数-ソート後のデータの表示
    int l;
    printf("SWAP(%d,%d)\n",i+1,k+1);            //ソートしたデータの位置を表示
    printf("# ");
    for(l=0; l<n-1; l++){
        printf("%d ",s[l]);                 //ソート後の配列を表示
    }
    printf("%d\n",s[n-1]);
}


int selectionsort(int *s,int n){            //selectionsort関数-ソートの実行
    int i,j,k,t=0,c=0,min;
    
    for(i=0; i<n; i++){                     //配列の左端から順に比較
        min=s[i];
        t=0;
        for(j=i+1; j<n; j++){               
            c++;                            //比較回数を数える
            
            if(min>s[j]){                   //左側のデータ > 右側のデータ の場合
                min=s[j];                   //比較元のデータを更新
                k=j;                        //入れ替えるデータの位置を保存
                t=1;                        //swapのフラグ
            }
        }
        if(t==1){                           
            swap(&s[i],&s[k]);              //swap関数,print関数の呼び出し、各処理を実行
            print(i,k,n,s);
        }
    }
    return c;                               //selectionsort関数に比較回数を返す
}