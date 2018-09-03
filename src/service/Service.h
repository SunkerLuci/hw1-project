#ifndef ANDROID_ SERVICE_H
#define ANDROID_ SERVICE_H

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android
{
    class  Service : public BBinder
    {
    private:
        //mutable Mutex m_Lock;
        //int32_t m_NextConnId;

    public:
        static int Instance();
         Service();
        virtual ~ Service();
        virtual status_t onTransact(uint32_t, const Parcel&, Parcel*, uint32_t);
    };
}

#endif
