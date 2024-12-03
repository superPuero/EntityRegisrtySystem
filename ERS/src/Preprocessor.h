#pragma once


template<typename...L>
inline void log_function(L...args) {
	std::cout << '\n';
	((std::cout << args << ' '), ...);
}

#ifdef ERS_DEBUG
	#define ERS_LOG_WARNING(...)	ERS_LOG("WARNING:", __VA_ARGS__/*, "in", __FILE__, "at line", __LINE__, "in", __func__, "function"*/)
	#define ERS_LOG_ERROR(...)		ERS_LOG("ERROR:",	__VA_ARGS__/*, "in", __FILE__, "at line", __LINE__, "in", __func__, "function"*/)
#else	
	#define ERS_LOG_WARNING(...)	
	#define ERS_LOG_ERROR(...)		
#endif //ERS_DEBUG

