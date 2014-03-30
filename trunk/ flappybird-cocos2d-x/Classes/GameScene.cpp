#include "GameScene.h"
#include "time.h"

USING_NS_CC;

CCScene* GameScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	GameScene *layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	this->time_randomPipe = 0;

	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(GameScene::menuCloseCallback));

	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));
	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	////int pos_y = rand() % (int)(CCDirector::sharedDirector()->getVisibleSize().height - 40 ) + 40;
	//CCPoint p1 = CCPoint(0 , 0);
	//Pipe* pipe1 = new Pipe(p1, 1);
	//addChild(pipe1);

	//CCPoint p2 = CCPoint(100 , 0);
	//Pipe* pipe2 = new Pipe(p2, -1);
	//addChild(pipe2);
	bird = new Bird();
	addChild(bird);

	this->objs = new CCArray();

	timeFactor		=	0.f;
	this->setTouchEnabled( true );
	this->scheduleUpdate();

	return true;
}

void GameScene::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
#endif
}

void GameScene::ccTouchesBegan(CCSet* ptouch, CCEvent* event)
{
	bird->OnProcessInputBegan();
}
void GameScene::ccTouchesEnded(CCSet* ptouch, CCEvent* event)
{
	bird->OnProcessInputEnd();
}

void GameScene::update( float deltaTime )
{
	time_randomPipe += deltaTime;

	if (time_randomPipe > 2)
	{
		Pipe* pipe1 = new Pipe(1);
		Pipe* pipe2 = new Pipe(-1);
		addChild(pipe1);
		addChild(pipe2);
		objs->addObject(pipe1);
		objs->addObject(pipe2);

		int pos_y = rand() % (int)(CCDirector::sharedDirector()->getVisibleSize().height - 160 ) + 40;

		CCPoint p1 = CCPoint((int)CCDirector::sharedDirector()->getVisibleSize().width ,pos_y - pipe1->getBound().size.height / 2);	
		pipe1->setPosition(p1);

		CCPoint p2 = CCPoint((int)CCDirector::sharedDirector()->getVisibleSize().width , pos_y + pipe2->getBound().size.height / 2 + 100);
		pipe2->setPosition(p2);

		time_randomPipe = 0;
	}

	for (int i = 0; i < objs->count(); i++)
	{
		Pipe* p = (Pipe*)objs->objectAtIndex(i);
		if (p->isAlive == true)
		{
			if (bird->getBound().intersectsRect(p->getBound()))
			{
				bird->isAlive = false;
			}
		}
	}
	
}
