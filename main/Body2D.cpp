#include "Body2D.h"

void Body2D::init()
{

	sprites = NodeManager::instance().getChildren(_child);
}

void Body2D::move(Vector2D& velocity, float delta = 1)
{
	
	pos = velocity * delta;
	for (auto sprite : sprites)
	{
		sprite->setRotation(velocity.rotation);
		sprite->setPos(velocity * delta);
	}
}

float Body2D::lookAt(const Vector2& position)
{
	float my = (position.y - pos.y);
	float mx = (position.x - pos.x);
	
	m = std::atan2(my,mx) / RAD;

	return m;
}


