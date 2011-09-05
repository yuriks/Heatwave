#ifndef HEATWAVE_OBJMODEL_TYPEREGISTRY_HPP
#define HEATWAVE_OBJMODEL_TYPEREGISTRY_HPP

#include "Heatwave.hpp"
#include "GameObject.hpp"

namespace hw {
namespace obj {

static const Type NO_TYPE = 0xFFFF;

Type registerType(const char* name, Type base_type = NO_TYPE);
Type getTypeBase(Type type);
const char* getTypeName(Type type);
bool typeImplements(Type type, Type base);

}
}

#endif // HEATWAVE_OBJMODEL_TYPEREGISTRY_HPP
