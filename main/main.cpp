#include <iostream>
#include "RenderObj.h"
#include "Vector2.h"
#include "raylib.h"
#include "Point.h"
#include "Body2D.h"
#include <vector>
#include "NodeManager.h"


constexpr auto screenWidth = 1600;
constexpr auto screenHeight = 800;



class Enemy : public Body2D {

	Vector2D velocity = Vector2D(5.f, 5.f);


public:

	Enemy(std::string path, std::string id) : Body2D(path, id) {}

	void process(float delta) override {

		velocity.x += 5.0f;
		velocity.y += 2.0f;



		move(velocity, delta);

	}

};


class Player: public Body2D {

	const float vel = 1;

	float rotation = 0;
	Vector2D velocity = Vector2D(1.f, 1.f);

public:

	Player(std::string path, std::string id) : Body2D(path, id){}

	void process(float delta) override {
		
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) ) {
			rotation = lookAt(GetMousePosition());
			
		}

		if (Vector2D().toVector2D((GetMousePosition())) > velocity) {
			velocity += velocity.rotate(rotation) * 10; std::cout << "click";
		}

		std::cout << velocity.x<<std::endl;

		velocity.rotation = rotation;
		move(velocity ,delta);
		
		

	}

};





void draw(Node& node)
{
	

	InitWindow(screenWidth, screenHeight, "prova");
	

	node.init();

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		
		node.process(GetFrameTime());

		ClearBackground(RAYWHITE);

		EndDrawing();
	}
	CloseWindow();


}




int main()
{


	RenderObj* textuRe = new Node({ 
		new Sprite("resources/h.png", "sprite"),
		new Sprite("resources/h1.png", "sprite"),
	 },"textTure");


	Node* player = new Node({

		new Player("sprite", "player"),
		textuRe

	}, "player");


	NodeManager::instance().setNode(*player); //node manager singleton instance

	draw(*player); //window manager

	delete textuRe;
	delete player;

	return 0;
}

/*
	TO-DO
		IMPLEMENTING: SCENE MANAGER, MOVE METHOD(DRAG AND CLICK, ROTATE), 
*/
