#pragma once
#include <Resource/Data/Interface/Mesh.h>

#include <vector>
#include <assimp/scene.h>

#include <glm/glm.hpp>
namespace Stone
{
	class AssimpNode
	{
	public:
		AssimpNode(const char* filename);

	private:
		aiNode* m_RootNode;

		std::vector<AssimpMesh*> 
	};

	class AssimpMesh : public Mesh
	{
	public:
		AssimpMesh(aiMesh* mesh);
	private:
		aiMesh* m_Mesh;
		glm::mat4 m_Transofrm;
		std::vector<AssimpMesh*> m_Children;
	};
}