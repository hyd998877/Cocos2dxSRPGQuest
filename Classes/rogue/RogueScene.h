//
//  RogueScene.h
//  Cocos2dxSRPGQuest
//
//  Created by kyokomi on 2014/01/02.
//
//

#ifndef __Cocos2dxSRPGQuest__RogueScene__
#define __Cocos2dxSRPGQuest__RogueScene__

#include "cocos2d.h"
#include "MapManager.h"

class RogueScene : public cocos2d::Layer
{
protected:
    
    enum GameStatus {
        INIT        = 0,
        PLAYER_TURN = 1,
        ENEMY_TURN  = 2,
        ENEMY_ACTION  = 3,
    };
    // TiledMap（background, colision)
        // TiledMapFront
        // TiledMapEnemy
    
    enum TiledMapTag {
        kTiledMapEnemyBaseTag = 1000, // + seqNo
        kTiledMapFrontTag     = 2000,
        kGridLineTag          = 10000,
    };
    
    enum TiledMapIndex {
        zTiledMapEnemyBaseIndex = 1000,
        zTiledMapFrontIndex     = 2000,
        zGridLineIndex          = 10000,
    };
    
    enum Tag {
        kTiledMapTag          = 1,
//        kCursorBaseTag      = 9000,
//        kCursorMoveFindTag  = 9001,
//        kCursorMoveStepTag  = 9002,
//        kCursorSelectedTag  = 9003,
//        kGridLineTag          = 10000,
        kActorBaseTag         = 100000,
        kMiniMapTag           = 150000,
        kStatusBarTag         = 200000,
        kGameLogTag           = 210000,
    };
    enum Index {
        zTiledMapIndex   = 1,
//        zCursorBaseIndex     = 9000,
//        zCursorMoveFindIndex = 9001,
//        zCursorMoveStepIndex = 9002,
//        zCursorSelectedIndex = 9003,
//        zGridLineIndex   = 10000,
        zActorBaseIndex  = 100000,
        zMiniMapIndex    = 150000,
        zStatusBarIndex  = 200000,
        zGameLogIndex    = 210000,
    };

private:
    // ゲームステート管理
    GameStatus m_gameStatus;
    void changeGameStatus(GameStatus gameStatus);
    void enemyTurn();
    
    // マップベース情報
    cocos2d::Size m_baseContentSize;
    cocos2d::Size m_baseMapSize;
    cocos2d::Size m_baseTileSize;

    // マップ制御
    MapManager m_mapManager;
    
    // タッチイベント系
    void touchEventExec(cocos2d::Point touchPoint);
    void touchEventExec(MapIndex touchPointMapIndex);
    MapIndex checkTouchEventIndex(MapIndex touchPointMapIndex);
    void moveMap(MapIndex addMoveIndex, int actorSeqNo, MapDataType mapDataType, cocos2d::CallFunc* moveFinishedCallFunc);
    bool isTiledMapColisionLayer(MapIndex touchPointMapIndex);
    
    // UI関連
    void logMessage(const char * pszFormat, ...);
    
    // マップ座標変換
    cocos2d::Point indexToPoint(int mapIndex_x, int mapIndex_y);
    cocos2d::Point indexToPoint(MapIndex mapIndex);
    cocos2d::Point indexToPointNotTileSize(int mapIndex_x, int mapIndex_y);
    cocos2d::Point indexToPointNotTileSize(MapIndex mapIndex);
    
    MapIndex pointToIndex(cocos2d::Point point);
    MapIndex touchPointToIndex(cocos2d::Point point);
    // MapIndexからtileIndexに変換
    MapIndex mapIndexToTileIndex(MapIndex mapIndex);
    
public:
    RogueScene();
    ~RogueScene();
    
    virtual bool init();
    
    static cocos2d::Scene* scene();
    
    CREATE_FUNC(RogueScene);
    
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
    virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event);
};

#endif /* defined(__Cocos2dxSRPGQuest__RogueScene__) */
