#pragma once
class GameObject
{
protected:
	static int windowWidth;
	static int windowHeight;
	int radius;
public:
	GameObject(int radiusIn);
	static void setWindowWidth(int windowWidthIn);
	static void setWindowHeight(int windowHeightIn);
};

