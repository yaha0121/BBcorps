//
//  UILogin.h
//  BBcorps
//
//  Created by apple on 15-12-7.
//
//

#ifndef __BBcorps__UILogin__
#define __BBcorps__UILogin__

#include <stdio.h>
#include "cocos2d.h"
#include "cocos-ext.h"

class CGameManager;
/////////////////////////////////
//
// CUILogin 负责建立用户登录界面，用户信息输入后向后台请求用户数据
// CUILogin调用CLogin对象执行登录
// 登录进程和结果会通过LoginProgress和LoginStatusChanged函数回调
// 用户下载完毕后会调用GotoCity函数，前往城市建设界面
//
/////////////////////////////////

class CUILogin : public cocos2d::Layer
{
public:
    CUILogin(void);
    ~CUILogin(void);
    
    virtual bool init();
//    CREATE_FUNC(CUILogin);
    
    
    //登录状态的回调函数
//    virtual void LoginProgress(float progress);
//    virtual void LoginStatusChanged(LOGIN_STATUS status, const std::string & message);
//    virtual void LoginFinished(LOGIN_STATUS status, const std::string & message);
    
    
    //设置CGameManager对象
    void SetGameManager(CGameManager * pGameManager);
    
    //设置服务器列表
//    void SetServerList(const std::vector<SERVER_INFO> & vecServerList);
    
    //显示公告
//    void ShowBillboard(const std::string & strMessage, bool show, CGameLoader* loader);
    
    //设置公告内容
    void SetBillbardMessage(const std::string & strMessage);
    
    //关闭公告的回调函数
    void BillboardCloseCallback();
    
    //关闭账户中心的回调函数
    void AccountCloseCallback(const std::string & strUsername,
                              const std::string & strPassword,
                              const std::string & strPhoneNumber);
    
    //关闭服务器选择的回调函数
    void ServerBackCallback();
    
    //选择服务器的回调函数
//    void ServerSelectCallback(const SERVER_INFO & server);
    
    //登录按钮的回调函数
    void LoginCallback(const std::string & strUsername,
                       const std::string & strPassword,
                       const std::string & strPhoneNumber);
    
    //注册按钮的回调函数
    void RegisterCallback(const std::string & strUsername,
                          const std::string & strPassword,
                          const std::string & strPhoneNumber);
    
    //选择服务器
    bool SelectServer(int nCategory, const std::string & strName);
    
//    bool SelectServer(const SERVER_INFO & server);
    
    //登出
    void Logout();
    
    //游戏加载完毕
    void GameLoadFinished();
    
    static std::string m_content;
    
private:
    //账户中心按钮
    void ButtonAccountSelected(cocos2d::CCObject * sender);
    
    //快速登录按钮
    void ButtonQuickLoginSelected(cocos2d::CCObject * sender);
    
    //登陆按钮
    void ButtonLoginSelected(cocos2d::CCObject * sender);
    
    //选择服务器按钮
    void ButtonServerSelected(cocos2d::CCObject * sender);
    
    //测试按钮
    void ButtonTestSelected(cocos2d::CCObject * sender);
    
    //显示账户中心
    void ShowAccountCenter();
    
    //显示登录界面
    void ShowLogin();
    
    //显示服务器选择界面
    void ShowServerSelect();
    
    //用户登录
    void Login();
    
    //快速登录
    void QuickLogin();
    
    //用户注册
    void Register();
    
    //保存登录信息
    void SaveLoginInfo();
    
    //加载登录信息
    void LoadLoginInfo();
    
    //转换登陆进度文字
    void GetloginPlanStr(float progress);
    
    //加载资源
    void LoadResource();
    
    void LoadResource(float);
    
    // 下载资源包
    void DownloadResource();
    
    //登录文字信息
    void ResourceProgressTimer(float);
    
    //检查初始战斗
    //已经完成则返回true
    bool CheckFirstBattle();
    
    //检查初始战斗
    //已经完成则返回true
    bool CheckTutorialBattle();
    
    void getLoadTips(int scene_id,std::string & content);
    
private:
    cocos2d::BillBoard *            m_billboard;
    
    cocos2d::CCProgressTimer *      m_loginPlan;   //进度条
    cocos2d::CCSprite *             m_sprLoginPlanBack;     //进度条背景
    
    CGameManager *          m_pGameManager;         //CGameManager对象
    
//    CAccountCenter *        m_accountCenter;        //账户中心
    
    cocos2d::CCNode *       m_nodePop;              //当前弹出的页面
    
    //设置快速进入背景
    cocos2d::CCSprite * account_back;
    cocos2d::CCNode *       m_nodeLogin;            //登录页面
    cocos2d::CCLabelTTF *   m_labelServer;          //当前服务器名
    cocos2d::CCLabelTTF *   m_labelSwapServer;          //点击换区
    cocos2d::CCMenuItemImage * ButServeritem ;
    cocos2d::CCLabelTTF *   m_loginPlanStr; //登陆进度转换文字
    
//    LabelStroke *   m_labelResourceProg;    //资源下载进度文字
    cocos2d::CCLabelTTF *   m_labelDownloadMessage; //下载情况
    
    std::string     m_strInfoFilename;              //信息文件名
    
    std::string     m_strUsername;                  //用户名
    std::string     m_strPassword;                  //密码
    std::string     m_strPhoneNumber;               //手机号
    
    std::string m_strUsernameLast;     //上一次登陆的用户名
    
    std::string m_strServernameLast;
    
    int             m_nUserHead;                    //用户头像
    int             m_nUserLevel;                   //用户等级
    
//    SERVER_INFO     m_serverCurrent;                //当前服务器信息
//    SERVER_INFO     m_serverLast;                   //上次的服务器信息
    
    bool            m_bUserInfoSet;                 //是否设置过用户信息
    
//    std::vector<SERVER_INFO>    m_vecServerList;    //服务器列表
    
    bool            m_bLoginning;           //正在登录
    bool            m_bLoadLocalResource;   //正在加载本地资源
    bool            m_bDownloadResourceList;//正在下载资源
    bool            m_bDownloadResource;    //正在下载资源
    
    int             m_nReqFakeHero1;    //假战斗请求1
    int             m_nReqFakeHero2;    //假战斗请求2
    
    int             m_nReqPVEHero1;     //PVE战斗请求1
    int             m_nReqPVEHero2;     //PVE战斗请求2
    
//    std::vector<HERO_INFO>      m_vecAttacker;
//    std::vector<HERO_INFO>      m_vecDefender;
    
    cocos2d::CCLabelTTF * UserName;
    
    cocos2d::CCMenuItemImage * login_btn;
    
    cocos2d::CCMenuItemImage * QuickBtn;
    
    cocos2d::CCMenuItemSprite *  m_itemAccountCenter;
    
//    LOGIN_STATUS    m_status;
    
    std::string     m_nResourceMessage;
    int             m_nResourceProgDots;
    
//    CCSprite *      m_sprServerStatus;
    
//    CCLabelStroke *             m_labeltips;
    
    int     m_nInstanceId;
    int     m_nLevelId;
    int     m_nExp;
    
//    std::vector<LOADING_TIPS> m_vecLoadTips;
};

#endif /* defined(__BBcorps__UILogin__) */
