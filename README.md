# AudioSpline
Audio Spline made in Unreal Engine 4.26. 

![](Documentation/Images/Image01.PNG)

### Description
It moves the location of the audio component to the closest point on the spline to the player location.

### Supported Engine Versions
4.26

### Supported Platforms
Windows 32-bit, Windows 64-bit, MacOS, Playstation 4 and Xbox one.

### How to install the Plugin 
After you download the repository, extract the zip archive. Copy the folders "AudioSplinePlugin" into the "Plugins" folder of your UE4 project. 
If you don’t have a Plugins folder in your project folder yet, just create one.
You will be able to see it in the Editor only if you toggle the "Show Plugin Content" on the "View Options".
![](Documentation/Images/Image02.PNG)

### How to use the Plugin
There are two ways of using this tool. You can simply use the C++ Actor or you can create a Blueprint class out of it.

#### Using the C++ Actor
Drag the AudioSpline Actor into the world and add as many spline points as you need.
To add a spline point drag one of the X,Y,Z arrows while holding alt key on your keyboard. Alternatevely you can add a spline point anywhere on the spline by right click on it. 
![](Documentation/Images/Gif01.gif)

Set your Sound Cue in the Details panel.   
![](Documentation/Images/Image05.PNG)

#### Using a Blueprint Class
Create a blueprint class and do the same step above. This will allow you to add your unique blueprint logic to the Audio Spline.
![](Documentation/Images/Image04.PNG)

### How to contact me
For any feedback please send me an email: 
luigiplatania94@gmail.com

My website: https://www.luigiplatania.net/
