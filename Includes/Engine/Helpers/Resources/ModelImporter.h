#ifndef MINA_HELPERS_RESOURCES_MODELIMPORTER_H
#define MINA_HELPERS_RESOURCES_MODELIMPORTER_H

#include "Engine/pch.hpp"

namespace Mina
{

struct ModelImporterProp
{
};
class ModelImporter
{
private:
public:
	ModelImporter() = delete;
	ModelImporter(const ModelImporter&) = delete;
	ModelImporter(ModelImporter&&) = delete;

	ModelImporter& operator=(const ModelImporter&) = delete;
	ModelImporter& operator=(ModelImporter&&) = delete;

	ModelImporter(const ModelImporterProp& prop);

	entt::entity& import(entt::registry& registry);

	~ModelImporter() = default;
};
}	 // namespace Mina

#endif