// 3桁の Kaprekar 数の算出
// 入力3桁整数の桁を入れ替えた max, min の値の差を取り続ける.　　495になれば終了

#include<stdio.h>
int main(void){
    int n,max=0,min=0,mid=0,t,u;
    int s[3];

    scanf("%d",&n);
    while(n!=495){
        s[0]=(n/100)%10;            //入力整数を桁ごとに格納
        s[1]=(n/10)%10;
        s[2]=(n/1)%10;

        if(s[1]>=s[0]){             //各場合分けをもとに入力整数内の max/mid/min 桁を抽出
            max=s[1];
            min=s[0];
            if(s[2]>=s[1]){
                max=s[2];
                mid=s[1];
            }
            else if(s[2]<=s[1]&&s[2]>=s[0]){
                mid=s[2];
            }
            else if(s[2]<=s[1]&&s[2]<=s[0]){
                mid=s[0];
                min=s[2];
            }
        }
        if(s[1]<=s[0]){
            max=s[0];
            min=s[1];
            if(s[2]>=s[0]){
                max=s[2];
                mid=s[0];
            }
            else if(s[2]<=s[0]&&s[2]>=s[1]){
                mid=s[2];
            }
            else if(s[2]<=s[0]&&s[2]<=s[1]){
                mid=s[1];
                min=s[2];
            }
        }


        t = min*100 + mid*10 + max;     //桁入れ替え
        u = max*100 + mid*10 + min;
        n = u-t;
        printf("%3d - %3d = %3d\n",u,t,n);
    }
    return 0;
}
