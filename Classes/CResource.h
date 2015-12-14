//
//  CResource.h
//  BBcorps
//
//  Created by apple on 15-11-24.
//
//

#ifndef __BBcorps__CResource__
#define __BBcorps__CResource__

#include <stdio.h>
class CResourceData : public cocos2d::Object
{
public:
    CResourceData();
    ~CResourceData();
    
    static CResourceData * sharedResourceData();
    
    const std::string & getArmatureResource();
    
    const std::string & getIphoneResource();
};
#endif /* defined(__BBcorps__CResource__) */
