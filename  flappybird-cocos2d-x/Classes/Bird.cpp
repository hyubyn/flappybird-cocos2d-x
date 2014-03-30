#include "Bird.h"


Bird::Bird(void)
{
	isAlive = true;
	v = -6;
	n = 0;
	g = -7;
	screen = CCRect(0,0,CCDirector::sharedDirector()->getVisibleSize().width,CCDirector::sharedDirector()->getVisibleSize().height );
	body = cocos2d::CCSprite::create("bird.png");
	body->setScale(0.5f);
	addChild(body);
	setPosition(screen.size.width / 4,screen.size.height / 2);
	scheduleUpdate();
}


Bird::~Bird(void)
{
}

void Bird::update(float delta)
{
	if(this->getPositionY() < 0)
	{
		isAlive = false;
	}
	if(isAlive == true)
	{
		n = n - delta * n;
		v = n + g;
		if(this->getPositionY() < screen.size.height)
			this->setPositionY(this->getPositionY() + v);
		else 
		{
			this->setPositionY(this->getPositionY() - 10);
		}
		CCRect p = getBound();
		if(v > 0)
		{
			body->setRotation(-40);
		}
		else
		{
			body->setRotation(40);
		}
	}
}

void Bird::OnProcessInputBegan()
{
	n = 23;
}

void Bird::OnProcessInputEnd()
{
	
}

CCRect Bird::getBound()
{
	if( this->body != NULL )
	{
		CCRect bodySize	=	body->boundingBox();
		CCPoint bodyPoint	=	this->getPosition();
		CCRect bound		=	cocos2d::CCRectMake( bodyPoint.x - bodySize.size.width/2, 
		bodyPoint.y - bodySize.size.height/2, bodySize.size.width, bodySize.size.height );
		return bound;
	}
	return CCRectMake(0, 0, 0, 0);
}