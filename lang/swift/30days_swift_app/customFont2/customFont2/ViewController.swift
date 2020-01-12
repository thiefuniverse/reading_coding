//
//  ViewController.swift
//  customFont2
//
//  Created by 谢非 on 2017/10/25.
//  Copyright © 2017年 谢非. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource{

    var data: [String] = ["30 Days Swift", "这些字体特别适合打「奋斗」和「理想」", "谢谢「造字工房」，本案例不涉及商业使用", "使用到造字工房劲黑体，致黑体，童心体", "呵呵，再见🤗 See you next Project", "微博 @Allen朝辉",
                          "测试测试测试测试测试测试",
                          "123",
                          "Alex",
                          "@@@@@@"]
    var fonts: [String] = ["MFJinHei_Noncommercial-Regular", "1", "MFTongXin_Noncommercial-Regular", "MFZhiHei_Noncommercial-Regular", "Gaspar Regular"]
    
    @IBOutlet weak var fontTableView: UITableView!
    @IBOutlet weak var changeFont: UIButton!
    var fontRowIndex = 0
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        fontTableView.dataSource = self
        fontTableView.delegate = self
        
        
        for family in UIFont.familyNames {
            for font in UIFont.fontNames(forFamilyName: family){
                print(font)
                }
            
            }
        
        changeFont.layer.cornerRadius = 55
        // Do any additional setup after loading the view, typically from a nib.
    }

    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 35
    }
    
    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = fontTableView.dequeueReusableCell(withIdentifier: "fontCell", for: indexPath)
        let text = data[indexPath.row]
        
        cell.textLabel?.text = text
        cell.textLabel?.textColor = UIColor.white
        cell.textLabel?.font = UIFont(name: self.fonts[fontRowIndex], size: 16)
        
        print("thief: ",cell.textLabel?.font)
        print("fonts: ", self.fonts[fontRowIndex])
        return cell
    }
    
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return data.count
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func changeFontAction(_ sender: Any) {
        fontRowIndex = (fontRowIndex+1)  % 5
        print(fonts[fontRowIndex])
        fontTableView.reloadData()
    }
    
}

