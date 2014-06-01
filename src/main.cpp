// include GL libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// include GLM math library
#include <glm/glm.hpp>
using namespace glm;

// include log tools
#include "utils.hpp"
#include <sstream>
#include <string>



static void key(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	// PROCESS KEY INPUT HERE
}


int viewport_width = 640;
int viewport_height = 480;
void resize(GLFWwindow* window, int width, int height) {
	viewport_width = width;
	viewport_height = height;
}

int main(int argc, char** argv) {
// init GLFW
	log("initialize GLFW");
	if (!glfwInit())
		error("glfwInit failed");

// set error callback
	auto error_callback = [](int code, const char* desc) {
		std::stringstream ss;
		ss << "[GLFW] " << code << " " << desc;
		error(ss.str());
	};
	glfwSetErrorCallback(error_callback);


// create main window
	log("create window");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	GLFWmonitor* mon = glfwGetPrimaryMonitor();
	const GLFWvidmode* vmode = glfwGetVideoMode(mon);
	GLFWwindow* main_window = glfwCreateWindow(vmode->width, vmode->height, "dim4", mon, NULL);
	if (!main_window) {
		glfwTerminate();
		error("glfwCreateWindow failed");
	}
	glfwMakeContextCurrent(main_window);

// set window resize callback
	glfwSetWindowSizeCallback(main_window, resize);


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

// set keyboard callback
	glfwSetKeyCallback(main_window, key);

// start main loop
	glfwSwapInterval(1); //vsync
	while (!glfwWindowShouldClose(main_window)) {
		count_fps(1.0, info);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport(0, 0, viewport_width, viewport_height);

		glfwSwapBuffers(main_window);
		glfwPollEvents();
	}
	
// clean up
	glfwDestroyWindow(main_window);
	glfwTerminate();
	return 0;
}
