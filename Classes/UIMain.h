//
//  UIMail.h
//  BBcorps
//
//  Created by apple on 15-12-8.
//
//

#ifndef __BBcorps__UIMail__
#define __BBcorps__UIMail__

#include <stdio.h>
#include "cocos2d.h"
#include "Defines.h"
using namespace cocos2d;
class CGameManager;

class CUIMain : public cocos2d::LayerColor
{
public:
    CUIMain(void);
    ~CUIMain(void);
    
    virtual bool init();
    
    CREATE_FUNC(CUIMain);
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event  *event) override;
    
    //设置GameManager对象
    void SetGameManager(CGameManager * pGameManager);
    
    bign num;
    
    LabelTTF * aaLabel;
    
private:
    
    
private:
    CGameManager *  m_pGameManager;
};


#endif /* defined(__BBcorps__UIMail__) */
