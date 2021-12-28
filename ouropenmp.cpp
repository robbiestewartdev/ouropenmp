
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "class_timer.hpp"

using namespace cv;
using namespace std;

static void do_work( int nIndex, int nRepeats)
{
	int i;
	Timer timer;
	char szDesc[256];
	
	sprintf( szDesc, "% Thread", nIndex);
		
	timer.reset();
	for( i=0; i<nRepeats; i++){
		usleep(1000);
	}
	timer.out( szDesc);
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
	printf( "openmp start");
	
	#pragma omp parallel for
	for( nIndex = 0; nIndex < nThreads; nIndex++){
		do_work( nIndex, nRepeats);	
	}
	timer.out( "openmp end");
		
	return 0;
}
