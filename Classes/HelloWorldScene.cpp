#include "HelloWorldScene.h"
#include "VisibleRect.h"
#include "cocostudio/CocoStudio.h"

#if ENABLE_PHYSICS_BOX2D_DETECT
#include "../../Box2DTestBed/GLES-Render.h"
#include "Box2D/Box2D.h"
#elif ENABLE_PHYSICS_CHIPMUNK_DETECT
#include "chipmunk.h"
#endif


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

HelloWorld::HelloWorld(){
    
    m_fDeviceScale = 1;
    m_fFontScale = 1;
    
    auto m_sizeDesign = CCSizeMake(960, 640);
    
    auto director = Director::getInstance();
    auto eglview = director->getOpenGLView();
    auto sizeDevice = eglview->getFrameSize();
    
    
    eglview->setDesignResolutionSize(m_sizeDesign.width, m_sizeDesign.height, ResolutionPolicy::NO_BORDER);
    
    float fScaleX = (float)sizeDevice.width / m_sizeDesign.width;
    float fScaleY = (float)sizeDevice.height / m_sizeDesign.height;
    float fScale = (fScaleX < fScaleY) ? fScaleX : fScaleY;
    if (fScale < 0.95)
    {
        fScale = 0.5;
    }
    else if (fScale < 1.45)
    {
        fScale = 1;
    }
    else if (fScale < 1.95)
    {
        fScale = 1.5;
    }
    else
    {
        fScale = roundf(fScale);
    }
    
    fScale = 1;
    
    //eglview->setDesignResolutionSize(480, 320, ResolutionPolicy::NO_BORDER);
    
    m_fDeviceScale = fScale;
    
}

HelloWorld::~HelloWorld(){
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    CCLog("director = %f",_director->getContentScaleFactor());
    
    _director->setContentScaleFactor(1);
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size winSize = Director::getInstance()->getWinSize();
    
    //设置优先加载资源文件
    auto fileUtils = FileUtils::getInstance();
    
    std::vector<std::string> searchPaths;
    searchPaths.push_back("Armature");
    
    
    fileUtils->setSearchPaths(searchPaths);
   
    //播放骨头动画
    std::string RootResource = CResourceData::sharedResourceData()->getArmatureResource();
    
    std::string IphoneResource = CResourceData::sharedResourceData()->getIphoneResource();
    
    std::string xml = RootResource + "agathelos.xml";
    
    std::string img = RootResource + "agathelos.png";
    
    std::string plist = RootResource + "agathelos.plist";
    
    std::string str_json = RootResource + "HeroAnimation.ExportJson";
    
    std::string str_cbs = RootResource + "HeroAnimation.csb";
    
    
    ArmatureDataManager::getInstance()->addArmatureFileInfo(img.c_str(), plist.c_str(), xml.c_str());
    
    //ArmatureDataManager::getInstance()->addArmatureFileInfo(str_json.c_str());
//    armature.width = 188.439743,armature.height = 216.856171
//    armature.width = 130.217926,armature.height = 161.162491
    
    Armature * armature = Armature::create("agathelos");
    armature->getAnimation()->play("hurt");
    armature->getAnimation()->setSpeedScale(0.4f);
    armature->setPosition(VisibleRect::center().x, VisibleRect::center().y * 0.3f);
    
    addChild(armature,100);
    
    
    //添加动画监听
    //armature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_0(HelloWorld::animationEvent, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    

    
    std::string backPath = RootResource + "ask_skirmish_back.pvr.ccz";
    
    Sprite * backGround = Sprite::create(backPath.c_str());
    backGround->setPosition(VisibleRect::center().x,VisibleRect::center().y);
    backGround->setAnchorPoint(Vec2(0.5, 0.5));
    backGround->setVisible(true);
    this->addChild(backGround,10);
    
    
    CCLog("sprite width = %f",backGround->getContentSize().width);
    
    CCLog("ContentScaleFactor = %f",_director->getContentScaleFactor());
    
    return true;
}


void HelloWorld::animationEvent(cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID){
    
    if (movementType == LOOP_COMPLETE){
        if (movementID == "walk"){
            //
            ActionInterval *actionToRight = MoveTo::create(2, Point(100 , 100));
            armature->stopAllActions();
            armature->runAction(actionToRight);
            armature->getAnimation()->play("stand");
        }else if(movementID == "stand"){
            //
            ActionInterval *actionToLeft = MoveTo::create(2, Point::ZERO);
            armature->stopAllActions();
            armature->runAction(actionToLeft);
            armature->getAnimation()->play("walk");
        }
        
    }
}


void HelloWorld::dataLoaded(float percent)
{
    
}
