#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"//함수 호출 가능

#define N_BOARD              15

#define MAX_CHARNAME     200
#define MAX_DIE          6

#define N_PLAYER         3

#define PLAYERSTATUS_LIVE    0    
#define PLAYERSTATUS_DIE     1
#define PLAYERSTATUS_END     2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER];//헷갈~ 
//player_status[0] = PLAYERSTATUS_DIE       플레이어 0이 죽었다~는 뜻 
char player_statusString[3][MAX_CHARNAME] = {"LIVE","DIE","END"};

int turn = 0;

void opening(void)
{
     printf("================\n");
     printf("||            ||\n");
     printf("|| Shark game ||\n");
     printf("||            ||\n");
     printf("================\n");
}     
     
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}

void printPlayerPosition(int player)
{
     int i;
     for (i=0;i<N_BOARD;i++)
     {
         printf("|");
         if (i == player_position[player])
            printf("%c", player_name[player][0]); 
         else 
         {
              if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
                  printf("X");
              else
                  printf(" ");
         }
     }
     printf("|");
     printf("\n");
}

void printPlayerStatus(void)
{
     int i;
     printf("-------- player status --------\n");
     for (i=0;i<N_PLAYER;i++)
     {
         printf("%s: pos %i, coin: %i, status: %s\n",
         player_name[i],player_position[i],player_coin[i],player_statusString[player_status[i]]);
     }
     printf("-------------------------------\n");
}

void checkDie(void)
{
     int i;
     for(i=0;i<N_PLAYER;i++)
       if (board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
           player_status[i] = PLAYERSTATUS_DIE;
}

int main(int argc, char *argv[])
{
  int pos = 0;
  int i;
  srand((unsigned)time(NULL));
  //0. opening 
  opening();
  
  //1. 보드 초기화 & 플레이어 이름 결정
  board_initBoard();
  
  //1-2. 플레이어 초기화
  for (i=0;i<N_PLAYER;i++)
  {
      player_position[i] = 0;
      player_coin[i] = 0;
      player_status[i] = PLAYERSTATUS_LIVE;
      //player_name
      printf("Player %i's name: ", i);//몇번째~ 
      scanf("%s", player_name[i]);// & 필요 없음(자체가 포인터여서...) 
  } 
  
  
  //2. 반복문(플레이어 턴)
  do {
      int step;
      int coinResult;
      char c;
      
      
      if (player_status[turn] != PLAYERSTATUS_LIVE)
      {
           turn = (turn + 1)%N_PLAYER;
           continue;
      }
      
      //2-1. 보드, 플레이어 상태 출력
      board_printBoardStatus();
      for (i=0;i<N_PLAYER;i++)
          printPlayerPosition(i);
      printPlayerStatus();
      
      step = rolldie();
      pos += step;
      coinResult = board_getBoardCoin(pos);

      
      
      //2-2. 주사위 던지기
      printf("%s turn! ", player_name[turn]);
      printf("press any key to roll a die: ");
      scanf("%d",&c);
      fflush(stdin);
      step = rolldie();
     
      
      //2-3. 이동
      player_position[turn] += step;
      if (player_position[turn] >= N_BOARD)
      {
         player_position[turn] = N_BOARD-1; 
      }
      if (player_position[turn] == N_BOARD-1)
         player_status[turn] = PLAYERSTATUS_END;
          
      printf("%i번째 칸...\n",player_position[turn]);      
      
      //2-4. 동전 줍기
      coinResult = board_getBoardCoin(pos);
      player_coin[turn] += coinResult; 
      printf("동전 %i개...\n", player_coin[turn]);
       
      //2-5. 다음턴으로...
      turn = (turn + 1)%N_PLAYER;//wrap around
      
      //2-6. 상어 동작(if (모든 플레이어가 돌아~~~))
      if (turn == 0)
      {
         int shark_pos = board_stepShark();
         printf("상어 %i번쨰칸으로 이동\n",shark_pos);
         checkDie();      
      }
      
      
      } while(1);
        
      //3. 정리(승자 계산, 출력 등...) 
  
  system("PAUSE");	
  return 0;
}
