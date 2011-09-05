#include "Heatwave.hpp"
#include "hw_assert.hpp"
#include <cstdio>
#include <cstdlib>

void hw_assert(const char* file, int line, const char* message)
{
	fprintf(stderr, "Assert failed! %s:%d: %s\n", file, line, message);
	exit(1);
}
