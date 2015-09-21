//
//  ViewController.m
//  Bluetooth
//
//  Created by Nehal Kanetkar on 2015-07-17.
//  Copyright (c) 2015 Vinay Kanetkar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ViewController.h"

@interface ViewController () <CBCentralManagerDelegate, CBPeripheralDelegate> {
    CBCentralManager *centralManager;
    CBPeripheral *holdingPeripheral;
    bool readyFlag;
}

@end

@implementation ViewController
- (IBAction)onOffToggleButton:(id)sender {
    if (readyFlag) {
        bool sendingValue = false;
        switch ([sender selectedSegmentIndex]) {
            case 0:
                NSLog(@"0 Selected");
                NSLog(@"Writing value as false %d", sendingValue);
                break;
            case 1:
                NSLog(@"1 Selected");
                sendingValue = true;
                NSLog(@"Writing value as true %d", sendingValue);
                
                break;
            default:
                NSLog(@"Nope");
                break;
        }
    } else {
        NSLog(@"Try Again");
    }
}

- (id) init {
    self = [super init];
    
    readyFlag = false;
    if (self) {
        centralManager = [[CBCentralManager alloc] initWithDelegate:self queue:nil options:nil];
    }
    
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [centralManager scanForPeripheralsWithServices:nil options:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)centralManager:(CBCentralManager *)central didDiscoverPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary *)advertisementData RSSI:(NSNumber *)RSSI {
    NSLog(@"Discovered %@", peripheral.name);
    [centralManager connectPeripheral:peripheral options:nil];
}

- (void)centralManager:(CBCentralManager *)central didConnectPeripheral:(CBPeripheral *)peripheral {
    NSLog(@"Peripheral connected");
    holdingPeripheral = peripheral;
    readyFlag = true;
}

- (void) centralManagerDidUpdateState:(CBCentralManager *)central {
    
}

@end
