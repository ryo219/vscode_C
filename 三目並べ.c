#include<stdio.h>                                   //ヘッダーファイル stdio.h の読み込み
int main(void){                                     //main関数の宣言
  int input,count=1;                                //int型変数 input, count の宣言
  char s[9] = {'1','2','3','4','5','6','7','8','9'};
                                                    //char型変数 s[9] の宣言(盤面の表示)

    printf("\nInput number\n");


  while(count<=8){                                  //処理回数が8回以下の間、以下の処理を繰り返し
    printf("%c|%c|%c\n-+-+-\n%c|%c|%c\n-+-+-\n%c|%c|%c\n",s[6],s[7],s[8],s[3],s[4],s[5],s[0],s[1],s[2]);
                                                    /* o のターン ｰ 盤面を表示 */
    printf("\no> ");                                      
    scanf("%d",&input);                             //番号を入力させる
    printf("\n");                                       
      while(input>9 || input<1 || s[input-1]=='o' || s[input-1]=='x'){
        printf("ERROR\n");                          //入力された数字が盤面にない,又は入力の数字に対応するマスが埋まっている間        
        printf("\no> ");                                //ERROR と表示、再度入力させる
        scanf("%d\n",&input);
        printf("\n");
      }
    s[input-1]='o';                                 //入力の数字に対応するマスを o にする。

    printf("%c|%c|%c\n-+-+-\n%c|%c|%c\n-+-+-\n%c|%c|%c\n",s[6],s[7],s[8],s[3],s[4],s[5],s[0],s[1],s[2]);
    if((s[0]=='o'&&s[1]=='o'&&s[2]=='o') || (s[3]=='o'&&s[4]=='o'&&s[5]=='o') || (s[6]=='o'&&s[7]=='o'&&s[8]=='o') || (s[0]=='o'&&s[3]=='o'&&s[6]=='o') || (s[1]=='o'&&s[4]=='o'&&s[7]=='o') || (s[2]=='o'&&s[5]=='o'&&s[8]=='o') || (s[0]=='o'&&s[4]=='o'&&s[8]=='o') || (s[2]=='o'&&s[4]=='o'&&s[6]=='o')){                           //盤面を表示、縦横斜めいずれかのラインが o で揃った場合      
      printf("\no win!\n");                           // o が勝利、左記を出力。
      return 0;                                     //処理終了
    }                                               
    
    count+=1;                                       //処理回数を＋1
        
    printf("\nx> ");                                  /* x のターン - 以下, o のターンと同様*/
    scanf("%d",&input);                              
    printf("\n");                                      
      while(input>9 || input<1 || s[input-1]=='o' || s[input-1]=='x'){
        printf("ERROR\n");                              
        printf("\nx> ");
        scanf("%d\n",&input);
        printf("\n");
      }
    s[input-1]='x';                                    
    if((s[0]=='x'&&s[1]=='x'&&s[2]=='x') || (s[3]=='x'&&s[4]=='x'&&s[5]=='x') || (s[6]=='x'&&s[7]=='x'&&s[8]=='x') || (s[0]=='x'&&s[3]=='x'&&s[6]=='x') || (s[1]=='x'&&s[4]=='x'&&s[7]=='x') || (s[2]=='x'&&s[5]=='x'&&s[8]=='x') || (s[0]=='x'&&s[4]=='x'&&s[8]=='x') || (s[2]=='x'&&s[4]=='x'&&s[6]=='x')){
      printf("%c|%c|%c\n-+-+-\n%c|%c|%c\n-+-+-\n%c|%c|%c\n",s[6],s[7],s[8],s[3],s[4],s[5],s[0],s[1],s[2]);
      printf("\nx win!\n");                               
      return 0;                                         
    }
    count+=1;                                           
  }

  
   printf("%c|%c|%c\n-+-+-\n%c|%c|%c\n-+-+-\n%c|%c|%c\n",s[6],s[7],s[8],s[3],s[4],s[5],s[0],s[1],s[2]);
   printf("\no> ");                                   //9回目の処理-盤面に空きマスが残り一つ
   scanf("%d",&input);                              //盤面を表示,番号を入力させる。
   printf("\n");
     while(input>9 || input<1 || s[input-1]=='o' || s[input-1]=='x'){     
        printf("ERROR\n");                          //入力された数字が盤面にない,又は入力の数字に対応するマスが埋まっている間        
        printf("\no> ");                              //ERROR と表示、再度入力させる。
        scanf("%d\n",&input);
        printf("\n");
      }
   s[input-1]='o';                                 //入力の数字に対応するマスを o にする
   printf("%c|%c|%c\n-+-+-\n%c|%c|%c\n-+-+-\n%c|%c|%c\n",s[6],s[7],s[8],s[3],s[4],s[5],s[0],s[1],s[2]);
      if((s[0]=='o'&&s[1]=='o'&&s[2]=='o') || (s[3]=='o'&&s[4]=='o'&&s[5]=='o') || (s[6]=='o'&&s[7]=='o'&&s[8]=='o') || (s[0]=='o'&&s[3]=='o'&&s[6]=='o') || (s[1]=='o'&&s[4]=='o'&&s[7]=='o') || (s[2]=='o'&&s[5]=='o'&&s[8]=='o') || (s[0]=='o'&&s[4]=='o'&&s[8]=='o') || (s[2]=='o'&&s[4]=='o'&&s[6]=='o')){                            
        printf("\no win!\n");                         //盤面を表示、縦横斜めいずれかのラインが o で揃った場合        
        return 0;                                   // o が勝利、左記を出力。処理終了
      }
     
  printf("\neven.\n");                                //勝者がいない場合、左記を出力。
  return 0;                                         //処理終了
}
