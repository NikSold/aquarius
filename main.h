#ifndef  _MAIN_H_
#define _MAIN_H_

#define TRUE  1
#define FALSE 0

#define LINE_LENGTH 128
#define COL_COUNT  10
#define ROW_COUNT  3
#define CHAR_ARRAY_SIZE (5+1)

#define  CHAR_CR	 '\n'
#define  CHAR_RET	 '\r'
#define  CHAR_NULL '\0'

typedef	unsigned char	BOOL;

typedef struct tagButCoord
{
  int col;
  int row;
}ButCoord;

#endif //_MAIN_H_
