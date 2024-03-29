#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <memory>

#include "ShaderProgram.h"

void Framebuffer_size_callback(GLFWwindow* window, int width, int height);


class MainWindow
{
public:
	MainWindow();

	// Main functions (initialization, run)
	int Initialisation();
	int RenderLoop();

	// Callback to intersept GLFW calls
	void FramebufferSizeCallback(int width, int height);

private:
	// Initialize GLFW callbacks
	void InitializeCallback();
	// Intiialize OpenGL objects (shaders, ...)
	int InitializeGL();

	// Create 2 triangles vertices
	void CreateVertices();

	// Rendering scene (OpenGL)
	void RenderScene();

private:
	// settings
	const unsigned int SCR_WIDTH = 1200;
	const unsigned int SCR_HEIGHT = 800;
	GLFWwindow* m_window = nullptr;

	// Autre facon de d�clarer les VAO et VBO
	enum VAO_IDs { 
		Triangles, // valeur = 0 
		NumVAOs    // valeur = 1 (doit toujours etre en dernier
	};
	enum Buffer_IDs { 
		ArrayBuffer, // valeur = 0 
		NumBuffers   // valeur = 1 (doit toujours etre en dernier
	};
	GLuint m_VAOs[NumVAOs]; // tableau contenant tous les (identifiants) de VAO
	GLuint m_buffers[NumBuffers]; // tableau contenant tous les (identifiants) de VBO

	std::unique_ptr<ShaderProgram> m_mainShader = nullptr ;
};
