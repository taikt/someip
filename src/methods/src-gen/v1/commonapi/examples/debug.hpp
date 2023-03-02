#define DEBUG_ENABLE 1

#if DEBUG_ENABLE
#define DEBUG_MSG() std::cout<< "[CSOMEIP][DEBUG] func:" <<__FUNCTION__<<", file:"<<__FILE__<<"("<<__LINE__<<")\n"
#else
#define DEBUG_MSG()
#endif