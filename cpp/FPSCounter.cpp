#include "FPSCounter.h"

FPSCounter::FPSCounter(void)
{
	fullsec=1.0f ;
	cnt = 0 ;
	fps = 0 ;
}

void FPSCounter::Tick(float dt) 
{
	if (fps==0) fps = 60 ;

	cnt++ ;
	fullsec-=dt ;
	if (fullsec<=0) {
		fullsec=1.0f ;
		fps=cnt ;
		cnt=0 ;		
	}
}

unsigned int FPSCounter::getFPS()
{
	return fps ;
}
	
FPSCounter::~FPSCounter(void)
{

}
