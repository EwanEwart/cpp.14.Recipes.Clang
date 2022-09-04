#include <iostream>
using namespace std;

#include<cstdlib>

#include<GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
  GLFWwindow* window;
  /*
   * Initialise the library
   */
  if (!glfwInit()) {
    return EXIT_FAILURE;
  }
  /*
   * Create a windowed-mode window
   * and its associated OpenGL context
   */
  window = glfwCreateWindow(
          640
        , 480
        , "Plain OpenGLFW Window"
        , nullptr, nullptr
  );
  if (!window)
  {
    /* Terminates the GLFW library. */
    glfwTerminate();
    return EXIT_FAILURE;
  }

  /* Set the window's current context */
  glfwMakeContextCurrent(window);



  GLenum glewError{ glewInit() };
  if (glewError != GLEW_OK)
  {
    return EXIT_FAILURE;
  }



  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window))
  {
    /* Render here */
    /*
     * Swap the front and back buffers,
     * GLFW uses double buffering,
     * to update the screen
     * and process all pending events.
     */
    glfwSwapBuffers(window);
    /* Poll for and process events */
    glfwPollEvents();
  }
  /*
   * Release the memory and
   * terminate the GLFW library.
   * Then, exit the application.
   */
  glfwDestroyWindow(window);
  glfwTerminate();

  return EXIT_SUCCESS;
}
