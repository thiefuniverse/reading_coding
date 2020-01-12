//
//  ViewController.swift
//  ImageScroller9
//
//  Created by 谢非 on 2017/11/1.
//  Copyright © 2017年 谢非. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UIScrollViewDelegate {

    var imageView: UIImageView!
    var scrollView: UIScrollView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        imageView = UIImageView(image: UIImage(named: "steve"))
        
        setUpScrollView()
        scrollView.delegate = self
        
        setZoomScaleFor(srollViewSize: scrollView.bounds.size)
        scrollView.zoomScale = scrollView.minimumZoomScale
        
        recentImage()
        
        // Do any additional setup after loading the view, typically from a nib.
    }
    override var preferredStatusBarStyle: UIStatusBarStyle{
        return .lightContent
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    
    override func viewWillLayoutSubviews() {
        super.viewWillLayoutSubviews()
        
        setZoomScaleFor(srollViewSize: scrollView.bounds.size)
        
        if scrollView.zoomScale < scrollView.minimumZoomScale {
            scrollView.zoomScale = scrollView.minimumZoomScale
        }
        recentImage()
    }
    private func setUpScrollView(){
        scrollView = UIScrollView(frame: view.bounds)
        scrollView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        scrollView.backgroundColor = UIColor.clear
        scrollView.contentSize = imageView.bounds.size
        
        scrollView.addSubview(imageView)
        view.addSubview(scrollView)
        
    }
    
    private func setZoomScaleFor(srollViewSize: CGSize){
        let imageSize = imageView.bounds.size
        let widthScale = srollViewSize.width / imageSize.width
        let heightScale = srollViewSize.height / imageSize.height
        let minimunScale = min(widthScale, heightScale)
        
        scrollView.minimumZoomScale = minimunScale
        scrollView.maximumZoomScale = 3.0
    }
    
    private func recentImage() {
        let scrollViewSize = scrollView.bounds.size
        let imageViewSize = imageView.frame.size
        let horizontalSpace = imageViewSize.width < scrollViewSize.width ? (scrollViewSize.width - imageViewSize.width) / 2.0 : 0
        let verticalSpace = imageViewSize.height < scrollViewSize.height ? (scrollViewSize.height - imageViewSize.height) / 2.0 : 0
        print("ho, ve : ", horizontalSpace, verticalSpace)
        scrollView.contentInset = UIEdgeInsetsMake(verticalSpace, horizontalSpace, verticalSpace, horizontalSpace)
    }
    func viewForZooming(in scrollView: UIScrollView) -> UIView? {
        return self.imageView
    }
    
    func scrollViewDidZoom(_ scrollView: UIScrollView) {
        self.recentImage()
    }
    
}

