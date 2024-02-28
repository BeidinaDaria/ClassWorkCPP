#include "Singleton.h"
#include "Builder.h"
//#define SINGLETON
#define BUILDER

int main()
{
#ifdef SINGLETON
    President* pr = President::getInstance("Putin");
#endif

#ifdef BUILDER

#endif
}