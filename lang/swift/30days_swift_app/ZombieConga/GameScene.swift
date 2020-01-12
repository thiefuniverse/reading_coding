//
//  GameScene.swift
//  ZombieConga
//
//  Created by 谢非 on 2017/11/8.
//  Copyright © 2017年 谢非. All rights reserved.
//

import SpriteKit
import GameplayKit

class GameScene: SKScene {
    
    var zombie1 = SKSpriteNode()
    var lastUpdateTime: TimeInterval = 0
    var dt: TimeInterval = 0
    let zombibeMovePointsPerSec: CGFloat = 480.0
    let catMovePointsPerSec: CGFloat = 480.0
    var velocity = CGPoint.zero
    var lastTouchLocation: CGPoint = CGPoint()
    
    let cameraNode = SKCameraNode()
    var lives = 5
    var gameOver = false
    var trainCounter = 0
    
    
    var isSage = false
    let playableRect: CGRect
    var zombieRotateRadiansPerSec: CGFloat = mathPi * 4
    let miniNum: CGFloat = 0.001
    var zombieDestRotate: CGFloat = 0
    
    let livesLabel = SKLabelNode(fontNamed: "Chalkduster")
    let catsCount = SKLabelNode(fontNamed: "Chalkduster")
    var cameraRect: CGRect {
        let x = cameraNode.position.x - size.width / 2 + (size.width - playableRect.width) / 2
        let y = cameraNode.position.y - size.height / 2 + (size.height - playableRect.height ) / 2
        return CGRect(x: x, y: y, width: playableRect.width, height: playableRect.height)
    }
    var zombieIsHidden: Bool = false
    
    let zombieAnimation: SKAction
    let catCollisionSound: SKAction = SKAction.playSoundFileNamed("hitCat.wav", waitForCompletion: false)
    let enemyCollisionSound: SKAction = SKAction.playSoundFileNamed("hitCatLady.wav", waitForCompletion: false)
    
    override init(size: CGSize) {
        let maxAspectRatio: CGFloat = 16.0 / 9.0
        let playableHeight = size.width / maxAspectRatio
        let playableMargin = (size.height - playableHeight) / 2.0
        playableRect = CGRect(x: 0, y: playableMargin, width: size.width, height: playableHeight)
        
        var textures:[SKTexture] = []
        for i in 1...4 {
            textures.append(SKTexture(imageNamed: "zombie\(i)"))
        }
        textures.append(textures[2])
        textures.append(textures[1])
        
        zombieAnimation = SKAction.animate(with: textures, timePerFrame: 0.1)
        super.init(size: size)
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError(" init(coder: ) has not been implemented")
    }
    
    override func didMove(to view: SKView) {
        
        playBackgroundMusic(filename: "backgroundMusic.mp3")
        backgroundColor = SKColor.black

      //  let background = SKSpriteNode(imageNamed: "background1")
        for i in 0...1{
            let background = backgroundNode()
            background.anchorPoint = CGPoint.zero

            background.position = CGPoint(x: CGFloat(i) * background.size.width, y: 0)
            background.name = "background"
            background.zPosition = -1000
            self.addChild(background)
        }
        
        livesLabel.text = "Lives: \(lives)"
        livesLabel.fontColor = SKColor.black
        livesLabel.fontSize = 100
        livesLabel.zPosition = 150
        livesLabel.horizontalAlignmentMode = .left
        livesLabel.verticalAlignmentMode = .bottom
        livesLabel.position = CGPoint(x: cameraRect.origin.x + CGFloat(20), y: cameraRect.origin.y + CGFloat(20))
        
        addChild(livesLabel)
        

        catsCount.text = "Cats: \(trainCounter)"
        catsCount.fontColor = SKColor.black
        catsCount.fontSize = 100
        catsCount.zPosition = 150
        catsCount.horizontalAlignmentMode = .left
        catsCount.verticalAlignmentMode = .bottom
        catsCount.position = CGPoint(x: cameraRect.maxX - CGFloat(50), y: cameraRect.minY + CGFloat(20))
        addChild(catsCount)
        
        //background.position = CGPoint(x: size.width / 2, y: size.height / 2)
     
        
        
        //background.zRotation = CGFloat(M_PI) / 8
      //  let mySize = background.size
        //print("Size : \(mySize)")
        
        zombie1 = SKSpriteNode(imageNamed: "zombie1")
        zombie1.position = CGPoint(x: 400, y: 400)
        zombie1.zPosition  = 100
      //  zombie1.setScale(2)
        self.addChild(zombie1)
        
        addChild(cameraNode)
       // cameraNode.position = CGPoint(x: 0, y: 0)
        print("camera position: ",camera?.position)
//        cameraNode.position = back
        camera = cameraNode
        cameraNode.position = CGPoint(x: size.width/2, y: size.height/2)
//        cameraNode.position = CGPoint(x: size.width/2, y: size.height/2)
      //  cameraNode.position = zombie1.position
//        zombie1.run(SKAction.repeatForever(zombieAnimation))
        run(SKAction.repeatForever(SKAction.sequence([SKAction.run() {
            [weak  self] in self?.spawnEnemy()
            },
            SKAction.wait(forDuration: 2.0)])))
        
        run(SKAction.repeatForever(SKAction.sequence([SKAction.run {
                [weak self] in
            self?.spawnCat()
            },
            SKAction.wait(forDuration: 1.0)])))
    
        
    }
    
    func backgroundNode() -> SKSpriteNode {
        let backgroundNode = SKSpriteNode()
        backgroundNode.anchorPoint = CGPoint.zero
        backgroundNode.name = "background"
        
        let background1 = SKSpriteNode(imageNamed: "background1")
        background1.anchorPoint = CGPoint.zero
        background1.position = CGPoint(x: 0, y: 0)
        backgroundNode.addChild(background1)
        
        let background2 = SKSpriteNode(imageNamed: "background2")
        background2.anchorPoint = CGPoint.zero
        background2.position = CGPoint(x: background1.size.width, y: 0)
        backgroundNode.addChild(background2)
        
        backgroundNode.size = CGSize(width: background1.size.width + background2.size.width, height: background1.size.height)
        return backgroundNode
    }
    func loseCats() {
        var loseCount = 0
        
        enumerateChildNodes(withName: "train") {
            node, stop in
            var randomSpot = node.position
            randomSpot.x += CGFloat.random(min: -100, max: 100)
            randomSpot.y += CGFloat.random(min: -100, max: 100)
            
            node.name = ""
            node.run(SKAction.sequence([
                            SKAction.group([SKAction.rotate(byAngle: mathPi * 4, duration: 1.0),
                            SKAction.move(to: randomSpot, duration: 1.0),
                            SKAction.scale(to: 0, duration: 1.0)]),
                            SKAction.removeFromParent()]))
            loseCount += 1
            if loseCount >= 2 {
                stop[0] = true
            }
        }
                trainCounter -= 2
        if trainCounter < 0 {
            trainCounter = 0
        }
    }
    let cameraMovePointPerSec: CGFloat = 200.0
    func moveCamera() {
        let backgroundVelocity = CGPoint(x: cameraMovePointPerSec, y: 0)
        let amountToMove = backgroundVelocity * CGFloat(dt)
        cameraNode.position += amountToMove
        
        enumerateChildNodes(withName: "background") {
            node, _ in
            let background = node as! SKSpriteNode
            if background.position.x + background.size.width < self.cameraRect.origin.x + self.size.width  {
                background.position = CGPoint(x: background.position.x + background.size.width, y: background.position.y)
           }
        }
    }
    func moveTrain() {
        var targetPosition = zombie1.position
        enumerateChildNodes(withName: "train") {
            node , stop in
            if !node.hasActions() {
                let actionDuration = 0.3
                let offset = targetPosition - node.position
                let direction = offset.normalized()
                let amountToMovePerSec = direction * self.catMovePointsPerSec
                let amountToMove = amountToMovePerSec * CGFloat(actionDuration)
                let moveAction = SKAction.moveBy(x: amountToMove.x, y: amountToMove.y, duration: actionDuration)
                node.run(moveAction)
            }
            targetPosition = node.position
        }

    }
    override func update(_ currentTime: TimeInterval) {
        if lastUpdateTime > 0 {
            dt = currentTime - lastUpdateTime
        }else {
            dt = 0
        }
        lastUpdateTime = currentTime
        print("\(zombie1.position) position")
        
        //zombie1.position = CGPoint(x: zombie1.position.x + 8, y: zombie1.position.y)
        move(sprite: zombie1, velocity: velocity)
        moveCamera()
//        if zombie1.position.x >= size.width * 1.5 {
//            cameraNode.position = CGPoint(x: size.width * 1.5, y: size.height / 2)
//        }
//        else if zombie1.position.x <= size.width / 2{
//            cameraNode.position = CGPoint(x: size.width / 2, y: size.height / 2)
//        }
//        else {
//            cameraNode.position = CGPoint(x: zombie1.position.x, y: size.height / 2)
//        }
        rotate(sprite: zombie1, direction: velocity,rotateRadiansPerSec: &zombieRotateRadiansPerSec)
        boundsCheckZombie()
       checkCollisions()
        if lives <= 0 && !gameOver {
            gameOver = true
            print("you lose!")
            let gameOverScene = GameOverScene(size: size,won: false)
            gameOverScene.scaleMode = scaleMode
            let reveal = SKTransition.flipHorizontal(withDuration: 0.5)
            backgoundMusicPlayer.stop()
            view?.presentScene(gameOverScene, transition: reveal)
        }
        if trainCounter >= 15 && !gameOver {
            gameOver = true
            print("you win!")
            
            let gameOverScene = GameOverScene(size: size, won: true)
            gameOverScene.scaleMode = scaleMode
            let reveal = SKTransition.flipHorizontal(withDuration: 0.5)
            backgoundMusicPlayer.stop()
            view?.presentScene(gameOverScene, transition: reveal)
        }
        
        moveTrain()
        catsCount.text = "Cats: \(trainCounter)"
        livesLabel.text = "Lives: \(lives)"
        livesLabel.position = CGPoint(x: cameraRect.origin.x + CGFloat(20), y: cameraRect.origin.y )
        catsCount.position = CGPoint(x: cameraRect.origin.x + cameraRect.width - 500 , y: livesLabel.position.y)
    }
    
    override func didEvaluateActions() {
      
    }
    
    func move(sprite: SKSpriteNode, velocity: CGPoint) {

           // stopZombieAnimation()
        var amountToMove = velocity * CGFloat(dt)
        
        let touchDis = lastTouchLocation - zombie1.position
//        if touchDis.length() < amountToMove.length() {
//            self.velocity = CGPoint(x: 0, y: 0)
//            amountToMove = CGPoint(x: 0, y: 0)
//            stopZombieAnimation()
//        }
        print("Amount to move:  \(amountToMove)" )
        sprite.position = sprite.position + amountToMove
    }
    
    
    func rotate(sprite: SKSpriteNode, direction: CGPoint, rotateRadiansPerSec: inout CGFloat){
       
        let shortest = shortestAngleBetween(angle1: sprite.zRotation, angle2: velocity.angle)
        let amountToRotate = min(rotateRadiansPerSec * CGFloat(dt), abs(shortest))
        if (velocity.length() != 0){
            sprite.zRotation += shortest.sign() * amountToRotate
        }
     
//        let szRotation = (sprite.zPosition  == 0 ? 0 : sprite.zRotation.truncatingRemainder(dividingBy: 2 * mathPi ) );
//        if ((szRotation - zombieDestRotate) * ( szRotation + rotateRadiansPerSec - zombieDestRotate) < 0) {
//             sprite.zRotation = zombieDestRotate
//            rotateRadiansPerSec = 0
//        }
//        else {
//             sprite.zRotation += rotateRadiansPerSec
//        }
//
        print("sprite Z rotation: ",sprite.zRotation, " velocity angle", velocity.angle)
        
    }
    func moveZombieToward(location: CGPoint){
        let offset = location - zombie1.position
        let direction = offset.normalized()
        print("direction: \(direction)")
        velocity = direction * zombibeMovePointsPerSec
        print("velocity :  \(velocity)")
        startZombieAnimation()
        
    }
    
    func sceneTouched(touchLocation: CGPoint) {
        moveZombieToward(location: touchLocation)
      //  rotateZombieToward(location: touchLocation, sprite: zombie1)
    }
    
    
    func startZombieAnimation() {
        if zombie1.action(forKey: "animation") == nil {
            zombie1.run(SKAction.repeatForever(zombieAnimation), withKey: "animation")
        }
    }
    
    func stopZombieAnimation() {
        zombie1.removeAction(forKey: "animation")
    }
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let touch = touches.first else {
            return
        }
       
        let touchLocation = touch.location(in: self)
        if lastTouchLocation != touchLocation {
            lastTouchLocation = touchLocation
        }
        sceneTouched(touchLocation: touchLocation)
    }
    
    func spawnEnemy() {
        let enemy = SKSpriteNode(imageNamed: "enemy")
        enemy.name = "enemy"
        enemy.position = CGPoint(x: cameraRect.maxX + enemy.size.width / 2, y:
            CGFloat.random(min: cameraRect.minY + enemy.size.height / 2, max: cameraRect.maxY - enemy.size.height / 2))
        self.addChild(enemy)
        
//        let actionMove = SKAction.move(to: CGPoint(x: -enemy.size.width / 2, y: enemy.position.y), duration: 2.0)
//        enemy.run(actionMove)
//        let actionMidMove = SKAction.move(to: CGPoint(x: size.width / 2, y: playableRect.minY + enemy.size.height / 2), duration: 1.0)
//        let actionMove = SKAction.move(to: CGPoint(x: -enemy.size.width / 2, y: enemy.position.y), duration: 1.0)
        let actionMidMove = SKAction.moveBy(x: -size.width / 2 - enemy.size.width / 2, y: -playableRect.size.height / 2 + enemy.size.height / 2, duration: 1.0)
        
        let actionMove = SKAction.moveBy(x: -size.width / 2 - enemy.size.width / 2, y: playableRect.height / 2 - enemy.size.height / 2, duration: 1.0)
        let waitMove = SKAction.wait(forDuration: 0.25)
        
        let logMessage = SKAction.run() {
            print(" Reached Bottom")
        }
        
//        let reverseMid = actionMidMove.reversed()
//        let reverseMove = actionMove.reversed()
//
        let removeAction = SKAction.removeFromParent()
        let halfSequence = SKAction.sequence([actionMidMove,logMessage,waitMove, actionMove])
        let sequence = SKAction.sequence([halfSequence, halfSequence.reversed(), removeAction])
        //let repeatAction = SKAction.repeatForever(sequence)
        
        enemy.run(sequence)
    }
    
    override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let touch = touches.first else {
            return
        }
        let touchLocation = touch.location(in: self)
        sceneTouched(touchLocation: touchLocation)
    }
    
    func spawnCat() {
        let cat = SKSpriteNode(imageNamed: "cat")
        cat.name = "cat"
        cat.position = CGPoint(x: CGFloat.random(min: cameraRect.minX, max: cameraRect.maxX), y: CGFloat.random(min: cameraRect.minY, max: cameraRect.maxY))
        
        cat .setScale(0)
        addChild(cat)
        
        let appear = SKAction.scale(to: 1.0, duration: 0.5)
        let wait = SKAction.wait(forDuration: 10.0)
        let disappear = SKAction.scale(to: 0, duration: 0.5)
        let removeFromParent = SKAction.removeFromParent()
        
        cat.zPosition = -mathPi / 16.0
        let leftWiggle = SKAction.rotate(byAngle: mathPi / 8.0, duration: 0.5)
        let rightWiggle = leftWiggle.reversed()
        let fullWiggle = SKAction.sequence([leftWiggle, rightWiggle])
        let wiggleWait = SKAction.repeat(fullWiggle, count: 10)
        let scaleUp = SKAction.scale(to: 1.2, duration: 0.25)
        let scaleDown = SKAction.scale(to: 1.0, duration: 0.25)
        
        let fullScale = SKAction.sequence([scaleUp, scaleDown, scaleUp, scaleDown])
        let groupWait = SKAction.repeat(SKAction.group([fullWiggle, fullScale]), count: 10)
        let actions = [ appear, groupWait, disappear, removeFromParent]
        cat.run(SKAction.sequence(actions))
    }
    
    
    
    func zombieHit(cat: SKSpriteNode){
        if isSage {
            return
        }
        trainCounter += 1
        cat.name = "train"
        cat.removeAllActions()
        cat.setScale(1)
        cat.zRotation = 0
        cat.run(SKAction.colorize(with: UIColor.green, colorBlendFactor: 1, duration: 0.2))
       // cat.removeFromParent()
        self.run(catCollisionSound)
    }
    
    
    func zombieHit(enemy: SKSpriteNode){
       // zombieIsHidden = true
        if isSage {
            return
        }
        let blinkTImes = 6.0
        let duration = 2.0
        
        zombie1.run(SKAction.sequence(
            [SKAction.repeat(SKAction.customAction(withDuration: duration) { node, elapsedTime in
            let slice = duration / blinkTImes
            let remainder = Double(elapsedTime).truncatingRemainder(dividingBy: slice)
            node.isHidden = remainder > slice / 2
            self.isSage = true
            print("isSage internal 1")
        }, count: 3),
             SKAction.run {
                self.isSage = false
                }]) )
        print("isSage internal 2")
        
        zombie1.isHidden = false
        zombieIsHidden = false
        self.run(enemyCollisionSound)
        loseCats()
        lives -= 1
    }
    
    func checkCollisions() {
        var hitCats: [SKSpriteNode] = []
        print("check Collision")
            enumerateChildNodes(withName: "cat") {
                node, _ in
                let cat  = node as! SKSpriteNode
                if cat.frame.intersects(self.zombie1.frame) {
                    hitCats.append(cat)
                }
            }
            for cat in hitCats {
                zombieHit(cat: cat)
            }
        if zombieIsHidden {
            return
        }
 
            var hitEnemies: [SKSpriteNode] = []
            enumerateChildNodes(withName:  "enemy") {
                node, _ in
                let enemy = node as! SKSpriteNode
                if node.frame.insetBy(dx: 20, dy: 20).intersects(self.zombie1.frame) {
                    hitEnemies.append(enemy)
                    print("done collision 1")
                    return
                }
            }
            for enemy in hitEnemies {
                self.zombieHit(enemy: enemy)
            }
        
       print("done collision 2")
    }
    func boundsCheckZombie() {
        let bottomLeft = CGPoint(x: cameraRect.minX, y: cameraRect.minY)
        let topRight = CGPoint(x: cameraRect.maxX, y:cameraRect.maxY)
        
        if zombie1.position.x < bottomLeft.x {
            zombie1.position.x = bottomLeft.x
            velocity.x = abs(velocity.x)
        }
        if zombie1.position.y < bottomLeft.y {
            zombie1.position.y = bottomLeft.y
            velocity.y = -velocity.y
        }
        if zombie1.position.x > topRight.x {
            zombie1.position.x = topRight.x
            velocity.x = -velocity.x
        }
        if zombie1.position.y > topRight.y {
            zombie1.position.y = topRight.y
            velocity.y = -velocity.y
        }

    }
}
