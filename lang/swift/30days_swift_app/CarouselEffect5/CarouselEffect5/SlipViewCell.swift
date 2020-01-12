//
//  SlipViewCell.swift
//  CarouselEffect5
//
//  Created by 谢非 on 2017/10/30.
//  Copyright © 2017年 谢非. All rights reserved.
//

import UIKit

class SlipViewCell: UICollectionViewCell {
    var interest: Interest! {
    didSet {
        updateUI()
    }
    
    }
    
    @IBOutlet weak var mainImage: UIImageView!
    
    @IBOutlet weak var mainLabel: UILabel!
    
    fileprivate func updateUI () {
        mainImage.image = interest.featuredImage
        mainLabel.text = interest.title
    }
    override func layoutSubviews() {
        super.layoutSubviews()
        
        self.layer.cornerRadius = 5.0
        self.clipsToBounds = true
    }
    
}
