
/* Hello, Saana or Mira!
   I decided to include all the required files in this one single file
   to make it easier for you guys to skim through. :p

   I separated all of them into defferent sections...  */

// ---------------------v debug.h v-------------------------

#ifndef DEBUG_H
#define DEBUG_H

//part of Exercise 20!

void set_debug_level(int debug_level);
int dprintf(int debug_level, const char *fmt, ...);

#endif

// ---------------------v debug.c v-------------------------

#include "debug.h"
#include <stdarg.h>
#include <stdio.h>

// part of Exercise 20!

static int current_debug_level = 0;

// from the exercise description:
/* "Set_debug_level takes one integer parameter (debug level) and stores the value in a static variable
that is accessible to all functions in the file but not globally." */
void set_debug_level(int debug_level) {
   current_debug_level = debug_level;
}

/* "Dprintf works like printf but there is an extra integer parameter (debug level) that comes before the
usual printf parameters:" */
int dprintf(int debug_level, const char *fmt, ...) {
   if (debug_level > current_debug_level) {
      return 0;
   }

   fprintf(stderr, "[DBG%d] ", debug_level);

   va_list args;
   va_start(args, fmt);
   int result = vfprintf(stderr, fmt, args);
   va_end(args);

   return result;
}

// ---------------------v main.c v-------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "debug.h"

// part of Exercise 20!     Debug level *COMPLETED*

#define MIN_LEVEL 0
#define MAX_LEVEL 4
#define MESSAGE_COUNT 5

int main(void)
{
   int user_level;

   printf("Please enter a debug level (%d - %d):\n", MIN_LEVEL, MAX_LEVEL);
   while (scanf("%d", &user_level) != 1 || user_level < MIN_LEVEL || user_level > MAX_LEVEL) {
      printf("Invalid input. :( Please enter a number between %d and %d:\n", MIN_LEVEL, MAX_LEVEL);
      // clears the input 'buffer' vvv
      while (getchar() != '\n');
   }

   set_debug_level(user_level);

   srand(time(NULL));

   for (int i = 1; i <= MESSAGE_COUNT; i++) {
      // random number vvv
      int random_level = rand() % (MAX_LEVEL + 1);
      dprintf(random_level, "Message %d with the debug level of: %d\n", i, random_level);
   }

   return 0;
}



