#include <string>
// Include GLEW
#include <GL/glew.h>
#include <common/ColorShader.hpp>
#include <glm/glm.hpp>

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>



//default constructor
ColorShader::ColorShader() : Shader(){
}

ColorShader::ColorShader(glm::vec4 rgba){  
    initShaders("colorShader.vert","colorShader.frag");
    setColor(rgba);
}

ColorShader::~ColorShader(){
    glDeleteProgram(programID);    
}

void ColorShader::setColor(glm::vec4 rgba){
    GLint colorID = glGetUniformLocation(programID, "colorValue");
    glProgramUniform4fv(programID , colorID ,1 , &rgba [0]) ;
    
}



