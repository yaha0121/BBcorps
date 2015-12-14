//
//  UIMail.cpp
//  BBcorps
//
//  Created by apple on 15-12-8.
//
//

#include "UIMain.h"
#include "VisibleRect.h"

using namespace cocos2d;

CUIMain::CUIMain(void)
{
    m_pGameManager = NULL;
    
    aaLabel = NULL;
}


CUIMain::~CUIMain(void)
{
    
}

// on "init" you need to initialize your instance
bool CUIMain::init()
{
    if ( !LayerColor::init() )
    {
        return false;
    }
    
    //主界面 arm64 
//    auto * mainNode =
    
    bign aa;
    aa.operator=("219873981273971927838");
    
    bign bb;
    bb.operator=("12831728979182739871298739182739871293712937912873");
    
    aa.operator+=(bb);
    
    num.operator=(aa);
    
    //注册触摸监听
    auto listener = EventListenerTouchOneByOne::create();//创建一个触摸监听
    listener->setSwallowTouches(true);//设置是否想下传递触摸
    listener->onTouchBegan = CC_CALLBACK_2(CUIMain::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(CUIMain::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(CUIMain::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(CUIMain::onTouchCancelled, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    aaLabel = LabelTTF::create(num.str(), "", 20);
    aaLabel->setPosition(VisibleRect::center().x,VisibleRect::center().y);
    this->addChild(aaLabel);
    
    
    return true;
}


void CUIMain::SetGameManager(CGameManager *pGameManager)
{
    m_pGameManager = pGameManager;
}

bool CUIMain::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    //点击事件
    num.operator+=("1");
    aaLabel->setString(num.str());
    return true;
}
