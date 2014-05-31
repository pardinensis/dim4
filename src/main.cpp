// include GL libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// include GLM math library
#include <glm/glm.hpp>
using namespace glm;

// include log tools
#include "utils.hpp"



static void key(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	// PROCESS KEY INPUT HERE
}


int main(int argc, char** argv) {
// init GLFW
	log("initialize GLFW");
	if (!glfwInit())
		error("glfwInit failed");

// create main window
	log("create window");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	GLFWwindow* main_window = glfwCreateWindow(640, 480, "dim4", NULL, NULL);
	if (!main_window) {
		glfwTerminate();
		error("glfwCreateWindow failed");
	}
	glfwMakeContextCurrent(main_window);

// init glew extension handler
	log("initialize GLEW");
	glewExperimental = GL_TRUE;
	glewInit();

// print version info
	info("Renderer: " + std::string((const char*) glGetString(GL_RENDERER)));
	info("OpenGL version: " + std::string((const char*) glGetString(GL_VERSION)));

// enable depth test
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glfwSetKeyCallback(main_window, key);

	glfwSwapInterval(1); //vsync
	while (!glfwWindowShouldClose(main_window)) {


		glfwSwapBuffers(main_window);
		glfwPollEvents();
	}
	
// clean up
	glfwDestroyWindow(main_window);
	glfwTerminate();
	return 0;
}
