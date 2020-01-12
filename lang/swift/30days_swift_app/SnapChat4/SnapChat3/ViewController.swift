//
//  ViewController.swift
//  SnapChat3
//
//  Created by 谢非 on 2017/10/29.
//  Copyright © 2017年 谢非. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        UIApplication.shared.isStatusBarHidden = true
        let leftView: LeftViewController = LeftViewController(nibName: "LeftViewController", bundle: nil)
        let rightView: RightViewController = RightViewController(nibName: "RightViewController", bundle: nil)
        
        let centerView: CameraViewController =  CameraViewController(nibName: "CameraViewController", bundle: nil)
        
        self.addChildViewController(leftView)
        self.showScrollView.addSubview(leftView.view)
        leftView.didMove(toParentViewController: self)
        
        self.addChildViewController(rightView)
        self.showScrollView.addSubview(rightView.view)
        rightView.didMove(toParentViewController: self)
        
        self.addChildViewController(centerView)
        self.showScrollView.addSubview(centerView.view)
        centerView.didMove(toParentViewController: self)
        
        var centerViewFrame: CGRect = centerView.view.frame
        centerViewFrame.origin.x = self.view.frame.width
        centerView.view.frame = centerViewFrame
        
        var rightViewFrame: CGRect = rightView.view.frame
        rightViewFrame.origin.x =  2 * self.view.frame.width
        rightView.view.frame = rightViewFrame
        
        
        self.showScrollView.contentSize = CGSize(width: self.view.frame.width * 3, height: self.view.frame.height)
        
    }
    @IBOutlet weak var showScrollView: UIScrollView!
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    
}

