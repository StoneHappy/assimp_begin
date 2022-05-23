#include "AssimpNode.h"
#include <assimp/cimport.h>
#include <assimp/postprocess.h>

#include <Function/Render/Interface/Renderer.h>

namespace Stone
{
	AssimpNode::AssimpNode(const char* filename)
	{
		m_Parent = nullptr;
		const aiScene* scene = aiImportFile(filename, aiProcessPreset_TargetRealtime_MaxQuality);
		loadNode(scene, scene->mRootNode);
	}
	AssimpNode::AssimpNode(AssimpNode* parentNode,const aiNode* node, const	aiScene* scene)
		: m_Scene(scene), m_Parent(parentNode)
	{
		loadNode(scene, node);
	}

	void AssimpNode::recusiveRender(AssimpNode* node)
	{
		for (auto mesh : node->m_ChildMeshes)
		{
			PublicSingletonInstance(Renderer).render(mesh.get());
		}
		for (auto child : node->m_ChildNodes)
		{
			recusiveRender(child.get());
		}
	}

	void AssimpNode::loadNode(const aiScene* scene, const aiNode* node)
	{
		for (size_t i = 0; i < node->mNumMeshes; i++)
		{
			const aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
			m_ChildMeshes.push_back(std::make_shared<AssimpMesh>(mesh));
		}

		for (size_t i = 0; i < node->mNumChildren; i++)
		{
			m_ChildNodes.push_back(std::make_shared<AssimpNode>(this, node->mChildren[i], scene));
		}
	}
}