# Operating-System-FilterFormatter
In this assignment you will write a C filter program that formats a jumbled stream of input numbers into nicely organized columns. To determine the parameters for the output formatting your program will make use of command-line arguments, environment variables, and a configuration file. To test your program you will need to use the Windows command-line.

Write a C program called filter.c that reads from standard input and writes to standard output. The input to your program will be positive decimal numbers, which are less than 10,000, separated by white space. The output of your program will be the input numbers formatted into columns.

The default number of output columns for your output is three and there should always be exactly two spaces between the output columns. If the file filter.cfg exits in the current directory, then the second integer value in that file overrides the default number of output columns. If there is an environment variable called CS302_COLUMNS, then the value of that variable overrides the default number of columns and the number of columns set by the configuration file (if it exits). If there is a command-line parameter, then that command-line parameter overrides both the environment variable (if there is one), the configuration file (if it exits), and the default number of columns.

The decimal points of all the numbers in an output column must line up. You line up the decimal points by calling printf with an appropriate format string. The number of digits after a decimal point is called the precision of a decimal number. All the numbers in the output will have the same precision. The default precision for your output is 13 decimal places. If the file filter.cfg exits in the current directory, then the first integer value in that file overrides the default precision. If there is an environment variable called CS302_PRECISION, then the value of that variable overrides the default precision and the precision set by the configuration file (if it exits). If there is a second command-line parameter, then that command-line parameter overrides both the environment variable (if there is one), the configuration file (if it exits), and the default value of precision.

Your program should use the Standard C library function fopen() to open the configuration file filter.cfg (if it exits). Your program should use the function fscanf() to read the two integer values from the configuration file. To keep things simple, you can assume that if the configuration file exits, then it must contain two positive integer values. The configuration file is a text file, so the "integers" in it are actually strings, but the fscanf() function will automatically convert them to int values for you.

Your program should use the Standard C Library function getenv() to see if there are environment variables named CS302_COLUMNS or CS302_PRECISION. If either one exits, its string value should be converted to an integer value by using the Standard C Library function atoi() ("atoi" is an abbreviation of "ascii to integer").

Your program should get its command-line arguments by using the argc and argv parameters to your program's main() function (see also Chapter 9 from this book). Command-line arguments, like environment variables, are always strings. So you need to use atoi() to convert a command-line argument into an int value.

Your program should read in values from standard input by using the Standard C Library function scanf() and its associated formatting strings.

Your program should write formatted output numbers (with the decimal points lined up and the proper number of decimal digits) to standard output by using the Standard C Library function printf() and its associated formatting strings. (Hint: You will need to make use of the * character in your format strings.)

Formatted input and output is not as hard as it might seem by looking at the last few references. After a few examples, you quickly get the hang of it. (Here is a nice printf summary for the Java version of printf.)

Here are a couple of examples. If the input stream to your program looks like this:

5163.1575670644243                 6806.8180791650138
                 8977.2739646595655
      2598.0792870876185                 7162.5237586596268          6691.2041993469038
 1043.6422009949033
    6922.8216193121125          3.0480056154058  9926.6081118198181  100.3082369457076
5135.1567125461588      7808.2382885219886     1439.6542863246559        249.6179692983795
  214.0065309610279                 9280.5883968626968             2687.3871883297220
7612.8426770836513         6644.2027649769589  8364.5604419080173      4740.7550279244360
254.6181218909269         2500.3814813684498
      2293.6803491317482                  835.3306680501725
        5962.7923215430155    9622.5988341929387    57.3069246498001
        1557.9630726035341                8398.5614795373385         5958.4870143742182
   2568.3835566270945             9935.9135715811644              3410.1040681173131
982.0299691763055
  8393.5613269447913           9066.2766808069100                 4896.4546037171549
     7597.8422193060087            8551.5661488692895   1076.6432081057162
 1911.3635059663686         7586.8418836024048       9282.8936429944770 4696.1433149204995
 1388.0423596911528
                 1936.3642689291055     3408.4091921750542              3556.4137089144565
     9241.8923917355878          5003.4578691976685               3366.7130954924160
  4270.1303140354621   620.6292916653950    4700.7538071840572         1766.0538956877347
              441.6238288521989            8153.8591875972779
then the default way to format this is with three columns and 13 digits of precision (notice that there are exactly two spaces between the columns).

5163.1575670644243  6806.8180791650138  8977.2739646595655
2598.0792870876185  7162.5237586596268  6691.2041993469038
1043.6422009949033  6922.8216193121125     3.0480056154058
9926.6081118198181   100.3082369457076  5135.1567125461588
7808.2382885219886  1439.6542863246559   249.6179692983795
 214.0065309610279  9280.5883968626968  2687.3871883297220
7612.8426770836513  6644.2027649769589  8364.5604419080173
4740.7550279244360   254.6181218909269  2500.3814813684498
2293.6803491317482   835.3306680501725  5962.7923215430155
9622.5988341929387    57.3069246498001  1557.9630726035341
8398.5614795373385  5958.4870143742182  2568.3835566270945
9935.9135715811644  3410.1040681173131   982.0299691763055
8393.5613269447913  9066.2766808069100  4896.4546037171549
7597.8422193060087  8551.5661488692895  1076.6432081057162
1911.3635059663686  7586.8418836024048  9282.8936429944770
4696.1433149204995  1388.0423596911528  1936.3642689291055
3408.4091921750542  3556.4137089144565  9241.8923917355878
5003.4578691976685  3366.7130954924160  4270.1303140354621
 620.6292916653950  4700.7538071840572  1766.0538956877347
 441.6238288521989  8153.8591875972779
On the other hand, if we use seven columns and only two digits of precision, the same input should produce the following output.

5163.16  6806.82  8977.27  2598.08  7162.52  6691.20  1043.64
6922.82     3.05  9926.61   100.31  5135.16  7808.24  1439.65
 249.62   214.01  9280.59  2687.39  7612.84  6644.20  8364.56
4740.76   254.62  2500.38  2293.68   835.33  5962.79  9622.60
  57.31  1557.96  8398.56  5958.49  2568.38  9935.91  3410.10
 982.03  8393.56  9066.28  4896.45  7597.84  8551.57  1076.64
1911.36  7586.84  9282.89  4696.14  1388.04  1936.36  3408.41
3556.41  9241.89  5003.46  3366.71  4270.13   620.63  4700.75
1766.05   441.62  8153.86
