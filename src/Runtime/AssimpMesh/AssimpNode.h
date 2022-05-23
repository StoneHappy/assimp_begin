#pragma once
#include <vector>
#include "AssimpMesh.h"

#include <assimp/scene.h>

#include <glm/glm.hpp>
namespace Stone
{
	class AssimpNode
	{
	public:
		AssimpNode(const char* filename);

		AssimpNode(AssimpNode* parentNode, const aiNode* node, const aiScene* scene);

		static void recusiveRender(AssimpNode* node);
	public:

		void loadNode(const aiScene* scene, const aiNode* node);

		std::vector<std::shared_ptr<AssimpMesh>> m_ChildMeshes;
		std::vector<std::shared_ptr<AssimpNode>> m_ChildNodes;

		glm::mat4 m_Transform;

		const aiScene* m_Scene;
		const aiScene* m_Node;
		const AssimpNode* m_Parent;
	};
}