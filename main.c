#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"//�Լ� ȣ�� ����
#define MAX_DIE          6

 
void opening(void)
{
     printf("==============\n");
     printf("|            |\n");
     printf("| Shark game |\n");
     printf("|            |\n");
     printf("==============\n");
}     
     
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}


int main(int argc, char *argv[])
{
  int pos = 0;
  srand((unsigned)time(NULL));
  //0. opening 
  opening();
  
  //1. �ʱ�ȭ & �÷��̾� �̸� ����
  board_initBoard();
  
  //2. �ݺ���(�÷��̾� ��)
  do {
      int step = rolldie();
      int coinResult;
      char c;
      
      board_printBoardStatus();
      
      pos += step;
      printf("press any key to continue: ");
      scanf("%d",&c);
      coinResult = board_getBoardCoin(pos);
      }
      
      
       //2-1. �÷��̾� ���� ���
       //2-2. �ֻ��� ������
       //2-3. �̵�
       //2-4. ���� �ݱ�
       //2-5. ����������...
       //2-6. ��� ����(if (��� �÷��̾ ����~~~))
       
        
  //3. ����(���� ���, ��� ��...) 
  
  system("PAUSE");	
  return 0;
}
