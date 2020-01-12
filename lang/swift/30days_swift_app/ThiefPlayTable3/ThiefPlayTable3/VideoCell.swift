//
//  VideoCell.swift
//  ThiefPlayTable3
//
//  Created by 谢非 on 2017/10/28.
//  Copyright © 2017年 谢非. All rights reserved.
//

import UIKit
import AVKit

struct video {
    let image: String
    let title: String
    let source: String
}

class VideoCell: UITableViewCell {

    @IBOutlet weak var showSource: UILabel!
    @IBOutlet weak var showTitle: UILabel!
    @IBOutlet weak var showVideoImage: UIImageView!
    

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
