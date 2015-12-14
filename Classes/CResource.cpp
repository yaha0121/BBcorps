//
//  CResource.cpp
//  BBcorps
//
//  Created by apple on 15-11-24.
//
//

#include "CResource.h"

// singleton stuff
static CResourceData * s_SharedResourceData = NULL;

CResourceData * CResourceData::sharedResourceData(void)
{
    if (!s_SharedResourceData)
    {
        s_SharedResourceData = new CResourceData();
    }
    
    return s_SharedResourceData;
}

CResourceData::CResourceData()
{
    
}


CResourceData::~CResourceData()
{

}

const std::string & CResourceData::getArmatureResource()
{
    std::string res = cocos2d::FileUtils::sharedFileUtils()->fullPathForFilename("Armature") + "/";

    return res;
}

const std::string & CResourceData::getIphoneResource()
{
    std::string res = cocos2d::FileUtils::sharedFileUtils()->fullPathForFilename("iphone") + "/";
    
    return res;
}