#include "Pipe.h"

Pipe::Pipe()
{

}

Pipe::Pipe(float scaleY) : CCNode()
{
	isAlive = true;
	body = cocos2d::CCSprite::create("pipe.png");
	this->v  = Pipe_Velloc;
	//this->setPosition(pos);
	this->setScaleY(scaleY);
	this->addChild(body);
	this->scheduleUpdate();
	
}

CCRect Pipe::getBound()
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

void Pipe::update(float dt)
{
	CCPoint p = this->getPosition();
	p.x -= v * dt;
	this->setPosition(p);
	if (this->getPositionX() + this->getBound().size.width / 2 < 0 )
	{
		if (this->getParent() != NULL)
		{
			this->getParent()->removeChild(this, true);
			this->isAlive = false;
		}
		

	}
}

Pipe::~Pipe(void)
{
}
