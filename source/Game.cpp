#include <Game.h>
#include<glm/vec3.hpp>

unsigned int VBO;
unsigned int VAO;

void Game::Init(){

    Shader teste;
	teste.CreateShader("/home/ferpen/project/shader/shader.vert", "/home/ferpen/project/shader/shader.frag");
    Shaders["teste"] = teste;

    //cria e armazena os vertices em um buffer
	glm::vec3 vertices[3];
	vertices[0] = glm::vec3(-1.0f,-1.0f,0.0f);
	vertices[1] = glm::vec3(0.0f,1.0f,0.0f);
	vertices[2] = glm::vec3(1.0f,-1.0f,0.0f);

	glGenBuffers(1,&VBO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices,GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}


void Game::Render(){
	//coloca o programa do shader em uso
    Shaders["teste"].Use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);


}

void Game::Update(){
    
}