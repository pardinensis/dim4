#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

int main(int argc, char** argv) {
	if (!glfwInit())
		exit(EXIT_FAILURE);


	glm::vec4 test(3, 10, -3, 7);
	return 0;
}
