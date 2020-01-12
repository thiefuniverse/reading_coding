//
//  ViewController.swift
//  StopWatch1
//
//  Created by 谢非 on 2017/10/25.
//  Copyright © 2017年 谢非. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var showSecond: UILabel!
    var counter: Float = 0.0
    var timer: Timer = Timer()
    var isPlaying: Bool = false
    
    @IBOutlet weak var stopButton: UIButton!
    @IBOutlet weak var startButton: UIButton!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    @IBAction func resetTimer(_ sender: Any) {
        timer.invalidate()
        counter = 0.0
        showSecond.text = String(format:"%0.1f", counter)
        
        startButton.isEnabled = true
        stopButton.isEnabled = true
    }
    
    @IBAction func stopTimer(_ sender: Any) {
        timer.invalidate()
        isPlaying = false
        startButton.isEnabled = true
        stopButton.isEnabled = false
    }
    @IBAction func startTimer(_ sender: Any) {
        if  isPlaying {
            return
        }
        timer = Timer.scheduledTimer(timeInterval: 0.1, target: self, selector: #selector(ViewController.updateTimer), userInfo: nil, repeats: true)
        startButton.isEnabled = false
        stopButton.isEnabled = true
    }
    
    
    @objc func updateTimer() {
        counter += 0.1
        showSecond.text = String(format:"%0.1f", counter)
    }

}

