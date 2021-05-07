#ifndef QUAD_HPP
#define QUAD_HPP

#include "Object.hpp"
// Include GLEW
#include <GL/glew.h>
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>

class Quad: public Object{

    public:
        //Default Constructor
        Quad();

        //Deconstructor
        ~Quad();

        void init();

        void render(Camera* camera);

    private:
        GLfloat g_vertex_buffer_data[18];
        GLuint vertexbuffer;
};

#endif