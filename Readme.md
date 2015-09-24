# Arduino Star Tracking Mount
### Overview
The star tracking mount is used to reduce the amount of star trails when taking photos of stars. The idea is to align the mount to polaris and rotate the mount at the same angular velocity as the earth's rotation.

### Materials
- Threaded rod (1/4" diameter)
- Furniture metal dowel (3/4" length)
- Wood dowel (1/2" diameter)
- Shaft coupler
- 1.8˚/Step stepper motor
- Plywood
- Tripod head
- Arduino Uno
- Motor shield
- Bluetooth shield

### Implementation
This project is still a work in progress but below are some photos of the implementation.

Overview of the motor assembly, with both dowels, to allow for rotation of the threaded rod.

<img src="https://github.com/nkanetka/Star-Tracking-Mount/blob/master/Images/thumb_IMG_0181_1024.jpg" width="450px" height="600px" />

Mount with camera set up ontop.

<img src="https://github.com/nkanetka/Star-Tracking-Mount/blob/master/Images/thumb_IMG_0197_1024.jpg" width="450px" height="600px" />

### To Do
1. Work on tweaking the correct speed of the motor.
2. Implement a control for the motor using the Bluetooth shield
    - Test using an LED or something first then scale up to the motor.
    - Test with an Android as Apple requires a MFi developer account.