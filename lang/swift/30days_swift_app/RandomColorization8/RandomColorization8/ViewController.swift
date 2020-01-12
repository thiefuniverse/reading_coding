//
//  ViewController.swift
//  RandomColorization8
//
//  Created by 谢非 on 2017/11/1.
//  Copyright © 2017年 谢非. All rights reserved.
//

import UIKit
import AVFoundation

class ViewController: UIViewController {

    var audioPlayer = AVAudioPlayer()
    let gradientLayer = CAGradientLayer()
    
    @IBAction func playMusic(_ sender: Any) {
        let bgMusic = URL(fileURLWithPath: Bundle.main.path(forResource: "Ecstasy", ofType: "mp3")!)
        
        do {
            try AVAudioSession.sharedInstance().setCategory(AVAudioSessionCategoryPlayback)
            try AVAudioSession.sharedInstance().setActive(true)
            try audioPlayer = AVAudioPlayer(contentsOf: bgMusic)
            
            audioPlayer.prepareToPlay()
            audioPlayer.play()
        }
        catch let audioError as Error {
            print(audioError)
        }
        if (timer == nil) {
            timer = Timer.scheduledTimer(timeInterval: 0.2, target: self, selector: #selector(self.randomColor), userInfo: nil, repeats: true)
        }
        
        let redValue = CGFloat(drand48())
        let blueValue =  CGFloat(drand48())
        let greenValue = CGFloat(drand48())
        
        self.view.backgroundColor = UIColor(red: redValue, green: greenValue, blue: blueValue, alpha: 1.0)
        
        //graditent color
        gradientLayer.frame = view.bounds
        let color1 = UIColor(white: 0.5, alpha: 0.2).cgColor as CGColor
        let color2 = UIColor(red: 1.0, green: 0, blue: 0, alpha: 0.4).cgColor as CGColor
        let color3 = UIColor(red: 0, green: 1, blue: 0, alpha: 0.3).cgColor as CGColor
        let color4 = UIColor(red: 0, green: 0, blue: 1, alpha: 0.3).cgColor as CGColor
        let color5 = UIColor(white: 0.4, alpha: 0.2).cgColor as CGColor
        
        gradientLayer.colors = [color1, color2, color3, color4, color5]
        gradientLayer.locations = [0.10, 0.30, 0.50, 0.70, 0.90]
        gradientLayer.startPoint = CGPoint(x: 0, y: 0)
        gradientLayer.endPoint = CGPoint(x: 1, y: 1)
        self.view.layer.addSublayer(gradientLayer)
    }
    var timer: Timer?
    override func viewDidLoad() {
        super.viewDidLoad()
        UIApplication.shared.isStatusBarHidden = true
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

 @objc   func randomColor() {
        
        let redValue = CGFloat(drand48())
        let blueValue =  CGFloat(drand48())
        let greenValue = CGFloat(drand48())
        
        
        self.view.backgroundColor = UIColor(red: redValue, green: greenValue, blue: blueValue, alpha: 1.0)
        
    }
}

