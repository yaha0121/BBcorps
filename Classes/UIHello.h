//
//  UIHello.h
//  BBcorps
//
//  Created by apple on 15-12-7.
//
//

#ifndef __BBcorps__UIHello__
#define __BBcorps__UIHello__

#include <stdio.h>
#include "cocos2d.h"
class CGameManager;

// CUIHello 负责建立程序加载时的欢迎界面
// 对象初始化之后n秒，会自动回调GotoLogin的函数，前往登录界面

class CUIHello : public cocos2d::LayerColor
{
public:
    CUIHello(void);
    ~CUIHello(void);
    
    virtual bool init();
    
    CREATE_FUNC(CUIHello);
    
    //设置GameManager对象
    void SetGameManager(CGameManager * pGameManager);
    
private:
    void ShowLogo(float);
    
    //定时器的回调函数
    void HelloFinished(float);
    
private:
    CGameManager *  m_pGameManager;
};


#endif /* defined(__BBcorps__UIHello__) */
