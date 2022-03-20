#include "etodpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace ETOD {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		ETOD_CORE_ASSERT(windowHandle, "���� handle Ϊ�գ�"); //Window handle is null!
	}

	void OpenGLContext::Init()
	{
		ETOD_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ETOD_CORE_ASSERT(status, " Glad ��ʼ��ʧ��! "); //Failed to initailize Glad!

		ETOD_CORE_INFO("OpenGL ��Ⱦ��Ϣ: "); //OpenGL Info
		ETOD_CORE_INFO("����: {0}", glGetString(GL_VENDOR)); //Vendor
		ETOD_CORE_INFO("�ͺ�: {0}", glGetString(GL_RENDERER)); //Renderer
		ETOD_CORE_INFO("�汾: {0}", glGetString(GL_VERSION)); //Version
	}

	void OpenGLContext::SwapBuffers()
	{
		ETOD_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}
}