#ifndef HEATWAVE_HWASSERT_HPP
#define HEATWAVE_HWASSERT_HPP

void hw_assert(const char* file, int line, const char* message);

#define HW_ASSERT(cond, message) ((cond) ? (void)0 : hw_assert(__FILE__, __LINE__, message))

#if DBG_ENABLE_DBG_ASSERT
#define HW_DBG_ASSERT(cond) ((cond) ? (void)0 : hw_assert(__FILE__, __LINE__, #cond))
#else
#define HW_DBG_ASSERT(cond)
#endif

#endif // HEATWAVE_HWASSERT_HPP
