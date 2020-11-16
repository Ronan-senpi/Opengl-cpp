#include <GL/glew.h>
#include <GLFW/glfw3.h>

/// <summary>
/// Initialize nothing for moment
/// </summary>
/// <returns></returns>
bool Initialize() {
    return true;
}
/// <summary>
/// Terminate nothing for moment
/// </summary>
void Terminate() {

}

/// <summary>
/// Render here
/// </summary>
/// <param name="window"></param>
void Display(GLFWwindow* window) {
    int width, height;
    /* Render here */
    glfwGetWindowSize(window, &width, &height);

    glViewport(0, 0, width, height);
    glClearColor(.5f, .5f, .5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    static const float triangle[] = {
        //(x,y)
        -0.8f, +0.8f, //1er sommet
        0.0f, -0.8f, // 2eme sommet
        +0.8f, +0.8f // 3eme sommet
    };
    //On indique a OpenGL la structuration des sommets
    //Stride : Interval en octets entre deux sommets

    //TODO : Faire en sorte que "Triangle" reste sur le GPU tant qu'il ne change pas
    // Buffer object, VBO(slide 28), 
    //TD 1 a partir de II rendu de triangle -Partie B
    glVertexAttribPointer(0, 2 /*(x,y)*/, GL_FLOAT, false,2*sizeof(float)/*Stride*/, triangle);
    glEnableVertexAttribArray(0);
    //dessine moi un triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);

}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the glfw3 library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Initialize the glew library */
    glewInit();

    /*Important pour le tp*/
    Initialize();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        Display(window);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    Terminate();
    glfwTerminate();
    return 0;
}
