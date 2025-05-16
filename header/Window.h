#ifndef Window_h
#define Window_h

#include <GL/glew.h>
#include <GLFW/glfw3.h>
class Window
{
private:
	GLFWwindow* ID;
	unsigned int Height;
	unsigned int Width;
	bool fullscreen;

public:
	Window(int heig, int widt, bool full);
	~Window();
	GLFWwindow* getID();
	void resize(int heig,int wid);
};
#endif