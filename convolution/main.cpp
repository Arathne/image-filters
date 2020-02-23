#include <stdio.h>

#define DATASIZE 375000
#define FILTERSIZE 9

FILE* file_id1;
FILE* file_id2;

unsigned char data[DATASIZE];
unsigned char outdata[DATASIZE];

int x, y;
int filter[FILTERSIZE] = { 1,2,3,4,5,4,3,2,1 };


int main()
{
	
	file_id1 = fopen( "unesco750-1.raw", "rb" );
	fread( data, 1, DATASIZE, file_id1 );
	fclose( file_id1 );
	
	for( x = 0; x < DATASIZE; x++ )
	{
		for( y = 0; y < FILTERSIZE; y++ )
		{
			if( x-y >= 0 && x-y < DATASIZE )
			{
				outdata[x] += data[ x-y ] * filter[ y ];		
			}
		}
	}

	file_id2 = fopen( "output.raw", "wb" );
	fwrite( outdata, 1, DATASIZE, file_id2 );
	fclose( file_id2 );
	
	return 0;
}
