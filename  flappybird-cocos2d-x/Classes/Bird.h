#ifndef __BIRD_H_
#define __BIRD_H_

#include "cocos2d.h"
using namespace cocos2d;
class Bird: public cocos2d::CCNode
{
private:
	CCSprite* body;
	int n;
	int v;
	int g;
	CCRect screen;
public:
	bool isAlive;
	Bird(void);
	void OnProcessInputBegan();
	void OnProcessInputEnd();
	void update(float);
	CCRect getBound();
	~Bird(void);
};

#endif
