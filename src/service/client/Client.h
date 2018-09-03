#ifndef ANDROID_ CLIENT_H
#define ANDROID_ CLIENT_H
#include <binder/Parcel.h>

namespace android
{
    class  Client
    {
    public:
        int setN(int n);
		String8 setString8(String8 str);
    private:
        static void get Service();
    };
}

#endif
