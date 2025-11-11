#include <GLFW/glfw3.h>
#include <iostream>
#include <thread>

#include "win/win.hh"

void glfw_error_callback(int error, const char* description) {
    std::cerr << "GLFW ERR: " << description;
}

int main() {
    std::cout << "Hello world! @monoglint 8:19 pm 10 Nov 2025\nFirst compile 8:39 pm\n";
    
    win::init_glfw();

    glfwSetErrorCallback(glfw_error_callback);
    std::cout << "start\n";

    win::window new_window("Test window");

    while (!new_window.should_close()) {
        new_window.poll_events();
    }

    win::destroy_glfw();

    std::cout << "terminate\n";

    return 0;
}