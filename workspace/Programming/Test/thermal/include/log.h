#ifndef __LOG_H__

#define __LOG_H__

#define LOGI(...) (printf(LOG_TAG __VA_ARGS__))

#ifdef DEBUG
#define LOGD(...) (printf(LOG_TAG __VA_ARGS__))
#else
#define LOGD(...)
#endif

#endif
