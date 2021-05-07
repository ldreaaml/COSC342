
#ifndef COLORSHADER_HPP
#define COLORSHADER_HPP


#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <common/Shader.hpp>


class ColorShader: public Shader{

public:

    ColorShader();
    ColorShader(glm::vec4 rgba);
    ~ColorShader();
    
    void setColor(glm::vec4 rgba);

private:
    glm::vec4 m_rgba; 
};


#endif