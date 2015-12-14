//
//  UIHello.cpp
//  BBcorps
//
//  Created by apple on 15-12-7.
//
//
#include "UIHello.h"
#include "GameManager.h"

using namespace cocos2d;


#define FONT_NAME       "Arial"
#define FONT_SIZE       64
#define LOGO_DELAY      2.0
#define CALLBACK_DELAY  3.0
#define FADE_TIME       0.2

CUIHello::CUIHello(void)
{
    m_pGameManager = NULL;
}


CUIHello::~CUIHello(void)
{
}


// on "init" you need to initialize your instance
bool CUIHello::init()
{
    if ( !CCLayerColor::init() )
    {
        return false;
    }
    
    
    /*
     //生成演示文字
     CCLabelTTF * label = CCLabelTTF::create("上海致玩网络科技有限公司\n出品", FONT_NAME, FONT_SIZE);
     
     // ask director the window size
     label->setPosition( ccp(size.width / 2, size.height / 2) );
     label->setScale(CResourceData::sharedResourceData()->GetFontScale());
     
     //添加文字对象
     this->addChild(label, 1);
     */
    
    //ShowFanTuan(0);
    
    //ShowZhiWan(0);
    
    return true;
}

void CUIHello::SetGameManager(CGameManager *pGameManager)
{
    m_pGameManager = pGameManager;
}

void CUIHello::ShowLogo(float)
{
//    CCSize size = CCDirector::sharedDirector()->getWinSize();
//    
//    {
//        //        this->setColor(ccc3(255, 255, 255));
//        this->setOpacity(0);
//        
//        CCFadeIn * fadein = CCFadeIn::create(FADE_TIME);
//        CCDelayTime *delay = CCDelayTime::create(LOGO_DELAY);
//        CCFadeOut * fadeout = CCFadeOut::create(FADE_TIME);
//        CCSequence * seq = CCSequence::create(fadein, delay, fadeout, NULL);
//        this->runAction(seq);
//    }
//    
//    std::string strDeviceResourcePath = CResourceData::sharedResourceData()->GetDeviceResourcePath();
//    CCSprite * sprite = CCSprite::create((strDeviceResourcePath + "background/hello_9meng.pvr.ccz").c_str());
//    if (sprite != NULL)
//    {
//        sprite->setPosition(ccp(size.width / 2, size.height / 2));
//        this->addChild(sprite);
//        
//        sprite->setOpacity(0);
//        CCFadeIn * fadein = CCFadeIn::create(FADE_TIME);
//        CCDelayTime *delay = CCDelayTime::create(LOGO_DELAY);
//        CCFadeOut * fadeout = CCFadeOut::create(FADE_TIME);
//        CCSequence * seq = CCSequence::create(fadein, delay, fadeout, NULL);
//        sprite->runAction(seq);
//    }
    
    //开启定时器
    scheduleOnce(schedule_selector(CUIHello::HelloFinished), FADE_TIME + LOGO_DELAY + FADE_TIME);
}


void CUIHello::HelloFinished(float)
{
    if (m_pGameManager != NULL)
    {
        m_pGameManager->HelloFinished();
    }
}