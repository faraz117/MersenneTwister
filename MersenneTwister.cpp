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
///////////////To Write to the CSV file///////////////////
ofstream MyFile;
/////////////////////////////////////////////////////////


uint16_t index=624;
uint32_t mt[624];
uint32_t y = 0;
// What can be the range of the seed 
uint32_t _int32(uint32_t x){

	return int(0xFFFFFFFF & x);
}

void init_MT_RNG(uint32_t seed){
mt[0]=seed; // Probably form the ADC 
for (int i = 1 ; i < 625 ; i ++ ){
	mt[i]= _int32(1812433253 * (mt[i-1] ^ mt[i -1] >> 30) + i);
}
} 

void twist_now(){
	for(int i = 0 ; i < 625 ; i ++){
		y= _int32((mt[i] & 0x80000000) + ( mt[i +1 % 624 ] & 0x7FFFFFFFF));

		mt[i]= mt[(i+ 397) % 624] ^ y >> 1;

		if ( y % 2 != 0){
			mt[i]=mt[i] ^ 0x9908b0df;
		}

	}
	index=0;	
}

uint32_t generate_number(){
	if (index >= 624){
		twist_now();
	}

	y=mt[index];

	y= y ^ y >> 11;
	y= y ^ y << 7 & 2636928640;
	y = y ^ y << 15 & 4022730752;
	y = y ^ y >> 18;

	index = index + 1;

	return _int32(y);

}

int main (){
	init_MT_RNG(0);
	MyFile.open("randomNumbers.txt");
	for (int j=0 ; j < 1000 ; j ++){
		uint32_t numberNow= generate_number();
		printf("%d\n",numberNow);
		MyFile<<numberNow<<endl;
	}
}