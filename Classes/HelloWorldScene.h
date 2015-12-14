#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CResource.h"
#include "cocostudio/CocoStudio.h"

using namespace cocostudio;

class HelloWorld : public cocos2d::Layer
{
public:
    
    HelloWorld();
    ~HelloWorld();
    
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    //动画监听事件
    void animationEvent(cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID);
    
    void dataLoaded(float percent);
    
    float           m_fDeviceScale;
    float           m_fFontScale;

};

#endif // __HELLOWORLD_SCENE_H__
