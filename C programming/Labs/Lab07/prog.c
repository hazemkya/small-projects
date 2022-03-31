#include <stdio.h>
#include <stdlib.h>
#include "prog.h"

int main(){
  /* local var declarations */
  FileStats* fsp;
  char** lines;
  fsp = process_file("wcs.txt");

  /* printf the returned stats */
  printf("Total # of chars = %d\n", fsp->total_chars);
  printf("# of letters = %d\n", fsp->letters_count);
  printf("# of words = %d\n", fsp->words_count);
  printf("# of lines = %d\n", fsp->lines_count);
  printf("Length of longest line = %d\n", fsp->max_line_length);
  lines = get_lines("wcs.txt");

  /* write reversed file */
  write_rev("wcs-rev.txt", lines, fsp->lines_count);

  return 0;
}

/* define the functions you can write function stubs
   during development */

/* returns 1 if param is a letter and 0 otherwise */
int is_letter(char c){
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/* takes a filename as a string param and returns a pointer to a FileStats
   structure, or NULL on failure */
FileStats* process_file(char* fn){
  FileStats* result = 0;
  FILE* fp = fopen(fn, "r");
  if (fp){
    result = (FileStats*)calloc(1, sizeof(FileStats));
    char c, prev=0;
    int len = 0;
    do {
      c = getc(fp);
      if (c != EOF) {
        result->total_chars++;
        if (c != '\n') len++;
      }
      if (is_letter(c)) result->letters_count++;
      if (is_letter(prev) && !is_letter(c)) result->words_count++;
      if (c == '\n' || c == EOF){
        result->lines_count++;
        if (len > result->max_line_length) result->max_line_length = len;
        len = 0;
      }
      prev = c;      
    } while (c != EOF);
    fclose(fp);
  }
  return result;
}

/* takes a filename as a string param and returns an array contains all the
   lines of the file, or NULL on failure 
char** get_lines(char* fn){
  char** result = 0;
  FILE* fp = fopen(fn, "r");
  int i;
  if (fp){
    FileStats* fs = process_file(fn);
    result = malloc(fs->lines_count*sizeof(char*));
    for (i=0; i < fs->lines_count; i++){
      result[i] = calloc(fs->max_line_length+1, 1);
      fgets(result[i], fs->max_line_length+1, fp);
    }

    fclose(fp);
  }
  return result;
}

*/

char** get_lines(char* fn){
  char c;
  int i;
  char **lines, *p;
  
  FileStats* fs;
  FILE* fp;

  if (!(fs = process_file(fn))) return NULL;
 
  lines = (char**)calloc(fs->lines_count, sizeof(char*));
  for (i=0; i < fs->lines_count; i++)
    lines[i] = (char*)calloc(fs->max_line_length+1, 1);

  if (!(fp = fopen(fn, "r"))) return NULL;

  i = 0; 
  p = lines[0];
  do {
    c = getc(fp);
    if (c == '\n' || c == EOF)
      p = lines[++i];
    else
      *p++ = c;
  } while (c != EOF);
  return lines;
}

/*

void write_rev(char* fn, char** lines, int count){
  int i,j;
  FILE* fp = fopen(fn, "w");
  if (fp)
  {
    for (i = 0; i < count; i++){
      j=0;
      while(lines[((count-1) - i)][j]!= '\n' && lines[((count-1) - i)][j]!= 0){
        fputc(lines[((count-1) - i)][j], fp);
        j++;
      }
        fputc('\n', fp);
    }

    fclose(fp);
  }
}
*/

void write_rev(char* fn, char** lines, int count){
  int i=0;
  FILE* fp = fopen(fn, "w");
  if (fp)
  {
    
    for (i = 0; i < count; i++)
    { 
      fputs(lines[((count-1) - i)], fp);

      fputc('\n', fp);

    }

    fclose(fp);
  }


}