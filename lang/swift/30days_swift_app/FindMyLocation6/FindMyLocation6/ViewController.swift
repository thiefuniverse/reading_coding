//
//  ViewController.swift
//  FindMyLocation6
//
//  Created by 谢非 on 2017/10/31.
//  Copyright © 2017年 谢非. All rights reserved.
//

import UIKit
import CoreLocation

class ViewController: UIViewController, CLLocationManagerDelegate {

    @IBOutlet weak var showLocation: UILabel!
    
    var locationManager: CLLocationManager!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    @IBOutlet weak var findMyLocationAct: UIButton!
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func findLocation(_ sender: Any) {
        locationManager = CLLocationManager()
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.requestAlwaysAuthorization()
        locationManager.startUpdatingLocation()
    }
    
    
    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
        self.showLocation.text = " Error " + error.localizedDescription
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        CLGeocoder().reverseGeocodeLocation(manager.location!, completionHandler: {(placemarks,error) -> Void in
            if (error != nil) {
                self.showLocation.text = "Reverse failed " + error!.localizedDescription
                print("Recerse" + error!.localizedDescription)
                return
        }
            
            if placemarks!.count > 0 {
                let pm = placemarks![0]
                self.displayLocation(pm)
            }
            else {
                self.showLocation.text = "Problem with geocoder"
            }
        } )
    }
    
    func displayLocation(_ placemark: CLPlacemark?) {
        if let containsPlacemark = placemark {
            locationManager.stopUpdatingLocation()
            
            let locality = (containsPlacemark.locality != nil) ? containsPlacemark.locality : ""
            let postalCode = (containsPlacemark.postalCode != nil) ? containsPlacemark.postalCode : ""
            let administrativeArea = (containsPlacemark.administrativeArea != nil) ? containsPlacemark.administrativeArea : ""
            let country = (containsPlacemark.country != nil) ? containsPlacemark.country : ""
            
            self.showLocation.text = postalCode! + " " + locality!
            
            self.showLocation.text?.append("\n" + administrativeArea! + ", " + country!)
        }
    }
}

