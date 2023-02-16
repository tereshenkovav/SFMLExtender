#ifndef SF_COUNTDOWN_H
#define SF_COUNTDOWN_H

namespace sf {

class Countdown
{
private:
	float left ;
	bool oncereach ;
public:
	Countdown(void);
	void upset(float interval) ;
	void update(float dt) ;
	bool isActive() ;
	bool onceReachNol() ;
	void reset() ;
	~Countdown(void);
};

}

#endif
