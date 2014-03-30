#include "cocos2d.h"
#include "Pipe.h"

#define d = 20

using namespace cocos2d;

class GameScene : public CCLayer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCloseCallback(CCObject* pSender);

	// implement the "static node()" method manually
	CREATE_FUNC(GameScene);

	void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

	void update( float deltaTime );

private:
	//Background *background;
	cocos2d::CCArray	*objs;
	//AirCraft	*airCraft;
	//GameManager *gm;
	float time_randomPipe;
	float timeFactor;
};

