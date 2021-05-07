#include "Quad.hpp"

Quad::Quad()
{
    init();
}
Quad::~Quad(){
    glDeleteBuffers(1,&vertexbuffer);
}

void Quad::init(){

    g_vertex_buffer_data[0] = -1.0f, g_vertex_buffer_data[1]=  -1.0f, g_vertex_buffer_data[2]=0.0f;
    g_vertex_buffer_data[3] = 1.0f, g_vertex_buffer_data[4]=  -1.0f, g_vertex_buffer_data[5]=0.0f;
    g_vertex_buffer_data[6] = 0.0f, g_vertex_buffer_data[7]=  1.0f, g_vertex_buffer_data[8]=0.0f;

    g_vertex_buffer_data[9] = 0.0f, g_vertex_buffer_data[10]=  -3.0f, g_vertex_buffer_data[11]=0.0f;
    g_vertex_buffer_data[12] = -1.0f, g_vertex_buffer_data[13]=  -1.0f, g_vertex_buffer_data[14]=0.0f;
    g_vertex_buffer_data[15] = 1.0f, g_vertex_buffer_data[16]=  -1.0f, g_vertex_buffer_data[17]=0.0f;
        

    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    
}

void Quad::render(Camera* camera){
    bindShaders();
    glm::mat4 ModelMatrix = this->getTransform();
    glm::mat4 MVP = camera->getViewProjectionMatrix() * ModelMatrix;

    shader->updateMVP(MVP);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,        // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,        // size
        GL_FLOAT, // type
        GL_FALSE, // normalized?
        0,        // stride
        (void *)0 // array buffer offset
    );

    glDrawArrays(GL_TRIANGLES,0,6);
    glDisableVertexAttribArray(0);
}

