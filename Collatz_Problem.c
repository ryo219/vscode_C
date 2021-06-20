// コラッツ角谷予想の実装　　　偶数⇒2で割る　奇数⇒3倍して+1
// max計算回数は 98 としている
// 1になれば『ok』

#include<stdio.h>
int main(void){
    int x,i=0;
    scanf("%d",&x);
    printf("%d\n",x);
 
    while(x!=1&&i<=200){
        if(x%2==0){
          x=x/2;
        }
        else{
          x=3*x+1;
        }
        printf("%d\n",x);
        i+=1;
    }
    
    if(i<=200){
        printf("OK\n");
        return 0;
    }
    else{
        printf("\n");
        return 0;
    }
}
