# PeggleRoguelike
![The Layout for the roguelike!](https://raw.githubusercontent.com/Ivan951236/PeggleRoguelike/refs/heads/main/gallery/peggle_roguelike_layout.png)

# Compilation Instrucions

## Windows (and Linux's GUI):

NOTE: The GUI Version is now in Ivan951236/PeggleRoguelikeGUI repository!

Install ![Qt 5]([https://msys2.org](https://www.qt.io/download-qt-installer-oss))

If Present, then run Qt Creator

Select Project

Do Build Project

## Windows (CLI) (and Linux's CLI):

Install ![MSYS2](https://msys2.org) (not required for linux, as it is not for linux)

Run MSYS2 UCRT64 Shell (Required!) (on Linux, open your tty emulator (terminal) instead)

Update MSYS2 by using ``` pacman -Syu ``` (command's true for arch linux, might differ on other distro's)

Install MSYS2 Buildtools for C++ (linux buildtools on linux)

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

