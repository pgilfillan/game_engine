#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

#include "util.hpp"

namespace Util {
    void panic(const char *message) {
        fprintf(stderr, "%s", message);
        glfwTerminate();
        exit(-1);
    }
}
