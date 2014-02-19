#include "STime.h"
#include <chrono>
namespace StiGame
{

STime::STime()
{
    //ctor
}

STime::~STime()
{
    //dtor
}

unsigned long long STime::GetMsTimestamp(void)
{
    std::chrono::time_point<std::chrono::steady_clock> tp = std::chrono::steady_clock::now();

    unsigned long long stamp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count();

    return stamp;
}


}
