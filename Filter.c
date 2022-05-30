/*
   This program adds a number to every value read from
   standard input and writes the result to standard output.

   The default value to add to every input number is 0.
   This default value can be overridden by
      1.) a value from a configuration file, or by
      2.) an environment variable, or by
      3.) a command line argument.
*/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
   // Set the default value.
   int numColumns = 3;
   int precision = 13;
   
   // Override the default value with a value from the configuration file.
   FILE * fp;
   if ( (fp = fopen("filter.cfg", "r")) != NULL )
   {
      // get an operand from the configuration file
      fscanf(fp, "%d %d", &precision , &numColumns);
   }
   else 
   {
      printf("could not open cfg\n");
   }


   // Override the default value with an environment variable value.
   char * op;
   if ( (op = getenv( "CS302_PRECISION" )) != NULL )
   {
      // get an operand from the environment
      precision = atoi(op);
   }
   
   
   if ( (op = getenv( "CS302_COLUMNS" )) != NULL )
   {
      // get an operand from the environment
      numColumns = atoi(op);
   }


   // Get a command line argument (if it exists).
   if (argc > 1)
   {  // get an operand from the command line
       numColumns = atoi(argv[1]);
   }
   if (argc > 2)
   {
     precision = atoi(argv[2]);
   }
   // Process the stream of input numbers.
   
   double x;
   int columns = 1;
   while( scanf("%lf", &x ) != EOF )
   {
      if (columns != 1)
      {
        printf("  ");
      }
      printf("%*.*f", precision + 5, precision, x); //%*.*f , a , b
      if (columns == numColumns)
      { 
        columns = 1;
        printf("\n");
      }
      else
      {
         columns++;
      }
   }
      
  
   

   return 0;
}
