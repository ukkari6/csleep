#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



void no_operand_message();
void help_message();
void error_message();


int main(int argc, char *argv[]){
  int time;

  //引数なし
  if (argc == 1){
    no_operand_message();
    return 1;

  } else if(argc == 2){
    //ヘルプ表示
    if (strcmp(argv[1], "--help") == 0) {
      help_message();
      return 1;
    }

    //引数が数字+smhかどうか
    char *input = argv[1];
    char unit = input[strlen(input) - 1]; //smh
    int value = atoi(input); // 数字部分を整数に変換


    if(value == 0 && input[0] != '0'){
      error_message();
      return 0;
    }

    switch (unit){
      case 's':
        time = value;
        break;
      case 'm':
        time = value * 60;
        break;
      case 'h':
        time = value * 3600;
        break;
    }


  }else{
    error_message();
    return 0;

  }

  int time_count = 0;
  while(1){
    sleep(1);
    if(time_count >= time){
      printf("プログラムを終了します。\n");
      break;
    }else{
      time_count += 1;
      printf("\033[H\033[J");  // カーソルを画面の先頭に移動して、画面を消去する
      printf("設定時間:%d秒\n", time);
      printf("残り %d秒\n", time - time_count);
    }
  } 
  return 0;
}

//オペランドの指定が無い
void no_operand_message(){
  printf("csleep: オペランドがありません\n");
  printf("詳しくは 'csleep --help' を実行してください。\n");
}

//ヘルプ表示
void help_message(){
  printf("使用方法：csleep NUMBER[SUFFIX]\n");
  printf("もしくは：csleep OPTION\n");
  printf("NUMBER 秒間停止します。\n");
  printf("SUFFIXには、\n");
  printf("秒を表す 's' デフォルト\n");
  printf("分を表す 'm' \n");
  printf("時間を表す 'h' \n");
  printf("\n");
  printf("https://github.com/ukkari6/csleep\n");
}

void error_message(){
  printf("csleep: 無効な指定です\n");
  printf("詳しくは 'csleep --help' を実行してください。\n");
}
