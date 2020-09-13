#include <bangtal.h>

using namespace bangtal;

int main()
{
	//장면 생성
	ScenePtr scene1 = Scene::create("룸1", "Images/배경-1.png");
	ScenePtr scene2 = Scene::create("룸2", "Images/배경-2.png");

	//문 생성
	auto open1 = false;
	auto door1 = Object::create("Images/문-오른쪽-닫힘.png", scene1, 800, 270);

	auto door2 = Object::create("Images/문-왼쪽-열림.png", scene2, 320, 270);

	auto door3 = Object::create("Images/문-오른쪽-닫힘.png", scene2, 910, 270);
	auto open3 = true;

	//문 클릭하면 이동
	door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open1 == true) {
			scene2->enter();
		}
		else {
			door1->setImage("Images/문-오른쪽-열림.png");
			open1 = true;
		}
		return true;
	});

	door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			scene1->enter();
		return true;
	});

	door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open3 == true) {
			endGame();
		}
		else {
			door1->setImage("Images/문-오른쪽-열림.png");
			open3 = true;
		}
		return true;
		});

	//게임 시작
	startGame(scene1);

	return 0;
}