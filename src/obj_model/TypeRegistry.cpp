#include "TypeRegistry.hpp"

namespace hw {
namespace obj {

namespace {

static const int MAX_COMPONENT_TYPES = 256;

TypeInfo type_registry[MAX_COMPONENT_TYPES];
int num_types = 0;

} // namespace

// Warning: This must not depend on any non-constant initialized type, since
// it needs to be used to initialize other variables.
Type registerType(const TypeInfo& info)
{
	HW_ASSERT(num_types < MAX_COMPONENT_TYPES, "Maximium number of GameComponent types exceeded. Increase MAX_COMPONENT_TYPES.");
	HW_ASSERT(info.base_type < num_types, "Invalid base_type specified.");

	type_registry[num_types] = info;

	return num_types++;
}

const TypeInfo& getTypeInfo(Type type)
{
	HW_DBG_ASSERT(type < num_types);

	return type_registry[type];
}

Type getTypeBase(Type type)
{
	return getTypeInfo(type).base_type;
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
