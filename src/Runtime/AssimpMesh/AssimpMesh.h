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

		AssimpMesh(const aiMesh* mesh, const aiScene* scene, const aiNode* node, const std::string& filename);

		std::vector<std::shared_ptr<AssimpMesh>> m_Children;

	private:
		void loadMesh(const aiMesh* mesh);

		virtual void updateBuffer() override;
        
        bool m_NeedUpdateBuffer = true;

		const aiScene* m_Scene;
		const aiNode* m_Node;
	};
}