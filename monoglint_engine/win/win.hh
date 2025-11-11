#pragma once

/*

DEPENDENCIES
math

*/

#include <GLFW/glfw3.h>
#include <string>

#include "math/math.hh"

namespace win {
    void init_glfw();
    void destroy_glfw();

    struct window {
        window(const std::string& _title, const math::vec2<u32>& size = { 800, 600 });
        ~window();

        window(const window& other) = delete;
        window(window&& other) {
            title = other.title;
            handle = other.handle;

            other.handle = nullptr;
        }

        void poll_events();
        void swap_buffers();
        bool should_close();
        
        [[nodiscard]]
        inline std::string get_title() const {
            return title;
        }

        [[nodiscard]]
        math::vec2<u32> get_size() const;

        [[nodiscard]]
        math::vec2<u32> get_position() const;
        
    private:
        std::string title;

        GLFWwindow* handle;
    };
}