#include <Shader.h>
#include <fstream>

bool Shader::CreateShader(std::string VertexSourcePath,std::string FragmentSourcePath){

    //misc
    int success;
    char infoLog[512];

    //cria o programa que está com os shaders
    ID = glCreateProgram();
    
    //carrega o shader de vertices
    std::ifstream VertexSource(VertexSourcePath);

    //lê o arquivo
    if (VertexSource.is_open()){
        std::string lineVertex;
        std::string loadVertex;
        while(getline(VertexSource, lineVertex)){
            loadVertex.append(lineVertex);
            loadVertex.append("\n");
        }
    VertexSource.close();
    
    //cria o shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);;
    const char *ConstVertex = loadVertex.c_str();
    glShaderSource(vertexShader, 1, &ConstVertex, NULL);
    glCompileShader(vertexShader);

    //confere o shader
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //aplica o shader de vertice ao programa
    glAttachShader(ID, vertexShader);

    //deleta o shader utilizado
    glDeleteShader(vertexShader);

    }
    else{
        printf("Vertex Source not found");
        return false;
    }

    //passa para o shader de fragmento
    std::ifstream FragmentSource(FragmentSourcePath);

    if (FragmentSource.is_open()){
        //lê o arquivo
        std::string lineFragment;
        std::string loadFragment;
        while(getline(FragmentSource, lineFragment)){
            loadFragment.append(lineFragment);
            loadFragment.append("\n");
        }
    FragmentSource.close();
    

    //cria o shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char *ConstFragment = loadFragment.c_str();
    glShaderSource(fragmentShader, 1, &ConstFragment, NULL);
    glCompileShader(fragmentShader);

    //confere o shader
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
      if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //aplica o shader de fragmento ao programa
    glAttachShader(ID, fragmentShader);

    //deleta o shader
    glDeleteShader(fragmentShader);
    }

    else{
        printf("Fragment Source not found");
        return false;
    }

    glLinkProgram(ID);

    // confere o programa
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        return false;
    }

    return true;
}

void Shader::Use(){
    glUseProgram(ID);
}

unsigned int Shader::getID(){
    return ID;
}