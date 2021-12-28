
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "class_timer.hpp"

using namespace std;

static int do_work( int nIndex, int nRepeats)
{
	int i;
	Timer timer;
	char szDesc[256];
	int nTotal = 1;
		
	
	sprintf( szDesc, "% Thread Start\n", nIndex);	
	printf( "%s", szDesc);
	
	timer.reset();
	for( i=0; i<nRepeats; i++){
		int k = 0;
		for( k=0; k<100000; k++){
			nTotal *= k;
		}
	}
	
	sprintf( szDesc, "% Thread End\n", nIndex);
	
	timer.out( szDesc);
	
	return nTotal;
}

int main( int argc, char* argv[])
{
	int nThreads = 0;
	int nRepeats = 0;
	Timer timer;
	
	if (argc != 3) {
		std::cout << "Usage: ouropenmp threads repeats" << std::endl;
		return 0;
	}
	else {
		nThreads = atoi( argv[1]);
		nRepeats = atoi( argv[2]);
	}
	
	int nIndex = 0;
	
	timer.reset();
	printf( "openmp start\n");
	
	#pragma omp parallel for
	for( nIndex = 0; nIndex < nThreads; nIndex++){
		do_work( nIndex, nRepeats);	
	}
	timer.out( "openmp end\n");
		
	return 0;
}
