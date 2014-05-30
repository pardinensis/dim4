#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

// test includes
#include <chrono>
#include <thread>

static void error(const std::string& msg) {
	std::cerr << "ERROR: " << msg << std::endl;
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
	if (!glfwInit())
		error("glfwInit failed");

	GLFWwindow* main_window = glfwCreateWindow(640, 480, "dim4", NULL, NULL);
	if (!main_window) {
		glfwTerminate();
		error("glfwCreateWindow failed");
	}

	std::this_thread::sleep_for(std::chrono::seconds(3));
	
	glfwDestroyWindow(main_window);
	glfwTerminate();
	return 0;
}
