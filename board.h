#define BOARDSTATUS_OK       1
#define BOARDSTATUS_NOK      0//왜 얘네만 옮긴 거지 


int board_initBoard(void);
int board_printBoardStatus(void);

int board_getBoardCoin(int pos);//위치로...??
int board_getBoardStatus(int pos);

int board_getSharkPosition(void);
int board_stepShark(void);//입력이 필요 없으니까 void인 것이야요

 

