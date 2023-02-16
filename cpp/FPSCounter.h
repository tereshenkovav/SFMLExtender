#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

class FPSCounter
{
private:
	unsigned int cnt ;
	unsigned int fps ;
	float fullsec ;
public:
	FPSCounter(void);
	void Tick(float dt) ;
	unsigned int getFPS() ;
	~FPSCounter(void);
};

#endif