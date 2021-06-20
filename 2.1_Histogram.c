// 

#include<stdio.h>
#include<stdlib.h>

int count(int n, int r, float *data);        //count関数のプロトタイプ宣言

int main(){
  int i,n,r;
  float *data;
  float max, min;

  printf("I'll output the Histogram.   Input the number of data.\n");
  scanf("%d",&n);                            
  data=(float *)malloc(sizeof(float) * n);   //メモリ領域の動的確保
  
  printf("Then, input the data>0.   Every data should be positive real number.\n");
  for(i=0; i<n; i++){                        
    scanf("%f",&data[i]);                    //n個のデータの読み込み
  }

  max = data[0];                             //入力データ内の max, min を抽出,　ヒストグラムの表示に利用
  min = data[0];
  for(i=1; i<n; i++){
    if(max<=data[i]){
      max = data[i];
    }
    if(min>=data[i]){
      min = data[i];
    }
  }


  for(r=0; r<=max; r++){                      //階数 : 0 ~ max までヒストグラムを表示
    printf("%2d ",r);                      
    for(i=0; i<count(n,r,data); i++){        //count関数の呼出
      printf("*");
    } 
  printf("\n");
  }
  free(data);                                //不要になったメモリの解放
  return 0;
}


int count(int n, int r, float *data){        //count関数の定義
  int i,c=0;

  for(i=0; i<n; i++){                        //各データの四捨五入
      if(data[i]-(int)data[i]>=0.5){         //少数第一位を抽出、5以上の場合
      data[i]=(int)data[i]+1.0;              //切り上げ
    }
    else{                                   
      data[i]=(int)data[i];
    }
  }
  for(i=0; i<n; i++){                       //データ数だけ以下の処理を繰り返し
    if(r==data[i]){                         //階級rに含まれる場合、cに1を足す
      c++;
    }
  }
  return c;                                 //count関数の戻り値(関数にヒストグラムの度数を返す)
}