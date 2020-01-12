//
//  ViewController.swift
//  ThiefPlayTable3
//
//  Created by 谢非 on 2017/10/28.
//  Copyright © 2017年 谢非. All rights reserved.
//

import UIKit
import AVKit

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    var playerController = AVPlayerViewController()
    var playerView = AVPlayer()
    
    
    var data = [
        
        video(image: "videoScreenshot01", title: "Introduce 3DS Mario", source: "Youtube - 06:32"),
        video(image: "videoScreenshot02", title: "Emoji Among Us", source: "Vimeo - 3:34"),
        video(image: "videoScreenshot03", title: "Seals Documentary", source: "Vine - 00:06"),
        video(image: "videoScreenshot04", title: "Adventure Time", source: "Youtube - 02:39"),
        video(image: "videoScreenshot05", title: "Facebook HQ", source: "Facebook - 10:20"),
        video(image: "videoScreenshot06", title: "Lijiang Lugu Lake", source: "Allen - 20:30")
        
    ]
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return data.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "VideoCell", for: indexPath) as! VideoCell
        
        let video = data[ indexPath.row]
        cell.showVideoImage?.image = UIImage(named: video.image)
        cell.showTitle.text = video.title
        cell.showSource.text = video.source
        return cell
        
    }
    

    @IBOutlet weak var showVIdeoTableView: UITableView!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        showVIdeoTableView.dataSource = self
        showVIdeoTableView.delegate = self
        
    }

    func numberOfSections(in tableView: UITableView) -> Int {
        return 2
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func playVideo(_ sender: Any) {
        
        let path = Bundle.main.path(forResource: "emoji zone", ofType: "mp4")
        playerView = AVPlayer(url: URL(fileURLWithPath: path!))
        playerController.player = playerView
        self.present(playerController, animated: true, completion: {
            self.playerController.player?.play()
        })
    }
    
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 130
    }
}

