//
//  GameManager.cpp
//  BBcorps
//
//  Created by apple on 15-12-7.
//
//

#include "GameManager.h"
#include "UIHello.h"
#include "UIMain.h"

using namespace cocos2d;
using namespace std;

#define DESIGNED_WIDTH          960
#define DESIGNED_HEIGHT         640
CGameManager::CGameManager(void)
{
    m_bChangingScene = false;
}


CGameManager::~CGameManager(void)
{

}


//启动游戏
void CGameManager::Run()
{
    //CResourceData::sharedResourceData()->LoadLoginResource();
    
    //建立Hello对象
    CCScene * sceneHello = CCScene::create();
    if (sceneHello != NULL)
    {
        //CUIHello * uiHello = CUIHello::create();
        CUIMain * ui = CUIMain::create();
        if (ui != NULL)
        {
            ui->SetGameManager(this);
            sceneHello->addChild(ui);
        }
        
        //加载并开始运行
        //CCDirector::sharedDirector()->runWithScene(sceneHello);
        Director::getInstance()->runWithScene(sceneHello);
    }
    
    //开始加载游戏数据
    //m_loader.LoadGame(this);
}


//Hello结束
void CGameManager::HelloFinished()
{
    m_bHelloFinished = true;
    GotoLogin();
}


//切换到登录界面
void CGameManager::GotoLogin()
{
    if (m_bChangingScene)
    {
        return;
    }
    m_bChangingScene = true;
    
    m_strMessage.clear();
    
    Scheduler * pScheduler = Director::getInstance()->getScheduler();
    
    if (pScheduler != NULL)
    {
        //pScheduler->scheduleSelector(schedule_selector(CGameManager::GotoLogin), this, 0, 0, 0, false);
        
        pScheduler->schedule(schedule_selector(CGameManager::GotoLogin), this, 0, 0, 0, false);
        
    }
}


//切换到登录界面
void CGameManager::GotoLogin(float)
{
    m_bChangingScene = false;
    
    //m_battle = BATTLE_UNKNOWN;
    
    ClearCurrentScene();
    
    //建立Login对象
    CCScene * scene = CCScene::create();
    if (scene != NULL)
    {
        //默认先进入游戏界面
        //CUILogin * ui = CUILogin::create();
        CUIMain * ui = CUIMain::create();
        if (ui != NULL)
        {
            ui->SetGameManager(this);
            
            if (m_bLoadFinished)
            {
                //ui->GameLoadFinished();
                
                //m_loader.RefreshServerList(this);
                //                vector<SERVER_INFO> vecServerList;
                //                m_loader.GetServerList(vecServerList);
                //                ui->SetServerList(vecServerList);
            }
            
            if (!m_bBillboardShowed)
            {
                m_bBillboardShowed = true;
                
                //获取公告内容
                string strMessage;
                //m_loader.GetBillboard(strMessage);
                //ui->ShowBillboard(strMessage, m_bLoadFinished,&m_loader);
            }
            
            scene->addChild(ui);
            
        }
        
        //加载新scene，旧的scene会自动释放
        CCDirector::sharedDirector()->replaceScene(scene);
    }
}



void CGameManager::ClearCurrentScene()
{
    //清除旧界面
    //CCScene * scene = CCDirector::sharedDirector()->getRunningScene();
    Scene * scene = Director::getInstance()->getRunningScene();
    
    if (scene != NULL)
    {
        scene->removeAllChildren();
        
        //CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
        
        SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
        
        TextureCache::sharedTextureCache()->removeUnusedTextures();
        
        
        //音效关闭
        //CocosDenshion::SimpleAudioEngine::end();

        
        /*
         CCArmatureDataManager::purgeArmatureSystem();
         CCArmatureDataManager::sharedArmatureDataManager()->removeAll();
         CCAnimationCache::sharedAnimationCache()->purgeSharedAnimationCache();
         CCSpriteFrameCache::sharedSpriteFrameCache()->purgeSharedSpriteFrameCache();
         CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
         CCTextureCache::sharedTextureCache()->purgeSharedTextureCache();
         CCTextureCache::sharedTextureCache()->removeUnusedTextures();
         CocosDenshion::SimpleAudioEngine::end();
         
         CCSpriteFrameCacheHelper::sharedSpriteFrameCacheHelper()->purgeSpriteFrameCacheHelper();
         CCFileUtils::sharedFileUtils()->purgeCachedEntries();
         //        CCFileUtils::sharedFileUtils()->purgeFileUtils();
         CCLabelBMFont::purgeCachedData();
         //        CCPoolManager::sharedPoolManager()->purgePoolManager();
         //        CCDirector::sharedDirector()->purgeCachedData();
         */
    }
}


//请求队列已满
void CGameManager::UserReqFull()
{
    //已经登录
//    if (CLogin::sharedLogin()->GetLoginStatus() == LS_LOGGED_IN)
//    {
//        m_bReqFull = true;
//        
//        if (m_waitingBox == NULL)
//        {
//            CCScene * scene = CCDirector::sharedDirector()->getRunningScene();
//            if (scene != NULL)
//            {
//                m_waitingBox = CWaitingBox::create();
//                if (m_waitingBox != NULL)
//                {
//                    m_waitingBox->retain();
//                    scene->addChild(m_waitingBox, INT_MAX);
//                }
//            }
//        }
//    }
}


//请求队列已空
void CGameManager::UserReqNotFull()
{
//    if (m_bReqFull)
//    {
//        if (m_waitingBox != NULL)
//        {
//            m_waitingBox->removeFromParent();
//            m_waitingBox->release();
//            m_waitingBox = NULL;
//        }
//        
//        m_bReqFull = false;
//    }
}


//请求队列已空
void CGameManager::UserReqEmpty()
{
    /*
     if (m_waitingBox != NULL)
     {
     m_waitingBox->removeFromParent();
     m_waitingBox->release();
     m_waitingBox = NULL;
     }
     */
}

//加载启动信息的反馈
void CGameManager::LoadSuccessed()
{
//    m_bLoadFinished = true;
//    
//    CCScene * scene = CCDirector::sharedDirector()->getRunningScene();
//    if (scene == NULL)
//    {
//        return;
//    }
//    
//    CCArray * children = scene->getChildren();
//    CUILogin * login = dynamic_cast<CUILogin *>(children->objectAtIndex(0));
//    
//    if (login != NULL)
//    {
//        vector<SERVER_INFO> vecServerList;
//        m_loader.GetServerList(vecServerList);
//        login->SetServerList(vecServerList);
//        
//        string strMessage;
//        m_loader.GetBillboard(strMessage);
//        //        login->SetBillbardMessage(strMessage);
//        
//        login->GameLoadFinished();
//    }
}