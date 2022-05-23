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

		AssimpMesh(const aiMesh* mesh);

		std::vector<std::shared_ptr<AssimpMesh>> m_Children;

	private:
		void loadMesh(const aiMesh* mesh);

		virtual void updateBuffer() override;
        
        bool m_NeedUpdateBuffer = true;
	};
}