#include "TypeRegistry.hpp"

namespace hw {
namespace obj {

namespace {

static const int MAX_COMPONENT_TYPES = 256;

struct TypeInfo {
	const char* name;
	Type base_type;
};

TypeInfo type_registry[MAX_COMPONENT_TYPES];
int num_types = 0;

} // namespace

Type registerType(const char* name, Type base_type)
{
	HW_ASSERT(num_types >= MAX_COMPONENT_TYPES, "Maximium number of GameComponent types exceeded. Increase MAX_COMPONENT_TYPES.");

	type_registry[num_types].name = name;
	type_registry[num_types].base_type = base_type;

	return num_types++;
}

Type getTypeBase(Type type)
{
	HW_DBG_ASSERT(type < num_types);

	return type_registry[type].base_type;
}

const char* getTypeName(Type type)
{
	HW_DBG_ASSERT(type < num_types);

	return type_registry[type].name;
}

bool typeImplements(Type type, Type base)
{
	HW_DBG_ASSERT(type < num_types);
	HW_DBG_ASSERT(base < num_types);

	while (type != NO_TYPE) {
		if (type == base)
			return true;
		type = getTypeBase(type);
	}

	return false;
}

}
}
