#define GLEW_STATIC
#include "simpleTriangle.h"

/*const int       width   = 1280;
const int       height  = 960;

GLSLShader shader;
glm::mat4  P = glm::mat4(1);
glm::mat4 MV = glm::mat4(1);

//out vertex struct for interleaved attributes
struct Vertex {
	glm::vec3 position;
	glm::vec3 color;
};

//triangle vertices and indices
Vertex vertices[3];
GLushort indices[3];

//vertex array and vertex buffer object IDs
GLuint vaoID;
GLuint vboVerticesID;
GLuint vboIndicesID;

void onInitST()
{
    shader.LoadFromFile(GL_VERTEX_SHADER, "shaders/shader.vert");
	shader.LoadFromFile(GL_FRAGMENT_SHADER, "shaders/shader.frag");
	shader.CreateAndLinkProgram();
	shader.Use();
		//add attributes and uniforms
		shader.AddAttribute("vVertex");
		shader.AddAttribute("vColor");
		shader.AddUniform("MVP");
	shader.UnUse();

    //setup triangle geometry
	//setup triangle vertices
	vertices[0].color=glm::vec3(1,0,0);
	vertices[1].color=glm::vec3(0,1,0);
	vertices[2].color=glm::vec3(0,0,1);

	vertices[0].position=glm::vec3(-1,-1,0);
	vertices[1].position=glm::vec3(0,1,0);
	vertices[2].position=glm::vec3(1,-1,0);

	//setup triangle indices
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;

    //setup triangle vao and vbo stuff
    glGenVertexArrays(1, &vaoID);
	glGenBuffers(1, &vboVerticesID);
	glGenBuffers(1, &vboIndicesID);
	GLsizei stride = sizeof(Vertex);

	glBindVertexArray(vaoID);

		glBindBuffer (GL_ARRAY_BUFFER, vboVerticesID);
		//pass triangle verteices to buffer object
		glBufferData (GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

		//enable vertex attribute array for position
		glEnableVertexAttribArray(shader["vVertex"]);
		glVertexAttribPointer(shader["vVertex"], 3, GL_FLOAT, GL_FALSE,stride,0);

		//enable vertex attribute array for colour
		glEnableVertexAttribArray(shader["vColor"]);
		glVertexAttribPointer(shader["vColor"], 3, GL_FLOAT, GL_FALSE,stride, (const GLvoid*)offsetof(Vertex, color));

		//pass indices to element array buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndicesID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);

    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //glOrtho(0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f);
}

void onShutdownST()
{
    //Destroy shader
	shader.DeleteShaderProgram();

	//Destroy vao and vbo
	glDeleteBuffers(1, &vboVerticesID);
	glDeleteBuffers(1, &vboIndicesID);
	glDeleteVertexArrays(1, &vaoID);
}

void onResizeST(int width, int height)
{
    glViewport (0, 0, (GLsizei) width, (GLsizei) height);
    P = glm::ortho(-1, 1, -1, 1);
}

void onRenderST()
{
    //clear the colour and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//bind the shader
	shader.Use();
		//pass the shader uniform
		glUniformMatrix4fv(shader("MVP"), 1, GL_FALSE, glm::value_ptr(P*MV));
			//draw triangle
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
	//unbind the shader
	shader.UnUse();

	//swap front and back buffers to show the rendered result
	glutSwapBuffers();
}

void callSimpleTriangleExample(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutCreateWindow("CEREBRO 3D ENGINE 0.00000000000001");
    glewInit();

    onInitST();
    glutCloseFunc(onShutdownST);
    glutDisplayFunc(onRenderST);
    glutReshapeFunc(onResizeST);
    glutMainLoop();
}*/
