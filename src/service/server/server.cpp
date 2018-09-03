#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include "../service/ Service.h"


using namespace android;


int main(int arg, char** argv)
{
    DebugPrint(" server - ain() begin\n");
    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm = defaultServiceManager();
    //LOGI("ServiceManager: %p\n", sm.get());
    DebugPrint(" server - erviceManager: %p\n", sm.get());
    int ret =  Service::Instance();
    DebugPrint(" server -  Service::Instance return %d\n", ret);
    ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();

	return 0;
}
