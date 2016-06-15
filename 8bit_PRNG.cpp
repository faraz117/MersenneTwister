#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include <windows.h>
#include <time.h>

using namespace std;

ofstream MyFile;

uint8_t rnd(void) {
static uint8_t s=0xaa,a=0;

        s^=s<<3;
        s^=s>>5;
        s^=a++>>2;
        return s;
}

int main (void)
{
	MyFile.open("randomNumbers.txt");
	for (int j=0 ; j < 1000 ; j ++){
		uint8_t numberNow= rnd();
		printf("%d\n",numberNow);
		MyFile<<numberNow<<endl;
	}
return 0;
}