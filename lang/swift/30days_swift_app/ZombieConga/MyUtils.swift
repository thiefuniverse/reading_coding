//
//  MyUtils.swift
//  ZombieConga
//
//  Created by 谢非 on 2017/11/11.
//  Copyright © 2017年 谢非. All rights reserved.
//

import Foundation
import CoreGraphics
import AVFoundation

func + (left: CGPoint, right: CGPoint) -> CGPoint {
    return CGPoint(x: left.x + right.x, y: left.y + right.y)
}

func += (left: inout CGPoint, right: CGPoint) {
    left = left + right
}

func - (left: CGPoint, right: CGPoint) -> CGPoint {
    return CGPoint(x: left.x - right.x, y: left.y - right.y)
}

func -= (left: inout CGPoint, right: CGPoint) {
    left = left - right
}

func * (left: CGPoint, right: CGPoint) -> CGPoint {
    return CGPoint(x: left.x * right.x, y: left.y * right.y)
}

func *= (left: inout CGPoint, right: CGPoint){
    left = left * right
}

func * (point: CGPoint, scalar: CGFloat) -> CGPoint {
    return CGPoint(x: point.x * scalar, y: point.y * scalar)
}

func *= (point: inout CGPoint, scalar: CGFloat) {
    point = point * scalar
}

func / (left: CGPoint, right: CGPoint) -> CGPoint {
    return CGPoint(x: left.x / right.x, y: left.y / right.y)
}

func /= (left: inout CGPoint, right: CGPoint) {
    left = left / right
}

func / (point: CGPoint, scalar: CGFloat) -> CGPoint {
    return CGPoint(x: point.x / scalar, y: point.y / scalar)
}

func /= (point: inout CGPoint, scalar: CGFloat) {
    point = point / scalar
}

#if !(arch(x86_64) || arch(arm64))
    func atan2(y: CGFloat, x: CGFloat) -> CGFloat {
        return CGFloat(atan2f(Float(y), Float(x)))
}
    func sqrt(a: CGFloat) -> CGFloat {
        return CGFloat(sqrtf(Float(a)))
    }
#endif

extension CGPoint {
    func length() -> CGFloat {
        return sqrt(x*x + y*y)
    }
    func normalized() -> CGPoint {
        return self / length()
    }
    var angle: CGFloat {
        return atan2(y, x)
    }
    
}
let mathPi = CGFloat.pi

func shortestAngleBetween(angle1: CGFloat, angle2: CGFloat) -> CGFloat {
    let twoPi = 2 * mathPi
    var angle = (angle2 - angle1).truncatingRemainder(dividingBy: twoPi)
    
    if angle >= mathPi {
        angle = angle - twoPi
    }
    if angle <= -mathPi {
        angle = angle + twoPi
    }
    return angle
}

extension CGFloat {
    func sign() -> CGFloat {
        return self >= 0.0 ? 1.0 : -1.0
    }
    
    
    static func random() -> CGFloat {
        return CGFloat(Float(arc4random()) / Float(UInt32.max))
    }
    
    static func random(min: CGFloat, max: CGFloat) -> CGFloat {
        assert(min < max)
        return CGFloat.random() * (max - min) + min
    }
}

var backgoundMusicPlayer: AVAudioPlayer!

func playBackgroundMusic(filename: String) {
    let resourceUrl = Bundle.main.url(forResource: filename, withExtension: nil)
    guard let url = resourceUrl else {
        print("Could not find file: \(filename)")
        return
    }
    
    do {
        try backgoundMusicPlayer = AVAudioPlayer(contentsOf: url)
        backgoundMusicPlayer.numberOfLoops = -1
        backgoundMusicPlayer.prepareToPlay()
        backgoundMusicPlayer.play()
    }catch {
        print("Could not create audio player!")
        return
    }
}

