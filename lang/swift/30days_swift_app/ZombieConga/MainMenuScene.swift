//
//  MainMenuScene.swift
//  ZombieConga
//
//  Created by 谢非 on 2017/11/15.
//  Copyright © 2017年 谢非. All rights reserved.
//

import Foundation
import SpriteKit

class MainMenuScene: SKScene {
    override func didMove(to view: SKView) {
        let mainMenu = SKSpriteNode(imageNamed: "MainMenu")
        mainMenu.position = CGPoint(x: size.width / 2, y: size.height / 2)
        mainMenu.anchorPoint = CGPoint(x: 0.5, y: 0.5)
        self.addChild(mainMenu)
    }
    
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        sceneTouched();
    }
    
    
    func sceneTouched() {
        let transition = SKTransition.doorway(withDuration: 1.5)
        let runScene = GameScene(size: CGSize(width: 2048, height: 1536))
        self.view?.presentScene(runScene, transition: transition)
    }
}
