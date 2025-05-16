#include "Window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

//constructor, start the window
Window::Window(int heig, int widt, bool full) {
	Height = heig;
	Width = widt;
	fullscreen = full;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	glfwWindowHint(GLFW_RESIZABLE, false);

	if (full) {
		ID = glfwCreateWindow(heig, widt, "", glfwGetPrimaryMonitor(), NULL);
	}
	else {
		ID = glfwCreateWindow(heig, widt, "", NULL, NULL);
	}

	glfwSetKeyCallback(ID, key_callback);
	glfwSetFramebufferSizeCallback(ID, framebuffer_size_callback);

	glfwMakeContextCurrent(ID);

}

Window::~Window(){
glfwTerminate();
}

GLFWwindow* Window::getID(){
	return ID;
}

void Window::resize(int heig,int widt) {
	glfwSetWindowSize(ID, widt, heig);
	Height = heig;
	Width = widt;
}