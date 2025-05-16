#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/vec3.hpp>
#include <Window.h>
#include <Game.h>
bool full = false;


int main(int argc, char **argv) {
	
	Window wnd(500, 500, full);
	Game jogo;


	unsigned int err = glewInit();
	if (GLEW_OK!=err)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(err));
    	return 1;
	}

	jogo.Init();

    while (!glfwWindowShouldClose(wnd.getID()))
    {
	
	//limpa a tela
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

	jogo.Render();

    glfwSwapBuffers(wnd.getID());


	//recebe os eventos da janela
  	glfwPollEvents();

    }

   
	wnd.~Window();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
