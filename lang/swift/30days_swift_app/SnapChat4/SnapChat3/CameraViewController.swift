//
//  CameraViewController.swift
//  SnapChat3
//
//  Created by 谢非 on 2017/10/29.
//  Copyright © 2017年 谢非. All rights reserved.
//

import UIKit
import AVFoundation

class CameraViewController: UIViewController, UIImagePickerControllerDelegate,
UINavigationControllerDelegate,AVCapturePhotoCaptureDelegate{

    @IBOutlet weak var showImageView: UIImageView!
    @IBOutlet weak var showCamera: UIView!
    
    var captureSession: AVCaptureSession!
    var stillImageOutput: AVCapturePhotoOutput!
    var preivewLayer: AVCaptureVideoPreviewLayer?
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        UIApplication.shared.isStatusBarHidden = true
        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        preivewLayer?.frame = showCamera.bounds
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        captureSession = AVCaptureSession()
        stillImageOutput = AVCapturePhotoOutput()
        
        
        captureSession?.sessionPreset = AVCaptureSession.Preset.hd1920x1080
        let backCamera = AVCaptureDevice.default(for: AVMediaType.video)
        
        var error: NSError?
        var input: AVCaptureDeviceInput!
        do {
            input = try AVCaptureDeviceInput(device: backCamera!)
        }catch let error1 as NSError {
            error = error1
            input = nil
        }
        
        if (error == nil && captureSession?.canAddInput(input) != nil) {
            captureSession?.addInput(input)
            
          
       //     stillImageOutput?.outputSettings = [AVVideoCodecKey: AVVideoCodecJPEG]
            if (captureSession?.canAddOutput(stillImageOutput!) != nil){
                captureSession?.addOutput(stillImageOutput!)
                
                self.preivewLayer = AVCaptureVideoPreviewLayer(session: captureSession!)
                preivewLayer?.videoGravity = AVLayerVideoGravity.resizeAspect
                preivewLayer?.connection?.videoOrientation = AVCaptureVideoOrientation.landscapeLeft
                showCamera.layer.addSublayer(preivewLayer!)
                captureSession?.startRunning()
            }
        }
        
    }
    
    
    func  didPressTakePhoto() {
     //   if let videoConnection = stillImageOutput?.connection(with: AVMediaType.video) {
           let settings = AVCapturePhotoSettings()
        settings.flashMode = .off
        settings.isAutoStillImageStabilizationEnabled = true
        settings.isHighResolutionPhotoEnabled = false
//            let previewPixeltype = settings.availableEmbeddedThumbnailPhotoCodecTypes.first!
//            let previewFormat = [kCVPixelBufferPixelFormatTypeKey as String: previewPixeltype, kCVPixelBufferWidthKey as String: 160, kCVPixelBufferHeightKey as String: 160] as [String : Any]
//            settings.previewPhotoFormat = previewFormat
            self.stillImageOutput?.capturePhoto(with: settings, delegate: self as! AVCapturePhotoCaptureDelegate)
      //  }
    }
    
    
    var didTakePhoto = Bool()
    
    func didPressTakeAnother() {
        if didTakePhoto == true {
            print("did true ")
            showImageView.isHidden = true
            didTakePhoto = false
        }
        else {
            print("did false")
           // captureSession?.startRunning()
            didTakePhoto = true
            didPressTakePhoto()
        }
    }
    

    var counterTouched = 0
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        didPressTakeAnother()
        print("you touched", counterTouched)
        counterTouched = counterTouched + 1
    }

    func photoOutput(_ captureOutput: AVCapturePhotoOutput, didFinishProcessingPhoto photoSampleBuffer: CMSampleBuffer?, previewPhoto previewPhotoSampleBuffer: CMSampleBuffer?, resolvedSettings: AVCaptureResolvedPhotoSettings, bracketSettings: AVCaptureBracketedStillImageSettings?, error: Error?) {
        print("I am here")
        if let photoSampleBuffer = photoSampleBuffer {
            let photoData = AVCapturePhotoOutput.jpegPhotoDataRepresentation(forJPEGSampleBuffer: photoSampleBuffer, previewPhotoSampleBuffer: previewPhotoSampleBuffer)
            let image = UIImage(data: photoData!)
           // UIImageWriteToSavedPhotosAlbum(image!, nil, nil, nil)
            self.showImageView.image = image
            showImageView.isHidden = false
        }
    }
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
