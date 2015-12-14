//
//  GameManager.h
//  BBcorps
//
//  Created by apple on 15-12-7.
//
//

#ifndef __BBcorps__GameManager__
#define __BBcorps__GameManager__

#include <stdio.h>
#include "cocos2d.h"

///////////////////////////
//
// CGameManager 负责游戏的启动、基础数据设置、场景切换等基本的功能
// CGameManager还注册了用户数据验证出错的消息，当服务端验证用户数据出错时UserDataError会被调用
//
///////////////////////////


class CWaitingBox;

class CGameManager : public cocos2d::CCObject
{
public:
    CGameManager(void);
    ~CGameManager(void);
    
    
    //请求队列已满
    virtual void UserReqFull();
    
    //请求队列未满
    virtual void UserReqNotFull();
    
    //请求队列已空
    virtual void UserReqEmpty();
    
    //加载启动信息的反馈
    virtual void LoadSuccessed();
    
    //启动游戏
    void Run();
    
    //切换到登录界面
    void GotoLogin();
    
    //切换到登录界面
    void GotoLogin(const std::string & strMessage);
    
    //切换到城市建设界面
    void GotoCity();
    
    //切换到测试界面
    void GotoTest();
    
    //Hello结束
    void HelloFinished();
    
    //测试代码
    void DoTest();
    
    //切换到PVE战斗界面
    void GotoPVEBattle(float);
    
    //切换到城市选择副本界面
    void GotoCityPVE(float);
    
    //切换到好友Boss战斗界面
    void GotoFriendBattle(float);
    
    //切换到任务达人Boss战斗界面
    void GotoBuildingBattle(float);
    
    //切换到奶牛关Boss战斗界面
    void GotoCowBattle(float);
    
    //切换到地下城Boss战斗界面
    void GotoDungeonBattle(float);
    
    //切换到公会战战斗界面
    void GotoGuildWarBattle(float);
    
private:
    void ClearCurrentScene();
    
    //切换到登录界面
    void GotoLogin(float);
    
    //切换到城市建设界面
    void GotoCity(float);
    
    //切换到PVP战斗界面
    void GotoPVPBattle(float);
    
    //切换到假战斗界面
    void GotoFakeBattle(float);
    
    //加载游戏数据
    void LoadGame(float);
    
    //进入战斗
    //void GotoBattleTutorial(float);
    
    //进入测试
    void GotoTest(float);
    
private:

    bool            m_bLoadFinished;
    
    bool            m_bHelloFinished;
    
    CWaitingBox *   m_waitingBox;
    
    bool            m_bBillboardShowed;             //是否显示过公告
    
    //PVE 章数
    int m_nInstanceId;
    
    //PVE 关卡
    int m_nLevelId;
    
    //PVE 选择左边y坐标
    float m_nInstanceNodeY;
    
    //PVE 选择左边滚动条y坐标
    float m_nLeftGunNode;
    
    //PVE 选择右边y坐标
    float m_nLevelListNodeY;
    
    //PVE 选择右边滚动条y坐标
    float m_nRightGunNode;
    
    //玩家等级
    int m_nUserLevel;
    
    bool            m_bChangingScene;
    
    std::string     m_strMessage;
    
    bool            m_bWin;
    
    //int             m_nFriendBossId;
    
    float           m_pCowAdd[6];
    
    int             m_pCowBuff[5];
    
    int             m_nCaptainRage;
    
    int             m_nExp;
    
    int             m_nMailId;
    
    int             m_nStrongholdPos;
    
    int             m_hasdebuff;
    
    bool            m_bReqFull;

};

#endif /* defined(__BBcorps__GameManager__) */
