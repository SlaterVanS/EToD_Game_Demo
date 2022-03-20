#include "etodpch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace ETOD {

	Ref<Shader> Shader::Create(const std::string& filepath)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:      ETOD_CORE_ASSERT(false, "RendererAPI::None is currently  not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:    return std::make_shared<OpenGLShader>(filepath);
		}

		ETOD_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<Shader> Shader::Create(const std::string& name, const std::string & vertexSrc, const std::string & fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:      ETOD_CORE_ASSERT(false, "RendererAPI::None is currently  not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:    return std::make_shared<OpenGLShader>(name, vertexSrc, fragmentSrc);
		}

		ETOD_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	void ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader)
	{
		ETOD_CORE_ASSERT(!Exists(name), " ��ɫ���Ѿ����ڣ�"); // Shader already exists!
		m_Shaders[name] = shader;
	}

	void ShaderLibrary::Add(const Ref<Shader>& shader)
	{
		auto& name = shader->GetName();
		Add(name, shader);
	}

	ETOD::Ref<ETOD::Shader> ShaderLibrary::Load(const std::string & filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(shader);
		return shader;
	}

	ETOD::Ref<ETOD::Shader> ShaderLibrary::Load(const std::string & name, const std::string & filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(name, shader);
		return shader;
	}

	ETOD::Ref<ETOD::Shader> ShaderLibrary::Get(const std::string & name)
	{
		ETOD_CORE_ASSERT(Exists(name), " �Ҳ�����ɫ����"); // Shader not found!
		return m_Shaders[name];
	}

	bool ShaderLibrary::Exists(const std::string& name) const
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}

}