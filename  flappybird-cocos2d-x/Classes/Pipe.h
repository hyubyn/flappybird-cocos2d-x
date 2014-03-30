#include "cocos2d.h"
using namespace cocos2d;
#define Pipe_Velloc 150
#ifndef pipe

class Pipe : public cocos2d::CCNode
{
public:
	bool isAlive;
	cocos2d::CCSprite* body;
	cocos2d::CCRect getBound();
	cocos2d::CCPoint pos;
	int v;
	void update(float dt);
	Pipe();
	Pipe(float scaleY);
	~Pipe(void);
};



#endif // !pipe

