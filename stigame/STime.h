#ifndef STIME_H
#define STIME_H

namespace StiGame
{

class STime
{
    public:
        STime();
        virtual ~STime();
        static unsigned long long GetMsTimestamp(void);
    protected:
    private:
};

}

#endif // STIME_H
