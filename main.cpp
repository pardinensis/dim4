#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

// test includes
#include <chrono>
#include <thread>

int main(int argc, char** argv) {
	if (!glfwInit())
		exit(EXIT_FAILURE);

	GLFWwindow* main_window = glfwCreateWindow(640, 480, "dim4", NULL, NULL);

	std::this_thread::sleep_for(std::chrono::seconds(3));
	
	glfwDestroyWindow(main_window);
	glfwTerminate();
	return 0;
}
