#include <AL/alc.h>
#include <AL/al.h>

ALCdevice *device=alcOpenDevice(NULL);
ALCcontext *context=alcCreateContext(device,NULL);

void sound(){
    alcMakeContextCurrent(context);
}
