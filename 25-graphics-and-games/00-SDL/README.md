# SDL2

## Installation in Ubuntu

```sh
sudo apt-get install libsdl2-2.0-0
sudo apt-get install libsdl2-dev

# install extensions
sudo apt-get install libsdl2-image-dev
sudo apt-get install libsdl2-ttf-dev
sudo apt-get install libsdl2-gfx-dev
```

## WSL 2 settings

If you are running application in WSL 2 then install Moba xterm for X11 protocol. They run below command in WSL terminal then launch your application. Make sure Moba Xterm is running.

```sh
export DISPLAY="$(/sbin/ip route | awk '/default/ { print $3 }'):0"
```

[Installing SDL - wiki.libsdl.org](https://wiki.libsdl.org/SDL2/Installation)

[Setting up SDL Extension Libraries on Linux - lazyfoo.net](https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/linux/index.php)

[Using WSL and MobaXterm to Create a Linux Dev Environment on Windows - nickjanetakis.com](https://nickjanetakis.com/blog/using-wsl-and-mobaxterm-to-create-a-linux-dev-environment-on-windows)
