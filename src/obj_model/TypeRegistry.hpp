#ifndef HEATWAVE_OBJMODEL_TYPEREGISTRY_HPP
#define HEATWAVE_OBJMODEL_TYPEREGISTRY_HPP

#include "Heatwave.hpp"
#include "GameObject.hpp"

namespace hw {
namespace obj {

class ObjectPool;

struct TypeInfo
{
	const char* name;
	ObjectPool* pool;
	Type base_type;
};


static const Type NO_TYPE = 0xFFFF;

Type registerType(const TypeInfo& info);
const TypeInfo& getTypeInfo(Type type);
bool typeImplements(Type type, Type base);

}
}

#endif // HEATWAVE_OBJMODEL_TYPEREGISTRY_HPP
