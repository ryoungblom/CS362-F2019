#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    int rCharNo = (rand() % (256 - 0 + 1));
    char rChar = (char) rCharNo;

    //printf("%c\n", rChar);

    return rChar;
}

char *inputString()
{

  char stringR[6];
  char rdmChar;
  int rCharNoStr;

    int randms[4];

    randms[0] = 101;
    randms[1] = 114;
    randms[2] = 115;
    randms[3] = 116;

    // TODO: rewrite this function

    for (int i = 0; i < 5; i ++) {

      rCharNoStr = (rand() % (122 - 97 + 1)) + 97;
      //int n = rand() % 4;
      //rCharNoStr = randms[n];
      rdmChar = (char) rCharNoStr;

      stringR[i] = rdmChar;
    }

    stringR[5] = '\0';

    char * returnString = stringR;

    return returnString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {

    //clock_t x = clock() - t;

    //double time_taken_test = ((double)x)/CLOCKS_PER_SEC; // in seconds


    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);


    /*if (time_taken_test > 300) {

      s[0] = 'r';
      s[1] = 'e';
      s[2] = 's';
      s[3] = 'e';
      s[4] = 't';
      s[5] = '\0';
    }

    if (c == '[' && state == 0) {
      state = 1;
      printf ("Phase 1\n");
    }
    if (c == '(' && state == 1) {
      state = 2;
      printf ("Phase 2\n");
    }
    if (c == '{' && state == 2) {
      state = 3;
      printf ("Phase 3\n");
    }
    if (c == ' '&& state == 3) {
      state = 4;
      printf ("Phase 4\n");
    }
    if (c == 'a' && state == 4) {
      state = 5;
      printf ("Phase 5\n");
    }
    if (c == 'x' && state == 5) {
      state = 6;
      printf ("Phase 6\n");
    }
    if (c == '}' && state == 6) {
      state = 7;
      printf ("Phase 7\n");
    }
    if (c == ')' && state == 7) {
      state = 8;
      printf ("Phase 8\n");
    }
    if (c == ']' && state == 8) {
      state = 9;
      printf ("Phase 9\n");
    }

    */

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;

    /*printf ("char: %c\n", s[0]);
    printf ("char: %c\n", s[1]);
    printf ("char: %c\n", s[2]);
    printf ("char: %c\n", s[3]);
    printf ("char: %c\n", s[4]);
    printf ("char: %c\n", s[5]);*/

    //printf ("String: %s ", s);

    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
      break;
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    //clock_t t;
    //t = clock();

    testme();

    //t = clock() - t;
    //double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    //printf("testme() took %f seconds to execute \n", time_taken);

    return 0;
}
