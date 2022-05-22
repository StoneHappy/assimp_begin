#pragma once

#include <Resource/Data/Implement/VCG/VCGMesh.h>

#include <vector>
#include <assimp/scene.h>

#include <glm/glm.hpp>
#include <memory>
namespace Stone
{
	class AssimpMesh : public Mesh
	{
	public:
		AssimpMesh(const char* filename);

		AssimpMesh(const aiScene* sc, const aiNode* node);

		std::vector<std::shared_ptr<AssimpMesh>> m_Children;

	private:
		void loadMesh(const aiScene* scene, const aiNode* node);

		virtual void updateBuffer() override;
        

		glm::mat4 m_Transofrm;

		const aiScene* m_Scene;
		const aiNode* m_Node;

        bool m_NeedUpdateBuffer = true;
	};
}