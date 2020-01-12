//
//  ViewController.swift
//  CarouselEffect5
//
//  Created by 谢非 on 2017/10/30.
//  Copyright © 2017年 谢非. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var backImageView: UIImageView!
    @IBOutlet weak var collectionView: UICollectionView!
    
    fileprivate var interests = Interest.createInterests()
    fileprivate struct Storyboard {
        static let CellIdentifier = "InterestCell"
    }
    
    
 
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}



extension ViewController: UICollectionViewDataSource {
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 1
    }
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return interests.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: Storyboard.CellIdentifier, for: indexPath) as! SlipViewCell
        cell.interest = self.interests[indexPath.item]
        return cell
    }
}
