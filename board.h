#define BOARDSTATUS_OK       1
#define BOARDSTATUS_NOK      0//�� ��׸� �ű� ���� 


int board_initBoard(void);
int board_printBoardStatus(void);

int board_getBoardCoin(int pos);//��ġ��...??
int board_getBoardStatus(int pos);

int board_getSharkPosition(void);
int board_stepShark(void);//�Է��� �ʿ� �����ϱ� void�� ���̾߿�

 

