//
//  ViewController.swift
//  PulltoRefresh7
//
//  Created by 谢非 on 2017/10/31.
//  Copyright © 2017年 谢非. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return emojiData.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: cellIdentifier, for: indexPath)
        cell.textLabel!.text = self.emojiData[indexPath.row]
        cell.textLabel!.textAlignment = NSTextAlignment.center
        cell.textLabel?.font = UIFont.systemFont(ofSize: 50)
        cell.backgroundColor = UIColor.clear
        cell.selectionStyle = UITableViewCellSelectionStyle.none
        return cell
    }
    
    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    let cellIdentifier = "NewCellIdentifier"
    let favoriteEmoji = ["😄😄😄😄😄","😇😇😇😇😇", "😋😋😋😋😋"]
    let newFavoriteEmoji = ["🤡🤡🤡🤡🤡","𒁽𒁽𒁽𒁽𒁽","💇‍♂️💇‍♂️💇‍♂️💇‍♂️💇‍♂️","😄😄😄😄😄","😇😇😇😇😇", "😋😋😋😋😋"]
    
    var emojiData = [String]()
    var tableViewController = UITableViewController(style: .plain)
    var refreshControl = UIRefreshControl()
    var navBar: UINavigationBar = UINavigationBar(frame: CGRect(x: 0, y: 0, width: 375, height: 64))
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        emojiData = favoriteEmoji
        
        let emojiTableView = tableViewController.tableView
        emojiTableView?.backgroundColor = UIColor(red: 0.092, green: 0.096, blue: 0.116, alpha: 1)
        emojiTableView?.dataSource = self
        emojiTableView?.register(UITableViewCell.self, forCellReuseIdentifier: cellIdentifier)
        
        tableViewController.refreshControl = self.refreshControl
        self.refreshControl.addTarget(self, action: #selector(self.didRoadEmoji), for: .valueChanged)
        
        self.refreshControl.backgroundColor = UIColor(red: 0.113, green: 0.113, blue: 0.145, alpha: 1)
        let attributes = [NSAttributedStringKey.foregroundColor: UIColor.white]
       self.refreshControl.attributedTitle = NSAttributedString(string: "Last updated on \(NSDate())", attributes: attributes)
        self.refreshControl.tintColor = UIColor.white
        
        self.title = "emoji"
        self.navBar.barStyle = UIBarStyle.blackTranslucent
        
        emojiTableView?.rowHeight = UITableViewAutomaticDimension
        emojiTableView?.estimatedRowHeight = 60.0
        emojiTableView?.tableFooterView = UIView(frame: CGRect.zero)
        emojiTableView?.separatorStyle = UITableViewCellSeparatorStyle.none
        
        self.view.addSubview(emojiTableView!)
        self.view.addSubview(navBar)
        
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    
    @objc func didRoadEmoji() {
        self.emojiData = newFavoriteEmoji
        self.tableViewController.tableView.reloadData()
        self.refreshControl.endRefreshing()
    }
}

