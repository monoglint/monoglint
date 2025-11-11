#include <stdexcept>
#include <iostream>

#include "win.hh"

void win::init_glfw() {
    if (!glfwInit())
        throw std::runtime_error("GLFW failed to initialize.");
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void win::destroy_glfw() {
    glfwTerminate();
}

win::window::window(const std::string& _title, const math::vec2<u32>& size) {
    std::cout << "win create\n";
    
    title = _title;
    handle = glfwCreateWindow(size.x, size.y, _title.c_str(), nullptr, nullptr);

    if (!handle) {
        destroy_glfw();
        throw std::runtime_error("GLFW failed to create a window.");
    }

    glfwMakeContextCurrent(handle);
    glfwSwapInterval(1);
}

win::window::~window() {
    std::cout << "win end\n";

    if (handle)
        glfwDestroyWindow(handle);
}

void win::window::poll_events() {
    glfwPollEvents();
}

void win::window::swap_buffers() {
    glfwSwapBuffers(handle);
}

bool win::window::should_close() {
    return glfwWindowShouldClose(handle);
}

math::vec2<u32> win::window::get_size() const {
    int width;
    int height;

    glfwGetWindowSize(handle, &width, &height);

    return math::vec2<u32>(width, height);
}

math::vec2<u32> win::window::get_position() const {
    int x;
    int y;

    glfwGetWindowPos(handle, &x, &y);

    return math::vec2<u32>(x, y);
}