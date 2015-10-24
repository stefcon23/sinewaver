# sinewaver

A terminal screensaver that plots a sine wave

 Prints a sinewave linearly
  USAGE:
  sinewave [OPTIONS]
  Where [OPTIONS] include:
   -w   width of terminal (default 80)\n
   -a   angle (in degrees) to start wave from (default 0)
   -s   step, amount to increase angle by each step (default 5)
   -t   time delay in milliseconds (default 30)
   -c   character to represent sine wave (default '|')
   -i   character to represent the inside of the wave (default '-')
   -o   character to represent the outside of the wave (default ' ')
   -h   display this help message
  Examples:
   sinewave
   sinewave -w 50 -a 90
   sinewave -s 1 -t 10 -c '#'
   sinewave -c 'o' -i 'm' -o ' '
  Use keyboard interrupts to quit:
   Ctrl-C
  Conor Stefanini


## Changes
2015-10-24
    removed date from help message
	added a makefile
	updated README.md
Conor Stefanini, 24 October 2015

2015-05-25
    cleaned up a little bit
    got everything ready for github
Conor Stefanini, 25 May 2015
