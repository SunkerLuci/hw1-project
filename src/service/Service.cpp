#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include " Service.h"


namespace android
{
    //static struct sigaction oldact;
    static pthread_key_t sigbuskey;
    
    int  Service::Instance()
    {
        DebugPrint(" Service Instantiate\n");
        int ret = defaultServiceManager()->addService(
                String16("jack.svc"), new  Service());
        DebugPrint("  Service ret = %d\n", ret);
        return ret;
    }

     Service:: Service()
    {
        DebugPrint("  Service create\n");
        //m_NextConnId = 1;
        pthread_key_create(&sigbuskey,NULL);
    }

     Service::~ Service()
    {
        pthread_key_delete(sigbuskey);
        DebugPrint("  Service destory\n");
    }

    status_t  Service::onTransact(uint32_t code, 
                                 const Parcel& data, 
                                 Parcel* reply,
                                 uint32_t flags)
    {
        switch(code)
        {
        case 0: 
            {
                pid_t pid = data.readInt32();
                int num = data.readInt32();
                num += 1000;
                reply->writeInt32(num);
                return NO_ERROR;
            } break;
		case 1: 
            {
                pid_t pid = data.readInt32();
                String8 str = data.readString8();
				DebugPrint(" case 1 = %s \n",str.string());
				String8 add_str = String8(" service get ")+str;
                //str = add_str + str;
                reply->writeString8(add_str);
                return NO_ERROR;
            } break;
        default:
            return BBinder::onTransact(code, data, reply, flags);
        }
    }
}
