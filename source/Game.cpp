#include <Game.h>

unsigned int VBO;
unsigned int VAO;
unsigned int EBO;

void Game::Init(){

    Shader teste;
	teste.CreateShader("/home/ferpen/project/shader/shader.vert", "/home/ferpen/project/shader/shader.frag");
    Shaders["teste"] = teste;

    Texture txt,face;
    txt.CreateTexture("/home/ferpen/project/sprites/container.jpg");
    Textures["teste"] = txt;
    face.CreateTexture("/home/ferpen/project/sprites/awesomeface.png");
    Textures["face"] = face;
    //cria e armazena os vertices em um buffer
	float vertices[] = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};
    unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

	glGenBuffers(1,&VBO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices,GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

    glGenBuffers(1,&EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	// position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

    teste.Use();
    glUniform1i(glGetUniformLocation(teste.getID(), "texture1"), 0);
    glUniform1i(glGetUniformLocation(teste.getID(), "texture2"), 1);
    }


void Game::Render(){

    glActiveTexture(GL_TEXTURE0);
    Textures["teste"].Use();

    glActiveTexture(GL_TEXTURE1);
    Textures["face"].Use();
 
	//coloca o programa do shader em uso
    Shaders["teste"].Use();


	glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void Game::Update(){
    
}