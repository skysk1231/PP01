#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <Windows.h>


#pragma comment(lib,"OpenGL32")
using namespace std;

//적 색깔 코드 255, 0,0 주인공 207,255,229 공룡게임 만들기

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    bool GameRunning = true;
    float a = 0, b, c = 0.7;
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);// 함수 포인터

    do
    {

        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
        {
            b = 0.1;
        }
        else
        {
            b = 0;
        }

        glClearColor(1, 1, 1,1);
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(10);
        glBegin(GL_POINTS);
        glColor3f(0, 255, 255);
        glVertex2f(a, b);

        if (GameRunning == true)
        {
            if (c <= -1 && c != 0)
            {
                c -= 0.005;
                c = 1;
            }
            else if (c == 0.1)
            {
                c = 0.1;

            }
            else
            {
                c -= 0.005;
            }
        }
        if (GameRunning == false)
        {
            if (GetAsyncKeyState(VK_CONTROL) & 0x8000 || GetAsyncKeyState(VK_CONTROL) & 0x8001)
            {
                GameRunning = true;
                c = 1;
            }
            if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || GetAsyncKeyState(VK_SHIFT) & 0x8001)
            {
                break;
            }
        }

        glPointSize(10);
        glBegin(GL_POINTS);
        glColor3f(1, 0, 0);
        glVertex2f(c, a);
        glEnd();

        if (a == 0 && b == 0)
        {
            if (c < 0.01 && c>-0.01)
            {
                GameRunning = false;
                cout << "게임 오버";
                glColor3f(0, 1, 0);

                glEnd();
            }
        }


        glfwSwapBuffers(window);
        glfwPollEvents();

    } while (!glfwWindowShouldClose(window));

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}