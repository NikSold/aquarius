#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main.h"

const char *f_name_dic = "dictionary.csv";

const char kb_array[ROW_COUNT][COL_COUNT] =
{ {"QWERTYUIOP"},
  {"ASDFGHJKL*"},
  {"*ZXCVBNM**"}
};

char chars_array[CHAR_ARRAY_SIZE] = {0,};

//====================================================================
//====================================================================
void UpCase(char *line)
{
  char *s = line;
  char  count = LINE_LENGTH;

  if (line == NULL)
    return;
  while (*s)
  {
    *s = toupper((unsigned char) *s);
    s++;
    if (--count == 0)
      break;
  }
}
//====================================================================
BOOL CreateArrayKBchar(char symbol)
{
  ButCoord pos_centr = {-1, -1};
  ButCoord pos_left  = {-1, -1};
  ButCoord pos_right = {-1, -1};
  ButCoord pos_down  = {-1, -1};
  ButCoord pos_up    = {-1, -1};
  char *pos_char;
  char *row;
  char ind = 0;

  for (int i=0; i<COL_COUNT; i++)
  {
    row = (char *)&kb_array[i][0];
    if ((pos_char = strchr(row, symbol)) == NULL)
      continue;
    pos_centr.col = pos_char - row;
    pos_centr.row = i;
  } //for (int i=.; i<COL_COUNT; i++)
  if (pos_centr.col == -1)
    return FALSE;
  pos_left.col  = pos_centr.col - 1;  pos_left.row  = pos_centr.row;
  pos_right.col = pos_centr.col + 1;  pos_right.row = pos_centr.row;
  pos_down.col  = pos_centr.col;      pos_down.row  = pos_centr.row + 1;
  pos_up.col    = pos_centr.col;      pos_up.row    = pos_centr.row - 1;
  bzero(chars_array, CHAR_ARRAY_SIZE);
  chars_array[ind++] = kb_array[pos_centr.row][pos_centr.col];
  if (pos_left.col != -1 && pos_left.row != -1)
    chars_array[ind++] = kb_array[pos_left.row][pos_left.col];
  if (pos_right.col != -1 && pos_right.row != -1)
    chars_array[ind++] = kb_array[pos_right.row][pos_right.col];
  if (pos_down.col != -1 && pos_down.row != -1)
    chars_array[ind++] = kb_array[pos_down.row][pos_down.col];
  if (pos_up.col != -1 && pos_up.row != -1)
    chars_array[ind++] = kb_array[pos_up.row][pos_up.col];
  return TRUE;
}
//====================================================================
BOOL CheckWord(char *line)
{
  int len;
  int count;
  char *pos;

  if (line == NULL)
    return FALSE;
  len = strlen(line);
  for (int i=0; i<len; i++)
  {
    count = 0;
    if (!CreateArrayKBchar(line[i]))
      return FALSE;
    for (int j=0; j<len; j++)
    {
      pos = strchr(chars_array, line[j]);
      if (pos == NULL)
        break;
      count++;
    } //for (int j=0; j<len; j++)
    if (count == len)
      return TRUE;
  } //for (i=0; i<strlen(line); i++)
  return FALSE;
}
//====================================================================
int main( int argc, char **argv )
{
  FILE *f_dic;
  char line[LINE_LENGTH] = {0,};
  char *line_up;
  char *pos_cr = NULL;
  char *f_name = (char *)f_name_dic;
  int  count_words = 0;
  int  count_lines = 0;

  if (argc == 2)
    f_name = argv[1];
  if ((f_dic = fopen(f_name, "r")) == NULL)
  {
    printf("Can't open file \"%s\"\n", f_name);
    return -1;
  } //if ((f_dic = fopen(f_name_in, "r")) == NULL)
  printf("\n-----------------------------------------------------------\n");
  printf("  Start process: work with dictionary \"%s\".\n", f_name);
  printf("-----------------------------------------------------------\n\n");
  while(fgets(line, LINE_LENGTH-1, f_dic))
  {
    if ((pos_cr = strchr(line, CHAR_CR)) != NULL)
      *pos_cr = CHAR_NULL;
    if (strlen(line))
    {
      count_lines++;
      UpCase(line);  //printf("\nread up: %s\n", line);
      if (CheckWord(line))
      {
        count_words++;
        printf("%04d. Word found for adjacent keys: '%s' ==> '%s'\n", count_words, line, chars_array);
      } //if (CheckWord(line))
    } //if (strlen(line))
    bzero(line, LINE_LENGTH);
  } //while(fgets(line, LINE_LENGTH-1, f_dic))
  printf("\n----------------------------------------------------\n");
  printf("  Result: %d lines processed, %d words found.\n", count_lines, count_words);
  printf("----------------------------------------------------\n\n");
  fclose(f_dic);
  f_dic = NULL;
  return 0;
}
