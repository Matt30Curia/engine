#include "Sprite.h"


void Sprite::init()
{
	
	texture = LoadTexture(_pathTexture.c_str());

}

Sprite::~Sprite()
{
	UnloadTexture(texture);
}


void Sprite::draw()
{
   DrawTextureEx(texture, pos.toVector2(), rotation, 1, WHITE);
}

