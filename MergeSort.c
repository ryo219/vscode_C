//入力n項数列のマージソートを行うprogram

#include<stdio.h>
#include<stdlib.h>

int merge(int *, int , int ,int );     //merge関数のプロトタイプの宣言
int merge_sort(int *, int , int );

int main(){
    int n,*s,i,count;

    printf("Length of data : ");
    scanf("%d",&n);
    s=(int *)malloc(sizeof(int) *n);   //配列のメモリ領域の動的確保

    printf("Input data : ");
    for(i=0; i<n; i++){
        scanf("%d",&s[i]);
    }

    count = merge_sort(s,0,n-1);            //count関数の呼出(比較回数をcountに代入)

    printf("Sorted : ");
    for(i=0; i<=n-1; i++){  
        printf("%d ",s[i]);             //ソート後の配列を表示
    }
    printf("\nComparison : %d times\n",count);             //ソート時の要素比較回数
    free(s);                            //不要になったメモリの解放
    return 0;
}


int merge(int *array, int p, int q, int r){
                                       //merge関数の定義
    int *t;
    t = (int*)malloc(sizeof(int)*(r-p+1));
                                       //配列のメモリ領域の動的確保

    int count = 0;                     //比較回数count、初期値0
    int a=p, b=q+1, i=0;               //マージ時比較する配列の位置を表す変数
    
    while(a<=q&&b<=r){                 /* 配列t[p~q]と配列t[q+1~r]の比較 */
        if(array[a]>array[b]){           //比較,小さいほうをt[i]に代入
            t[i]=array[b];
            i++;                           //i,bの値を増やし,次の比較へ
            b++;
        }
        else{
            t[i]=array[a];               //同上
            i++;                        
            a++;
        }
        count++;
    }
    while(a<=q){                       /* 比較後,配列t[p~q]の要素が残った場合 */
            t[i]=array[a];
            i++;
            a++;
    }
    while(b<=r){                       /* 比較後,配列t[q1~r]の要素が残った場合 */
            t[i]=array[b];
            i++;
            b++;
    }
    for(i=0; i<r-p+1; i++){            //マージソートの結果を元の配列に返す
            array[i+p]=t[i];
    }
    free(t);                           //不要になったメモリの解放
    return count;                      //比較回数を関数に返す
}


int merge_sort(int *array, int left, int right){
    int count=0,mid;                       //ソート回数count
  
    if(left>=right){                              //配列要素が一つの時
        return count;
      }
    mid=(left+right)/2;                           //配列の中央
    count+=merge_sort(array,left,mid);        //再帰呼び出し-左の部分配列を小さくし、比較回数を足す
    count+=merge_sort(array,mid+1,right);     //再帰呼び出し-右の部分配列を小さくし、比較回数を足す
    count+=merge(array,left,mid,right);           //merge関数の呼出,マージ後の比較回数をソート回数に足す
    return count;                          //比較回数を関数に返す
}
