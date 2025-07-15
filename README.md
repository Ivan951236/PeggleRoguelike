# PeggleRoguelike
This is a Peggle Roguelike Preset Generator made in C++ and for Android also in Kotlin
![The Layout for the roguelike!](https://raw.githubusercontent.com/Ivan951236/PeggleRoguelike/refs/heads/main/gallery/peggle_roguelike_layout.png)

# Compilation Instrucions

## Windows:
Install ![MSYS2](https://msys2.org)
Run MSYS2 UCRT64 Shell (Required!)
Update MSYS2 by using ``` pacman -Syu ```
Install all GTK's Requirements on MSYS2 and also ![GTK 3 Runtime (Install gtk3 not gtk2)](https://github.com/tschoonj/GTK-for-Windows-Runtime-Environment-Installer) for windows to run GTK 3 Applications
Prepare Build Directory ``` mkdir -p build && cd build ```
Prepare CMake ``` CMake .. -G "MSYS Makefiles" ```
Run the following command ``` make ```

## Windows (CLI):
Install ![MSYS2](https://msys2.org)
Run MSYS2 UCRT64 Shell (Required!)
Update MSYS2 by using ``` pacman -Syu ```
Install MSYS2 Buildtools for C++
Prepare Build Directory ``` mkdir -p build && cd build ```
Prepare CMake ``` CMake .. -G "MSYS Makefiles" ```
Run the following command ``` make ```

## Android:
Install ![Android Studio](https://developer.android.com/studio)
Launch Android Studio
Install the Lastest SDK and Buildtools
Use the provided gradle config files
Build the App by using the run (Release) button besides your device picker that will not only build but also run in either connected device or in virtual machine included within Android Studio
If you want, also make a .APK file and copy to device then install to device
