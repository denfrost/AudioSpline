# AudioSpline
Audio Spline made in Unreal Engine 4.26. 

![](Documentation/Images/Image01.PNG)

### Description
It moves the location of the audio component to the closest point on the spline to the player location.

### Supported Engine Versions
4.26

### Supported Platforms
Win 32, Win 64, MacOS, Playstation 4 and Xbox one.

### How to install the Plugin 
After you download the repository, extract the zip archive. Your Project can be either a C++ Project or a Blueprint Project. 
Copy the folders "AudioSplinePlugin" into the "Plugins" folder of your UE4 project. 
If you don’t have a Plugins folder in your project folder yet, just create one.
![](Documentation/Images/Image09.PNG)
You will be able to see it in the Editor only if you toggle the "Show Plugin Content" on the "View Options".
![](Documentation/Images/Image08.PNG)

### How to use the Plugin
There are two ways of using this tool. You can simply use the C++ Actor or you can create a Blueprint class out of it.

#### Using the C++ Actor
Drag the AudioSpline Actor into the world and add as many spline points as you need.
To add a spline point drag one of the X,Y,Z arrows while holding alt key on your keyboard. Alternatevely you can add a spline point anywhere on the spline by right click on it. 
![](Documentation/Images/Gif01.gif)

Set your Sound Cue in the Details panel.   
![](Documentation/Images/Image05.PNG)

#### Using a Blueprint Class
This will allow you to add your unique blueprint logic to the Audio Spline.
Right click on the C++ Actor and select "Create Blueprint Class based on Audio Spline". 

![](Documentation/Images/Image04.PNG)

Choose a name and a directory for your Blueprint class.
![](Documentation/Images/Image07.PNG)

Set your Sound Cue in the Details panel. Then click Compile and Save.
![](Documentation/Images/Image06.PNG)

Drag the BP_AudioSpline Actor into the world and add as many spline points as you need. To add a spline point drag one of the X,Y,Z arrows while holding alt key on your keyboard. Alternatevely you can add a spline point anywhere on the spline by right click on it.
![](Documentation/Images/Gif03.gif)

### How it works
![](Documentation/Images/Image11.PNG)

You can change the Update Interval (Tick Interval) and the Range either on each instance of the actor or on the Blueprint class.

![](Documentation/Images/Image12.png)

### How to contact me
For any feedback please send me an email: 
luigiplatania94@gmail.com

My website: https://www.luigiplatania.net/
