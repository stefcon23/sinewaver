#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*
**	sinewaver.c
**
**	plotting sine wave linearly
**		mostly as a terminal screensaver
**
**	Conor Stefanini, 28 January 2015
**
**	Changes
**
**		2015-05-25
**			cleaned up a little bit
**			got everything ready for github
**		Conor Stefanini, 25 May 2015
*/

#define PI 3.14159265259

int delay(int milliseconds)
{

	/*
	**	delay function
	**
	**	delays for int milliseconds, uses time.h library
	**	taken from: http://c-for-dummies.com/blog/?p=69
	*/

	long pause;
	clock_t now, then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	if ((now = then = clock()) == -1) {
		return 1;
	}
	while ((now - then) < pause) {
		if ((now = clock()) == -1) {
			return EXIT_FAILURE;
		}
	}
	
	return 0;
}

int help()
{
	//	help file
	printf(" sinewave\n");
	printf(
		"  Prints a sinewave linearly\n"
		"  USAGE:\n"
		"   sinewave [OPTIONS]\n"
		"  Where [OPTIONS] include:\n"
		"   -w\twidth of terminal (default 80)\n"
		"   -a\tangle (in degrees) to start wave from (default 0)\n"
		"   -s\tstep, amount to increase angle by each step (default 5)\n"
		"   -t\ttime delay in milliseconds (default 30)\n"
		"   -c\tcharacter to represent sine wave (default '|')\n"
		"   -i\tcharacter to represent the inside of the wave (default '-')\n"
		"   -o\tcharacter to represent the outside of the wave (default ' ')\n"
		"   -h\tdisplay this help message\n"
		"  Examples:\n"
		"   sinewave\n"
		"   sinewave -w 50 -a 90\n"
		"   sinewave -s 1 -t 10 -c '#'\n"
		"   sinewave -c 'o' -i 'm' -o ' '\n"
		"  Use keyboard interrupts to quit:\n"
		"   Ctrl-C\n"
		"  Conor Stefanini, 7 February 2015\n"
	);
	return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
	float angle;	//	angle to calculate sine wave from
	int i;
	int wave;		//	value of sin multiplied by value for screen width
	float step;		//	amount to increase angle by at each step
	int w;			//	screen width
	int hW; 		//	half screen width
	int time;		//	time delay
	char wa,
		in, 
		sp;			//	output chars

	//	default options
	angle = 0;
	step = 5;
	time = 30;
	w = 80;				//	default terminal size
	wa = '|';			//	wave character
	in = '-';			//	inner wave character
	sp = ' ';			//	space outside wave character
	
	//	ERROR CHECK THE FOLLOWING
	if (argc > 1) {
		for (i = 1; i < argc; ++i) {
			if (argv[i][0] == '-') {
				switch (argv[i][1]) {
					case 'w':
						w = atoi(argv[i + 1]);
						break;
					case 'a':
						angle = atoi(argv[i + 1]);
						break;
					case 's':
						step = atoi(argv[i + 1]);
						break;
					case 't':
						time = atoi(argv[i + 1]);
						break;
					case 'c':
						wa = argv[i + 1][0];
						break;
					case 'i':
						in = argv[i + 1][0];
						break;
					case 'o':
						sp = argv[i + 1][0];
						break;
					default:
						help();
						return 0;
				}
			}
		}
	}


	hW = (w - 2) / 2;	//	2 chars for buffer (so wave doesn't touch sides)
	while (1) {
	
		//	TO DO
		//		add a reliable method of exit
		
		//	calculate sin of angle and scale it to half the screen
		wave = (int)(sin(angle * (PI / 180)) * hW);	//ERROR CHECK
		//	buffer character
		//		so the wave doesn't touch the size
		printf(" ");

		//	loop to fill the screen
		for (i = 0; i <= (w - 2); ++i) {
			
			if (i == hW + wave) {
				printf("%c", wa);
			} else if (i <= hW) {
				if (i > hW + wave) {
					printf("%c", in);
				} else {
					printf("%c", sp);
				}
			} else {
				if (i < hW + wave) {
					printf("%c", in);
				} else {
					if (sp == ' ') {
						continue;
					} else {
						printf("%c", sp);
					}
				}
			}

		}

		printf("\n");

		//	increment or reset angle
		if (angle >= 360) {
			angle = 0;
		} else {
			angle += step;
		}

		//	delay between screen refresh / character printing
		if (delay(time)) {
			fprintf(stderr, "The clock isn't working\n");
			return EXIT_FAILURE;
		}

	}
	
	return EXIT_SUCCESS;
}
